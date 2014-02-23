/*
 * TeamSpeak 3 demo plugin
 *
 * Copyright (c) 2008-2013 TeamSpeak Systems GmbH
 */

#ifdef _WIN32
#pragma warning (disable : 4100)  /* Disable Unreferenced parameter warning */
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "public_errors.h"
#include "public_errors_rare.h"
#include "public_definitions.h"
#include "public_rare_definitions.h"
#include "ts3_functions.h"
#include "plugin.h"

// My setup
#include "python_setup.h"

 static struct TS3Functions ts3Functions;

#ifdef _WIN32
#define _strcpy(dest, destSize, src) strcpy_s(dest, destSize, src)
#define snprintf sprintf_s
#else
#define _strcpy(dest, destSize, src) { strncpy(dest, src, destSize-1); (dest)[destSize-1] = '\0'; }
#endif

#define PLUGIN_API_VERSION 19

#define PATH_BUFSIZE 512
#define COMMAND_BUFSIZE 128
#define INFODATA_BUFSIZE 128
#define SERVERINFO_BUFSIZE 256
#define CHANNELINFO_BUFSIZE 512
#define RETURNCODE_BUFSIZE 128

 static char* pluginID = NULL;

#ifdef _WIN32
/* Helper function to convert wchar_T to Utf-8 encoded strings on Windows */
 static int wcharToUtf8(const wchar_t* str, char** result) {
 	int outlen = WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, 0, 0, 0);
 	*result = (char*)malloc(outlen);
 	if(WideCharToMultiByte(CP_UTF8, 0, str, -1, *result, outlen, 0, 0) == 0) {
 		*result = NULL;
 		return -1;
 	}
 	return 0;
 }
#endif

/*********************************** Required functions ************************************/
/*
 * If any of these required functions is not implemented, TS3 will refuse to load the plugin
 */

/* Unique name identifying this plugin */
 const char* ts3plugin_name() {
#ifdef _WIN32
	/* TeamSpeak expects UTF-8 encoded characters. Following demonstrates a possibility how to convert UTF-16 wchar_t into UTF-8. */
	static char* result = NULL;  /* Static variable so it's allocated only once */
 	if(!result) {
 		const wchar_t* name = L"Python Plugin";
		if(wcharToUtf8(name, &result) == -1) {  /* Convert name into UTF-8 encoded result */
			result = "Test Plugin";  /* Conversion failed, fallback here */
 	}
 }
 return result;
#else
 return "Python Plugin";
#endif
}

/* Plugin version */
const char* ts3plugin_version() {
	return "1.0";
}

/* Plugin API version. Must be the same as the clients API major version, else the plugin fails to load. */
int ts3plugin_apiVersion() {
	return PLUGIN_API_VERSION;
}

/* Plugin author */
const char* ts3plugin_author() {
	/* If you want to use wchar_t, see ts3plugin_name() on how to use */
	return "Someone";
}

/* Plugin description */
const char* ts3plugin_description() {
	/* If you want to use wchar_t, see ts3plugin_name() on how to use */
	return "This plugin adds a python interface to TS3.";
}

bool functionPointersSet = false;
bool pathSet = false;
bool pythonInitialized = false;
char pluginPath[PATH_BUFSIZE];
void doInitializePython(){
	if(functionPointersSet && pathSet){
		if(!pythonInitialized){
			pythonInitialized = true;
			printf("Starting to initialize python\n");
			initializePython(pluginPath);
		}
	}
}
/* Set TeamSpeak 3 callback functions */
void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
	ts3Functions = funcs;
	setTS3FunctionPointers(funcs);
	functionPointersSet = true;
	doInitializePython();
}

/*
 * Custom code called right after loading the plugin. Returns 0 on success, 1 on failure.
 * If the function returns 1 on failure, the plugin will be unloaded again.
 */
// We need the plugin path later
 int ts3plugin_init() {
 	char appPath[PATH_BUFSIZE];
 	char resourcesPath[PATH_BUFSIZE];
 	char configPath[PATH_BUFSIZE];

    /* Example on how to query application, resources and configuration paths from client */
    /* Note: Console client returns empty string for app and resources path */
 	ts3Functions.getAppPath(appPath, PATH_BUFSIZE);
 	ts3Functions.getResourcesPath(resourcesPath, PATH_BUFSIZE);
 	ts3Functions.getConfigPath(configPath, PATH_BUFSIZE);
 	ts3Functions.getPluginPath(pluginPath, PATH_BUFSIZE);
 	pathSet = true;
 	doInitializePython();
    return 0; // Success
}

/* Custom code called right before the plugin is unloaded */
void ts3plugin_shutdown() {
    /* Your plugin cleanup code here */
	finalizePython();
	/*
	 * Note:
	 * If your plugin implements a settings dialog, it must be closed and deleted here, else the
	 * TeamSpeak client will most likely crash (DLL removed but dialog from DLL code still open).
	 */

	/* Free pluginID if we registered it */
	 if(pluginID) {
	 	free(pluginID);
	 	pluginID = NULL;
	 }
	}


#include "ts3_python_callbacks.h"