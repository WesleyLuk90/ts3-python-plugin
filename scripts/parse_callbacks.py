import paths
import re

FUNCTIONS_START_MARKER = "/* Clientlib */"
PLUGINS_EXPORTDLL = "PLUGINS_EXPORTDLL"
FUNC_DEF_PARSER = re.compile(r"PLUGINS_EXPORTDLL\s+([\w\d_\*]+)\s+([\w\d_]+)\s*\((.*)\);")

class Parameter:
	def __init__(self, name, type_def):
		self.name = name.strip()
		self.type_def = type_def.strip()

	def get_c_def(self):
		return "%s %s" % (self.type_def, self.name)

	def __str__(self):
		return "%s -> %s" % (self.name, self.type_def)

	def dereferenced_type(self):
		if self.type_def[-1] != "*":
			raise Exception("Trying to dereference type %s" % self.type_def)
		return self.type_def[:-1]

	def array_declaration_type(self):
		the_type = self.dereferenced_type()
		if the_type.count("*") > 0:
			return the_type
		if the_type.find("const ") == 0:
			return the_type[6:]
		else:
			return the_type

class Function:
	def __init__(self, name, return_type):
		self.name = name
		self.return_type = return_type.strip()
		self.parameters = []

	def add_parameter(self, parameter):
		self.parameters.append(parameter)

	def short_name(self):
		return self.name.split("_")[1]

	def get_c_def(self):
		parameters = ", ".join([par.get_c_def() for par in self.parameters])
		return "%s %s(%s)" % (self.return_type, self.name, parameters)

	def __str__(self):
		parameters = ", ".join([str(par) for par in self.parameters])
		return "Function %s[%s] -> %s" % (self.name, parameters, self.return_type)

def parse_line(line):
	match = FUNC_DEF_PARSER.match(line)
	if not match:
		raise BaseException("Failed to parse line %s" % line)

	func = Function(match.group(2), match.group(1))

	param_strings = match.group(3).split(",")

	for param_string in param_strings:
		params = param_string.rsplit(" ", 1)
		param = Parameter(params[1], params[0])
		func.add_parameter(param);

	return func

def parse():
	f = open(paths.HEADER_FILE, "r")

	functions = []

	found = False
	for line in f:
		if line.strip() == FUNCTIONS_START_MARKER:
			found = True
			continue
		if not found:
			continue
		if line.find(PLUGINS_EXPORTDLL) == 0:
			function = parse_line(line)
			functions.append(function)

	return functions

