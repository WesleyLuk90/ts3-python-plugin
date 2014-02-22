import paths
from CCodeWriter import CCodeWriter

VARIABLE_INPUT_TYPE_STRING = {
	"unsigned int": 'i',
	"int": 'i',
	"size_t": 'l',
	"uint64": 'L',
	"const int*": 'O',
	"const char*": 's',
	"const char**": 'O',
	"const unsigned int*": 'O',
	"const short*": 'O',
	"const TS3_VECTOR*": '(fff)',
	"const uint64*": 'O',
	"const anyID*": 'O',
	"enum LogLevel": 'i',
	"enum PluginMessageTarget": 'i',
	"enum PluginItemType": 'i',
	"enum PluginGuiProfile": 'i',
	"enum PluginConnectTab": 'i',
	"anyID": 'h',
	"float": 'f',
}

VARIABLE_OUTPUT_TYPE_STRING = {
	# output types, O means we should specially handle it
	"int*": 'i',
	"char*": 's',
	"size_t*": 'l',
	"short*": 'j',
	"unsigned int*": 'i',
	"unsigned short*": 'j',
	"float*": 'f',
	"double*": 'd',
	"char**": 's', # pointer to string
	"char***": 'O', # array of pointers to strings
	"char****": 'O',
	"uint64*": 'L',
	"uint64**": 'O',
	"void*": 'O',
	"anyID*": 'h',
	"anyID**": 'O',
	"struct PluginBookmarkList**": 'O',
}

# Whether the variable is an output variable or input
VARIABLE_IN_OUT = {
	"unsigned int": 'in',
	"int": 'in',
	"size_t": 'in',
	"uint64": 'in',
	"const int*": 'in',
	"const char*": 'in',
	"const char**": 'in',
	"const unsigned int*": 'in',
	"const short*": 'in',
	"const TS3_VECTOR*": 'in',
	"const uint64*": 'in',
	"const anyID*": 'in',
	"enum LogLevel": 'in',
	"enum PluginMessageTarget": 'in',
	"enum PluginItemType": 'in',
	"enum PluginGuiProfile": 'in',
	"enum PluginConnectTab": 'in',
	"anyID": 'in',
	"float": 'in',

	"int*": 'out',
	"char*": 'out',
	"size_t*": 'out',
	"short*": 'out',
	"unsigned int*": 'out',
	"unsigned short*": 'out',
	"float*": 'out',
	"double*": 'out',
	"char**": 'out',
	"char***": 'out',
	"char****": 'out',
	"uint64*": 'out',
	"uint64**": 'out',
	"void*": 'out',
	"anyID*": 'out',
	"anyID**": 'out',
	"struct PluginBookmarkList**": 'out',
	
}

IGNORED_FUNCTIONS = {
	"freeMemory": True,
	"requestHotkeyInputDialog": True,
	"getBookmarkList": True,
	"getHotkeyFromKeyword": True,
}

class DefaultParameterHandler:
	def __init__(self, function, parameter):
		self.function = function
		self.parameter = parameter

	@property
	def name(self):
		return self.parameter.name

	@property
	def type(self):
		return self.parameter.type_def

	def _get_parameter_in_out(self):
		return VARIABLE_IN_OUT[self.type]

	def _is_input(self):
		return self._get_parameter_in_out() == "in"

	def _is_output(self):
		return self._get_parameter_in_out() == "out"

	def _get_output_type_string(self):
		return VARIABLE_OUTPUT_TYPE_STRING[self.type]

	def _requires_clean_up(self):
		return self.type.find("**") > -1

	def variable_declaration(self, w):
		if self._is_input():
			w.write_line("%s %s;" % (self.type, self.name))

	def parse_string(self):
		if self._is_input():
			return VARIABLE_INPUT_TYPE_STRING[self.type]
		else:
			return ""

	def parse_variable(self):
		if self._is_input():
			return "&" + self.name

	def python_input_variable(self):
		if self._is_input():
			return self.name

	def before_call(self, w):
		if self._is_output():
			w.write_line("%s %s;" % (self.parameter.dereferenced_type(), self.name))

	def function_call(self):
		if self._is_input():
			return self.name
		else:
			return "&" + self.name

	def before_build_return_value(self, w):
		pass

	def build_return_value_string(self):
		if self._is_output():
			return self._get_output_type_string()
		else:
			return ""

	def build_return_value_parameter(self):
		if self._is_output():
			return self.name
		else:
			return ""

	def clean_up(self, w):
		if self._is_output() and self._requires_clean_up():
			w.write_line("functions->freeMemory(%s);" % self.name)

class DeviceListParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return parameter.type_def == "char****"

	def before_build_return_value(self, w):
		w.write_line("int count = 0;")
		w.write_line("for(int i = 0; %s[i] != NULL; ++i){ count++; }" % self.name)
		w.write_line("PyObject* list = PyList_New(count);")
		w.write_line("for(int i = 0; %s[i] != NULL; ++i){" % self.name)
		w.write_line('PyList_SetItem(list, i, Py_BuildValue("(ss)", %s[i][0], %s[i][1]));' % (self.name, self.name))
		w.write_line("functions->freeMemory(%s[i][0]);" % self.name)
		w.write_line("functions->freeMemory(%s[i][1]);" % self.name)
		w.write_line("functions->freeMemory(%s[i]);" % self.name)
		w.write_line("}")

	def build_return_value_string(self):
		return "O"
	def build_return_value_parameter(self):
		return "list"

	def clean_up(self, w):
		w.write_line("Py_XDECREF(list);")
		w.write_line("functions->freeMemory(%s);" % self.name)

class PlaybackModesParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return (parameter.type_def == "char***"
			and function.name != "getDefaultPlaybackDevice"
			and function.name != "getDefaultCaptureDevice")

	def before_build_return_value(self, w):
		w.write_line("int count = 0;")
		w.write_line("for(int i = 0; %s[i] != NULL; ++i){ count++; }" % self.name)
		w.write_line("PyObject* list = PyList_New(count);")
		w.write_line("for(int i = 0; %s[i] != NULL; ++i){" % self.name)
		w.write_line('PyList_SetItem(list, i, Py_BuildValue("s", %s[i]));' % self.name)
		w.write_line("functions->freeMemory(%s[i]);" % self.name)
		w.write_line("}")

	def build_return_value_string(self):
		return "O"
	def build_return_value_parameter(self):
		return "list"

	def clean_up(self, w):
		w.write_line("Py_XDECREF(list);")
		w.write_line("functions->freeMemory(%s);" % self.name)

class DefaultDeviceParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return (parameter.type_def == "char***"
			and (function.name == "getDefaultPlaybackDevice"
				or function.name == "getDefaultCaptureDevice"))

	def before_build_return_value(self, w):
		w.write_line('PyObject* tuple = Py_BuildValue("(ss)", %s[0], %s[1]);' % (self.name, self.name))
		w.write_line("functions->freeMemory(%s[0]);" % self.name)
		w.write_line("functions->freeMemory(%s[1]);" % self.name)
		w.write_line("functions->freeMemory(%s);" % self.name)

	def build_return_value_string(self):
		return "O"
	def build_return_value_parameter(self):
		return "tuple"

	def clean_up(self, w):
		w.write_line("functions->freeMemory(%s);" % self.name)

