import paths
from ts3_function_bindings_generator import TS3FunctionGenerator


def generate(functions):
	f = open(paths.OUTPUT_FUNCTIONS_CLASS, "w")

	f.write("""
# AUTOGENERATED FILE DO NOT EDIT
import TS3Functions

class Connection:

	serverConnectionID = None

	def __init__(self, serverConnectionID = None):
		self.serverConnectionID = serverConnectionID

	def set_server_connection_id(self, id):
		self.serverConnectionID = id

	# Returns the server connection id if it is specified either by arguments
	# Or defined on this class
	def get_server_connection_id(self, serverConnectionHandlerID = None, **kwargs):
		if serverConnectionHandlerID != None:
			return serverConnectionHandlerID
		if self.serverConnectionID != None:
			return self.serverConnectionID
		raise Exception("Error, no serverConnectionHandlerID specified, either pass it in as an arguments or set it on the Connection class")

	def to_utf_8(self, args):
		for k,v in args.items():
			if type(v) is unicode:
				args[k] = v.encode('utf-8', 'replace')
		return args

	def from_utf_8(self, value):
		if type(value) is str:
			return unicode(value, 'utf-8')
		return value

		""")

	for function in functions:
		gen = TS3FunctionGenerator(function)
		gen.generate_python_method(f)

	f.close()