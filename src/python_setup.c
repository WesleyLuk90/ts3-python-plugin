#include "python_setup.h"
#include "ts3_module.h"
#include "ts3_functions_interface.h"
#include <stdio.h>
#include <Python.h>
PyThreadState* st;
void initializePython(const char * pluginPath){

	printf("Initializing python\n");
	Py_Initialize();
	printf("Done\n");

	printf("Initializing python threads\n");
	PyEval_InitThreads();
	printf("Done\n");

	printf("Initializing ts3 module\n");
	init_ts3mod();
	init_ts3functions();
	printf("Done\n");

	printf("Setting python path\n");
	setPythonPath(pluginPath);
	printf("Done\n");

	printf("Including main\n");
	includeMain();
	printf("Done\n");

	st = PyEval_SaveThread();
}

void finalizePython(){
	PyEval_RestoreThread(st);
	printf("Finializing python\n");
	Py_Finalize();
	printf("Python has been finalized\n");
}

static struct TS3Functions pythonTS3Functions;

void setTS3FunctionPointers(const struct TS3Functions funcs) {
    pythonTS3Functions = funcs;
}

struct TS3Functions * getTS3FunctionPointers(){
	return &pythonTS3Functions;
}

void setPythonPath(const char * pluginPath){
	char buffer[1024];
	sprintf(buffer, 
		"import sys\n"
		"import os\n"
		"sys.path.append(os.path.join('%s', 'python'))\n", pluginPath);
	printf("Setting include path\n");
	PyRun_SimpleString(buffer);
	printf("Path set\n");
}

void includeMain(){
	printf("Running main python file\n");
	PyRun_SimpleString("import main");
	printf("Main python file included\n");
}