class ArrayInputParameterHandler(DefaultParameterHandler):
	def variable_declaration(self, w):
		w.write_line("PyObject* %s;" % (self.name))

	def before_call(self, w):
		w.write_line('%s %s_c_array = new %s[PyObject_Length(%s)];' % (self.type, self.name, self.parameter.array_declaration_type(), self.name))
		w.write("""
			{
				PyObject *iterator = PyObject_GetIter(%s);
				PyObject *item = NULL;
				#define CLEANUP() do{ \\
				Py_XDECREF(iterator); \\
				Py_XDECREF(item); \\
				} while(0)

				int i = 0;

				if (iterator == NULL) {
				/* propagate error */
				delete[] %s_c_array;
				CLEANUP();
				return NULL;
				}
				while ((item = PyIter_Next(iterator)) != NULL) {
				if(!PyArg_ParseTuple(item, "%t", &%s_c_array[i])){
				delete[] %s_c_array;
				CLEANUP();
				return NULL;
				}
				i++;
				Py_DECREF(item);
				}
				if (PyErr_Occurred()) {
				delete[] %s_c_array;
				CLEANUP();
				return NULL;
				}
				CLEANUP();
				#undef CLEANUP
			}
			""".replace("%s", self.name).replace("%t", self.type_string))

	def function_call(self):
		return "%s_c_array" % (self.name)

	def clean_up(self, w):
		w.write_line("delete[] %s_c_array;" % self.name)

