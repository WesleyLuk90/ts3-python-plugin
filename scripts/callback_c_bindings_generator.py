import paths
from CCodeWriter import CCodeWriter

TYPE_MAP = {
	'uint64': 'L',
	'int': 'i',
	'unsigned int': 'i',
	'unsigned int': 'i',
	'enum PluginMenuType': 'i',
	'anyID': 'h',
	'char*': 's',
	'const char*': 's',
	'float': 'f',
	# will construct an array for these parameters
	'short*': 'O', 
	'float*': 'O', 
	'int*': 'O',
	'unsigned int*': 'O',
	'const unsigned int*': 'O',
	'const unsigned int*': 'O',
}

ARRAY_TYPES = {
	'short*': 'h', 
	'float*': 'f', 
	'int*': 'i',
	'unsigned int*': 'i',
	'const unsigned int*': 'i',
	'const unsigned int*': 'i',
}

IGNORE = {
	'ts3plugin_onCustom3dRolloffCalculationClientEvent': True,
	'ts3plugin_onCustom3dRolloffCalculationWaveEvent': True,
}

class DefaultVariableHandler:
	def __init__(self, function, parameter):
		self.function = function
		self.parameter = parameter

	@property
	def name(self):
		return self.parameter.name

	@property
	def type(self):
		return self.parameter.type_def

	@property
	def type_string(self):
		return TYPE_MAP[self.type]

	@property
	def array_name(self):
		return self.name + "_array"

	def is_array(self):
		try:
			ARRAY_TYPES[self.type]
			return True
		except:
			return False

	def get_array_type(self):
		return ARRAY_TYPES[self.type]

	def function_parameter(self):
		return self.parameter.get_c_def()

	def build_array(self, w):
		if not self.is_array():
			return
		w.write_line("""
	PyObject * %(array_name)s;
	{
		int count = 0;
		for(int i = 0; %(condition)s; i++) { count++; }
		%(array_name)s = PyList_New(count);
		for(int i = 0; %(condition)s; i++) {
			PyList_SetItem(%(array_name)s, i, Py_BuildValue("%(array_type)s", %(name)s[i]));
		}
	}""" % {
		'array_name': self.array_name,
		'name': self.name,
		'array_type': self.get_array_type(),
		'type': self.type,
		'condition': self.get_condition(self.name, "i"),
		})

	def get_condition(self, variable, index):
		for param in self.function.parameters:
			if param.name.find(variable[:-1] + 'Count') > -1:
				return "%s < %s" % (index, param.name)
		if self.type.count("*") > 1:
			return "%s[%s] != NULL" % (variable, index)
		else:
			return "%s[%s] != 0" % (variable, index)

	def build_map(self, w):
		# if self.type.find("*") > -1:
			# w.write_line('printf("Value address is 0x%%p\\n", %s);' % self.name)
		if self.is_array():
			w.write_line('temp = Py_BuildValue("%s", %s);' % (self.type_string, self.array_name))
		else:
			w.write_line('temp = Py_BuildValue("%s", %s);' % (self.type_string, self.name))
		w.write_line('PyDict_SetItemString(kwargs, "%s", temp);' % (self.name))
		w.write_line('Py_XDECREF(temp);')

	def clean_up(self, w):
		if not self.is_array():
			return
		w.write_line("Py_XDECREF(%s);" % self.array_name)

def get_parameter_handler(function, parameter):
	return DefaultVariableHandler(function, parameter)

class CCallbackBindingsGenerator:


	def __init__(self, function):
		self.function = function
		self.parameters = []
		for param in function.parameters:
			self.parameters.append(get_parameter_handler(function, param))

	def should_ignore(self):
		try:
			IGNORE[self.function.name]
			return True
		except:
			return False

	def get_definition(self, w):
		self.get_function_declaration(w)
		# w.write_line('printf("Infunction %s\\n");' % self.function.name)
		if not self.should_ignore():
			pass
			w.write_line("""PyGILState_STATE gstate;
gstate = PyGILState_Ensure();""")
			self.build_arrays(w)
			self.build_map(w)
			self.do_call(w)
			self.clean_up(w)
			w.write_line("""PyGILState_Release(gstate);""")
		self.end_function(w)

	def get_function_declaration(self, w):
		w.write_line("%s %s(%s) { " % (self.function.return_type,
			self.function.name,
			self.get_function_parameters()))

	def build_arrays(self, w):
		for param in self.parameters:
			param.build_array(w)

	def build_map(self, w):
		self.get_build_args(w)
		self.get_arg_check(w)
		w.write_line("PyObject * temp = NULL;")
		for param in self.parameters:
			param.build_map(w)

	def do_call(self, w):
		self.get_call(w)

	def clean_up(self, w):
		for param in self.parameters:
			param.clean_up(w)
		w.write_line("Py_XDECREF(kwargs);")

	def end_function(self, w):
		self.get_return(w)
		w.write_line("}")

	def get_function_parameters(self):
		return ", ".join(param.function_parameter() for param in self.parameters)

	def get_array_variable_name(self, name):
		return name + "_array";

	def get_build_args(self, w):
		w.write_line("PyObject *kwargs = PyDict_New();");

	def get_arg_check(self, w):
		w.write_line("if(!kwargs){")
		w.write_line('printf("Failed to build value in function %s\\n");'% self.function.name)
		self.get_return(w);
		w.write_line("}");

	def get_call(self, w):
		w.write_line('callEventHandler("%s", kwargs);' % self.function.short_name())

	def get_return(self, w):
		if self.function.return_type == "int":
			w.write_line("return 0;")
		else:
			w.write_line("return;")



def generate(functions):
	f = open(paths.OUTPUT_CALLBACK_C_BINDINGS, "w")
	c = CCodeWriter(f)
	# write out the header first
	c.write("""
// DO NOT EDIT, AUTOGENERATED FILE

#include <Python.h>
#include "ts3_module.h"

void callEventHandler(const char * methodName, PyObject *kwargs){
	PyObject * clientEventHandlerIterator = getClientEventHandlerIterator();
	if(!PyIter_Check(clientEventHandlerIterator)){
		printf("clientEventHandlerIterator is not iterable\\n");
		return;
	}

	PyObject * item;
	while ((item = PyIter_Next(clientEventHandlerIterator)) != NULL) {
		PyObject * method = PyObject_GetAttrString(item, methodName);
		if(!PyCallable_Check(method)){
			printf("ClientEventHandler's method %s is not callable\\n", methodName);
		} else {
			PyObject * tuple = PyTuple_New(0);
			PyObject * value = PyObject_Call(method, tuple, kwargs);
			if(!value){
				printf("Method call failed in %s\\n", methodName);
				if(PyErr_Occurred()){
					PyErr_Print();
				}
			}
			Py_XDECREF(value);
			Py_XDECREF(tuple);
		}
	    Py_XDECREF(method);
	    Py_XDECREF(item);
	}
	Py_XDECREF(clientEventHandlerIterator);
}
""")

	for function in functions:
		generator = CCallbackBindingsGenerator(function)
		generator.get_definition(c)
	f.close();