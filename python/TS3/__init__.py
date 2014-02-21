import TS3Module
import TS3Functions
from callback import ClientEventHandler

import sys
import traceback

from functions import Connection

# Exported Values
# Connection To call TS3 functions
# ClientEventHandler To listen for client events
# register_callback_handler To register a ClientEventHandler


_callback_handlers = []

def register_callback_handler(handler):
	_callback_handlers.append(handler)

def _convert_to_unicode(dictionary):
	for k,v in dictionary.items():
		if type(v) is str:
			dictionary[k] = unicode(v, "utf-8")
	return dictionary

# Adds the connection object to the arguments for easy function calling
def _create_connection(dictionary):
	connection = Connection()
	dictionary['connection'] = connection
	try:
		connection.set_server_connection_id(dictionary['serverConnectionHandlerID'])
	except KeyError:
		pass
	return dictionary

# The handler for all calls
class _CallbackCaller:
	def __getattr__(self, key):
		def call_callback(**kwargs):
			for handler in _callback_handlers:
				try:
					args = _convert_to_unicode(kwargs)
					args = _create_connection(args)
					getattr(handler, key)(**args)
				except:
					traceback.print_exc()
		return call_callback

TS3Module.register_client_event_handler(_CallbackCaller())

import string

class _CustomWriter:
	base = None

	def __init__(self, base):
		self.base = base

	def write(self, s):
		try:
			self.base.write(s)
			s = s.rstrip(string.whitespace)
			if type(s) is unicode:
				s = s.encode('utf-8', 'replace')
			if s == "":
				return
			TS3Functions.printMessageToCurrentTab(s)
		except:
			pass # Ignore all errors so that we don't get stuck in a loop

_original_stdout = sys.stdout
_original_stderr = sys.stderr
_redirected_stdout = _CustomWriter(_original_stdout)
_redirected_stderr = _CustomWriter(_original_stderr)

def redirect_output(stdout = True, stderr = True):
	if stdout:
		sys.stdout = _redirected_stdout
	else:
		sys.stdout = _original_stdout

	if stderr:
		sys.stderr = _redirected_stderr
	else:
		sys.stderr = _original_stderr