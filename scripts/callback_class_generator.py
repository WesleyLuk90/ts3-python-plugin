import paths

class PythonCallbackGenerator:

	def __init__(self, function):
		self.function = function

	def get(self):
		return """
	%s
	def %s(%s):
		%s
""" % (self.function_signature(), self.function_definition(), self.function_parameters(), self.function_body())

	def function_definition(self):
		return self.function.short_name()

	def function_parameters(self):
		parameters = ["self", "**kwargs"]

		# for param in self.function.parameters:
		# 	parameters.append(param.name)

		return ", ".join(parameters)

	def function_signature(self):
		return "# %s(%s)" % (self.function.name, ", ".join(param.name for param in self.function.parameters))

	def function_body(self):
		return "pass"


def generate(functions):
	f = open(paths.OUTPUT_CALLBACK_CLASS, "w")
	f.write("# GENERATED FILE DO NOT EDIT\n")
	f.write("# Class recieves callbacks\n")
# 	f.write("from collections import defaultdict\n")

# 	f.write("""
# class Struct(object):
# 	def __init__(self, **entries):
# 		self.__dict__.update(entries)


# """)

	f.write("class ClientEventHandler:\n")

# 	f.write("""
# 	def __init__(self):
# 		self.handlers = defaultdict(list)

# 	def call_handler(self, event, params):
# 		for handler in self.handlers[event]:
# 			handler(params)

# 	def register_handler(self, event, func):
# 		self.handlers[event].append(func)
# """)

	for function in functions:
		generator = PythonCallbackGenerator(function)
		f.write(generator.get())

	f.close()