class StringArrayParameterHandler(ArrayInputParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return (parameter.type_def == "const char**")

	type_string = "s"

class IntegerArrayParameterHandler(ArrayInputParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return (parameter.type_def == "const unsigned int*" or parameter.type_def == "const int*")

	type_string = "i"

class ShortArrayParameterHandler(ArrayInputParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return (parameter.type_def == "const short*" or parameter.type_def == "const anyID*")

	type_string = "h"

class Int64ArrayParameterHandler(ArrayInputParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return (parameter.type_def == "const uint64*")

	type_string = "L"

class TS3VectorParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return parameter.type_def == "const TS3_VECTOR*"

	def variable_declaration(self, w):
		w.write_line("%s %s_1;" % ('float', self.name))
		w.write_line("%s %s_2;" % ('float', self.name))
		w.write_line("%s %s_3;" % ('float', self.name))

	def parse_variable(self):
		return "&%s_1, &%s_2, &%s_3".replace("%s", self.name)

	def before_call(self, w):
		w.write_line("TS3_VECTOR %s = {%s_1, %s_2, %s_3};".replace("%s", self.name))

	def function_call(self):
		return "&" + self.name

class CharBufferLengthParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return parameter.name == "maxLen"

	def variable_declaration(self, w):
		pass

	def parse_string(self):
		pass

	def parse_variable(self):
		pass

	def before_call(self, w):
		pass

	def function_call(self):
		return "TS3_STRING_BUFFER_LEN"

	def before_build_return_value(self, w):
		pass

	def build_return_value_string(self):
		pass

	def build_return_value_parameter(self):
		pass

	def clean_up(self, w):
		pass

class CharBufferParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return parameter.type_def == "char*"

	def variable_declaration(self, w):
		pass

	def parse_string(self):
		pass

	def parse_variable(self):
		pass

	def before_call(self, w):
		w.write_line("char* %s = new char[TS3_STRING_BUFFER_LEN];" % self.name)

	def function_call(self):
		return self.name

	def before_build_return_value(self, w):
		pass

	def build_return_value_string(self):
		return "s"

	def build_return_value_parameter(self):
		return self.name

	def clean_up(self, w):
		w.write_line("delete[] %s;" % self.name)

class Int64OutputArrayParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return parameter.type_def == "uint64**"

	def before_build_return_value(self, w):
		w.write_line("int count = 0;")
		w.write_line("for(int i = 0; %s[i] != 0; ++i){count++;}" % self.name)
		w.write_line("PyObject* list = PyList_New(count);")
		w.write_line("""for(int i = 0; %s[i] != 0; ++i){
			PyList_SetItem(list, i, Py_BuildValue("L", %s[i]));
			}""".replace("%s", self.name))

	def build_return_value_parameter(self):
		return "list"

	def clean_up(self, w):
		w.write_line("Py_XDECREF(list);")

class ShortOutputArrayParameterHandler(DefaultParameterHandler):
	@classmethod
	def matches(cls, function, parameter):
		return parameter.type_def == "anyID**"

	def before_build_return_value(self, w):
		w.write_line("int count = 0;")
		w.write_line("for(int i = 0; %s[i] != 0; ++i){count++;}" % self.name)
		w.write_line("PyObject* list = PyList_New(count);")
		w.write_line("""for(int i = 0; %s[i] != 0; ++i){
			PyList_SetItem(list, i, Py_BuildValue("h", %s[i]));
			}""".replace("%s", self.name))

	def build_return_value_parameter(self):
		return "list"

	def clean_up(self, w):
		w.write_line("Py_XDECREF(list);")

ParameterHandlers = [
	# Input handlers
	StringArrayParameterHandler,
	IntegerArrayParameterHandler,
	ShortArrayParameterHandler,
	Int64ArrayParameterHandler,
	TS3VectorParameterHandler,

	# Output Handlers
	DeviceListParameterHandler,
	PlaybackModesParameterHandler,
	DefaultDeviceParameterHandler,
	Int64OutputArrayParameterHandler,
	ShortOutputArrayParameterHandler,
	
	CharBufferLengthParameterHandler,
	CharBufferParameterHandler,
]

def get_parameter_handler(function, parameter):
	for handler in ParameterHandlers:
		if handler.matches(function, parameter):
			return handler(function, parameter)
	return DefaultParameterHandler(function, parameter)


class TS3FunctionGenerator:


	# Certain variables need specific builders
	builder = None

	def __init__(self, function):
		self.function = function
		self.parameters = [get_parameter_handler(function, param) for param in function.parameters]

	# Should we ignore printing this function
	def should_ignore(self):
		try:
			IGNORED_FUNCTIONS[self.function.name]
			return True
		except KeyError:
			return False

	# Gets the string that we should pass into the parse call
	def get_parse_string(self):
		params = [];
		for param in self.parameters:
			value = param.parse_string()
			if value:
				params.append(value)

		return "".join(params)

	# Gets the parameters that go after the string in the parse call
	def get_parse_call_parameters(self):
		params = [];
		for param in self.parameters:
			variable = param.parse_variable()
			if variable:
				params.append(variable)

		return ", ".join(params)

	# Returns the parametrs that go into the c function call
	def get_function_parameters(self):
		parameters = []
		for param in self.parameters:
			value = param.function_call()
			if value:
				parameters.append(value)

		return ", ".join(parameters)

	# Should the value return by the function be ignored
	def should_ignore_function_value(self):
		return self.function.return_type == "void"

	# The string for the build value return call
	def get_build_value_string(self):
		parameters = []
		for param in self.parameters:
			value = param.build_return_value_string()
			if value:
				parameters.append(value)

		return "".join(parameters)

	# The parameters for the build value return call
	def get_build_value_parameters(self):
		parameters = []
		for param in self.parameters:
			value = param.build_return_value_parameter()
			if value:
				parameters.append(value)

		return ", ".join(parameters)

	# Whether or not we require build value
	def requires_build_value(self):
		return self.get_build_value_string() != ""

	def print_function(self, w):

		self.comment(w)
		self.declaration(w)
		self.variables(w)
		self.parse(w)
		self.get_function_pointer(w)
		self.before_function_call(w)
		self.get_function_call(w)
		self.before_build_return_value(w)
		self.build_return_value(w)
		self.clean_up(w)
		self.get_return(w)
		self.end_declaration(w)
	############
	# Begin Output Functions, w is the CCodeWriter instance
	############

	def comment(self, w):
		w.write_line("\n//%s" % self.function.get_c_def())

	def declaration(self, w):
		w.write_line("static PyObject * ts3func_%s(PyObject *self, PyObject *args){" % self.function.name)

	def variables(self, w):
		w.write_line("// Variable Declaration")
		for param in self.parameters:
			param.variable_declaration(w)

	def parse(self, w):
		w.write_line("// Parse Tuple Call")
		if self.get_parse_string() == "":
			return
		w.write_line("""
    if(!PyArg_ParseTuple(args, "%s", %s)){
        printf("Failed to parse args for function %s");
        return NULL;
    }""" % (self.get_parse_string(), self.get_parse_call_parameters(), self.function.name))



	def before_function_call(self, w):
		w.write_line("// Before Function Call")
		for param in self.parameters:
			param.before_call(w)

	def get_function_call(self, w):
		w.write_line("// Function call")
		if self.should_ignore_function_value():
			w.write_line("functions->%s(%s);" % (self.function.name, self.get_function_parameters()));
		else:
			w.write_line("unsigned int functionCallValue = functions->%s(%s);" % (self.function.name, self.get_function_parameters()));
			w.write_line("if(functionCallValue != ERROR_ok){")
			w.write_line('PyErr_Format(PyExc_Exception, "Function call %s returned error code:%%i", functionCallValue);' % self.function.name)
			w.write_line("return NULL;")
			w.write_line("}")

	def get_function_pointer(self, w):
		w.write_line("struct TS3Functions * functions = getTS3FunctionPointers();");

	def before_build_return_value(self, w):
		for param in self.parameters:
			param.before_build_return_value(w)

	def clean_up(self, w):
		w.write_line("// Clean up")
		for param in self.parameters:
			param.clean_up(w)

	def build_return_value(self, w):
		w.write_line("// Build return value")
		if self.requires_build_value():
			w.write_line('PyObject * returnValue = Py_BuildValue("%s", %s);' % (self.get_build_value_string(), self.get_build_value_parameters()))

	def get_return(self, w):
		if self.requires_build_value():
			w.write_line("return returnValue;")
		else:
			w.write_line("Py_RETURN_NONE;")

	def end_declaration(self, w):
		w.write_line("}")


	def get_module_definition(self, w):
		w.write_line('{"%s", ts3func_%s, METH_VARARGS,""},' % (self.function.name, self.function.name))

	def generate_python_method(self, f):
		f.write("\n")
		f.write("\tdef %s(self, **kwargs):\n" % (self.function.name))
		f.write("\t\t# TS3Functions.%s(%s)\n" % (self.function.name, self.python_raw_parameters()))
		f.write("\t\tkwargs = self.to_utf_8(kwargs)\n")
		f.write("\t\treturn TS3Functions.%s(%s)\n" % (self.function.name, self.python_parameters()))

	def python_parameters(self):
		out = []
		for parameter in self.parameters:
			variable = parameter.python_input_variable()
			if not variable:
				continue
			if variable == "serverConnectionHandlerID":
				out.append("self.get_server_connection_id(**kwargs)")
			else:
				out.append("kwargs['%s']" % variable)

		return ", ".join(out)

	def python_raw_parameters(self):
		out = []
		for parameter in self.parameters:
			variable = parameter.python_input_variable()
			if not variable:
				continue
			out.append(variable)

		return ", ".join(out)


def generate(functions):
	f = open(paths.OUTPUT_TS3_FUNCTIONS, "w")
	w = CCodeWriter(f)
	w.write("""
// DO NOT EDIT, AUTO GENERATED FILE

#include "ts3_functions_interface.h"
#include "public_errors.h"
#include "python_setup.h"

#define TS3_STRING_BUFFER_LEN 256
""")
	for function in functions:
		gen = TS3FunctionGenerator(function)
		if gen.should_ignore():
			continue
		gen.print_function(w)

	w.write("""
static PyMethodDef TS3FunctionsMethods[] = {""")
	
	for function in functions:
		gen = TS3FunctionGenerator(function)
		if gen.should_ignore():
			continue
		gen.get_module_definition(w)
	w.write("""
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
init_ts3functions(){
	PyObject *m;

	m = Py_InitModule("TS3Functions", TS3FunctionsMethods);
	if (m == NULL){
		printf("Failed to initialize TS3Functions\\n");
		return;
	}
}
""")
	f.close()