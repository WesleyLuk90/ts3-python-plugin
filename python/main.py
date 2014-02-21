import TS3

# Redirects print to the ts3 window
# Note that calling print too early will cause output to be ignored
TS3.redirect_output()

# loads all modules in the current directory
import os

current_dir = os.path.dirname(os.path.realpath(__file__))
for item in os.listdir(current_dir):
	path = os.path.join(current_dir, item)
	if os.path.isdir(path):
		module = os.path.split(path)[1]
		init_file = os.path.join(path, "__init__.py")
		if os.path.isfile(init_file):
			print "Importing %s" % module
			__import__(module)