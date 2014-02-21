from parse_callbacks import Parameter, Function
import paths
import re

FUNC_DEF_PARSER = re.compile(r"\s*(.*?)\s+\(\*([\w\d_]+)\)\s*\((.*)\);")

def build_function(name, type, params):
	function = Function(type, name)

	for param_chunk in params.split(","):
		if not param_chunk.strip():
			continue
		name, type = param_chunk.rsplit(" ", 1)
		parameter = Parameter(type, name)
		function.add_parameter(parameter)

	return function

def parse():
	f = open(paths.TS3_FUNCTIONS_FILE, "r")

	functions = []

	found = False
	for line in f:
		match = FUNC_DEF_PARSER.match(line)
		if match:
			function = build_function(match.group(1), match.group(2), match.group(3))
			functions.append(function)
			# print function
	return functions

