
// DO NOT EDIT, AUTO GENERATED FILE

#include "ts3_functions_interface.h"
#include "public_errors.h"
#include "python_setup.h"

#define TS3_STRING_BUFFER_LEN 256

//unsigned int getClientLibVersion(char** result)
static PyObject * ts3func_getClientLibVersion(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getClientLibVersion(&result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientLibVersion returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getClientLibVersionNumber(uint64* result)
static PyObject * ts3func_getClientLibVersionNumber(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getClientLibVersionNumber(&result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientLibVersionNumber returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int spawnNewServerConnectionHandler(int port, uint64* result)
static PyObject * ts3func_spawnNewServerConnectionHandler(PyObject *self, PyObject *args){
	// Variable Declaration
	int port;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "i", &port)){
		printf("Failed to parse args for function spawnNewServerConnectionHandler");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->spawnNewServerConnectionHandler(port, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call spawnNewServerConnectionHandler returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int destroyServerConnectionHandler(uint64 serverConnectionHandlerID)
static PyObject * ts3func_destroyServerConnectionHandler(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function destroyServerConnectionHandler");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->destroyServerConnectionHandler(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call destroyServerConnectionHandler returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getErrorMessage(unsigned int errorCode, char** error)
static PyObject * ts3func_getErrorMessage(PyObject *self, PyObject *args){
	// Variable Declaration
	unsigned int errorCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "i", &errorCode)){
		printf("Failed to parse args for function getErrorMessage");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* error;
	// Function call
	unsigned int functionCallValue = functions->getErrorMessage(errorCode, &error);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getErrorMessage returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", error);
	// Clean up
	functions->freeMemory(error);
	return returnValue;
}

//unsigned int logMessage(const char* logMessage, enum LogLevel severity, const char* channel, uint64 logID)
static PyObject * ts3func_logMessage(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* logMessage;
	enum LogLevel severity;
	const char* channel;
	uint64 logID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "sisL", &logMessage, &severity, &channel, &logID)){
		printf("Failed to parse args for function logMessage");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->logMessage(logMessage, severity, channel, logID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call logMessage returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getPlaybackDeviceList(const char* modeID, char**** result)
static PyObject * ts3func_getPlaybackDeviceList(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* modeID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &modeID)){
		printf("Failed to parse args for function getPlaybackDeviceList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char*** result;
	// Function call
	unsigned int functionCallValue = functions->getPlaybackDeviceList(modeID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getPlaybackDeviceList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != NULL; ++i){ count++; }
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != NULL; ++i){
		PyList_SetItem(list, i, Py_BuildValue("(ss)", result[i][0], result[i][1]));
		functions->freeMemory(result[i][0]);
		functions->freeMemory(result[i][1]);
		functions->freeMemory(result[i]);
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getPlaybackModeList(char*** result)
static PyObject * ts3func_getPlaybackModeList(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char** result;
	// Function call
	unsigned int functionCallValue = functions->getPlaybackModeList(&result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getPlaybackModeList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != NULL; ++i){ count++; }
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != NULL; ++i){
		PyList_SetItem(list, i, Py_BuildValue("s", result[i]));
		functions->freeMemory(result[i]);
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getCaptureDeviceList(const char* modeID, char**** result)
static PyObject * ts3func_getCaptureDeviceList(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* modeID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &modeID)){
		printf("Failed to parse args for function getCaptureDeviceList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char*** result;
	// Function call
	unsigned int functionCallValue = functions->getCaptureDeviceList(modeID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCaptureDeviceList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != NULL; ++i){ count++; }
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != NULL; ++i){
		PyList_SetItem(list, i, Py_BuildValue("(ss)", result[i][0], result[i][1]));
		functions->freeMemory(result[i][0]);
		functions->freeMemory(result[i][1]);
		functions->freeMemory(result[i]);
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getCaptureModeList(char*** result)
static PyObject * ts3func_getCaptureModeList(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char** result;
	// Function call
	unsigned int functionCallValue = functions->getCaptureModeList(&result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCaptureModeList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != NULL; ++i){ count++; }
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != NULL; ++i){
		PyList_SetItem(list, i, Py_BuildValue("s", result[i]));
		functions->freeMemory(result[i]);
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getDefaultPlaybackDevice(const char* modeID, char*** result)
static PyObject * ts3func_getDefaultPlaybackDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* modeID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &modeID)){
		printf("Failed to parse args for function getDefaultPlaybackDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char** result;
	// Function call
	unsigned int functionCallValue = functions->getDefaultPlaybackDevice(modeID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getDefaultPlaybackDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	PyObject* tuple = Py_BuildValue("(ss)", result[0], result[1]);
	functions->freeMemory(result[0]);
	functions->freeMemory(result[1]);
	functions->freeMemory(result);
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", tuple);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getDefaultPlayBackMode(char** result)
static PyObject * ts3func_getDefaultPlayBackMode(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getDefaultPlayBackMode(&result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getDefaultPlayBackMode returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getDefaultCaptureDevice(const char* modeID, char*** result)
static PyObject * ts3func_getDefaultCaptureDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* modeID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &modeID)){
		printf("Failed to parse args for function getDefaultCaptureDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char** result;
	// Function call
	unsigned int functionCallValue = functions->getDefaultCaptureDevice(modeID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getDefaultCaptureDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	PyObject* tuple = Py_BuildValue("(ss)", result[0], result[1]);
	functions->freeMemory(result[0]);
	functions->freeMemory(result[1]);
	functions->freeMemory(result);
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", tuple);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getDefaultCaptureMode(char** result)
static PyObject * ts3func_getDefaultCaptureMode(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getDefaultCaptureMode(&result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getDefaultCaptureMode returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int openPlaybackDevice(uint64 serverConnectionHandlerID, const char* modeID, const char* playbackDevice)
static PyObject * ts3func_openPlaybackDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* modeID;
	const char* playbackDevice;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &modeID, &playbackDevice)){
		printf("Failed to parse args for function openPlaybackDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->openPlaybackDevice(serverConnectionHandlerID, modeID, playbackDevice);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call openPlaybackDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int openCaptureDevice(uint64 serverConnectionHandlerID, const char* modeID, const char* captureDevice)
static PyObject * ts3func_openCaptureDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* modeID;
	const char* captureDevice;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &modeID, &captureDevice)){
		printf("Failed to parse args for function openCaptureDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->openCaptureDevice(serverConnectionHandlerID, modeID, captureDevice);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call openCaptureDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getCurrentPlaybackDeviceName(uint64 serverConnectionHandlerID, char** result, int* isDefault)
static PyObject * ts3func_getCurrentPlaybackDeviceName(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getCurrentPlaybackDeviceName");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	int isDefault;
	// Function call
	unsigned int functionCallValue = functions->getCurrentPlaybackDeviceName(serverConnectionHandlerID, &result, &isDefault);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCurrentPlaybackDeviceName returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("si", result, isDefault);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getCurrentPlayBackMode(uint64 serverConnectionHandlerID, char** result)
static PyObject * ts3func_getCurrentPlayBackMode(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getCurrentPlayBackMode");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getCurrentPlayBackMode(serverConnectionHandlerID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCurrentPlayBackMode returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getCurrentCaptureDeviceName(uint64 serverConnectionHandlerID, char** result, int* isDefault)
static PyObject * ts3func_getCurrentCaptureDeviceName(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getCurrentCaptureDeviceName");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	int isDefault;
	// Function call
	unsigned int functionCallValue = functions->getCurrentCaptureDeviceName(serverConnectionHandlerID, &result, &isDefault);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCurrentCaptureDeviceName returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("si", result, isDefault);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getCurrentCaptureMode(uint64 serverConnectionHandlerID, char** result)
static PyObject * ts3func_getCurrentCaptureMode(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getCurrentCaptureMode");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getCurrentCaptureMode(serverConnectionHandlerID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCurrentCaptureMode returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int initiateGracefulPlaybackShutdown(uint64 serverConnectionHandlerID)
static PyObject * ts3func_initiateGracefulPlaybackShutdown(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function initiateGracefulPlaybackShutdown");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->initiateGracefulPlaybackShutdown(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call initiateGracefulPlaybackShutdown returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int closePlaybackDevice(uint64 serverConnectionHandlerID)
static PyObject * ts3func_closePlaybackDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function closePlaybackDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->closePlaybackDevice(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call closePlaybackDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int closeCaptureDevice(uint64 serverConnectionHandlerID)
static PyObject * ts3func_closeCaptureDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function closeCaptureDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->closeCaptureDevice(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call closeCaptureDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int activateCaptureDevice(uint64 serverConnectionHandlerID)
static PyObject * ts3func_activateCaptureDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function activateCaptureDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->activateCaptureDevice(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call activateCaptureDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int playWaveFileHandle(uint64 serverConnectionHandlerID, const char* path, int loop, uint64* waveHandle)
static PyObject * ts3func_playWaveFileHandle(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* path;
	int loop;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lsi", &serverConnectionHandlerID, &path, &loop)){
		printf("Failed to parse args for function playWaveFileHandle");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 waveHandle;
	// Function call
	unsigned int functionCallValue = functions->playWaveFileHandle(serverConnectionHandlerID, path, loop, &waveHandle);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call playWaveFileHandle returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", waveHandle);
	// Clean up
	return returnValue;
}

//unsigned int pauseWaveFileHandle(uint64 serverConnectionHandlerID, uint64 waveHandle, int pause)
static PyObject * ts3func_pauseWaveFileHandle(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 waveHandle;
	int pause;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLi", &serverConnectionHandlerID, &waveHandle, &pause)){
		printf("Failed to parse args for function pauseWaveFileHandle");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->pauseWaveFileHandle(serverConnectionHandlerID, waveHandle, pause);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call pauseWaveFileHandle returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int closeWaveFileHandle(uint64 serverConnectionHandlerID, uint64 waveHandle)
static PyObject * ts3func_closeWaveFileHandle(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 waveHandle;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LL", &serverConnectionHandlerID, &waveHandle)){
		printf("Failed to parse args for function closeWaveFileHandle");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->closeWaveFileHandle(serverConnectionHandlerID, waveHandle);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call closeWaveFileHandle returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int playWaveFile(uint64 serverConnectionHandlerID, const char* path)
static PyObject * ts3func_playWaveFile(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* path;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &path)){
		printf("Failed to parse args for function playWaveFile");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->playWaveFile(serverConnectionHandlerID, path);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call playWaveFile returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int registerCustomDevice(const char* deviceID, const char* deviceDisplayName, int capFrequency, int capChannels, int playFrequency, int playChannels)
static PyObject * ts3func_registerCustomDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* deviceID;
	const char* deviceDisplayName;
	int capFrequency;
	int capChannels;
	int playFrequency;
	int playChannels;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "ssiiii", &deviceID, &deviceDisplayName, &capFrequency, &capChannels, &playFrequency, &playChannels)){
		printf("Failed to parse args for function registerCustomDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->registerCustomDevice(deviceID, deviceDisplayName, capFrequency, capChannels, playFrequency, playChannels);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call registerCustomDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int unregisterCustomDevice(const char* deviceID)
static PyObject * ts3func_unregisterCustomDevice(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* deviceID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &deviceID)){
		printf("Failed to parse args for function unregisterCustomDevice");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->unregisterCustomDevice(deviceID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call unregisterCustomDevice returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int processCustomCaptureData(const char* deviceName, const short* buffer, int samples)
static PyObject * ts3func_processCustomCaptureData(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* deviceName;
	PyObject* buffer;
	int samples;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "sOi", &deviceName, &buffer, &samples)){
		printf("Failed to parse args for function processCustomCaptureData");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	short* buffer_c_array = new short[PyObject_Length(buffer)];
	
	{
		PyObject *iterator = PyObject_GetIter(buffer);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] buffer_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			buffer_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] buffer_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] buffer_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->processCustomCaptureData(deviceName, buffer_c_array, samples);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call processCustomCaptureData returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] buffer_c_array;
	Py_RETURN_NONE;
}

//unsigned int acquireCustomPlaybackData(const char* deviceName, short* buffer, int samples)
static PyObject * ts3func_acquireCustomPlaybackData(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* deviceName;
	int samples;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "si", &deviceName, &samples)){
		printf("Failed to parse args for function acquireCustomPlaybackData");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	short buffer;
	// Function call
	unsigned int functionCallValue = functions->acquireCustomPlaybackData(deviceName, &buffer, samples);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call acquireCustomPlaybackData returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("j", buffer);
	// Clean up
	return returnValue;
}

//unsigned int getPreProcessorInfoValueFloat(uint64 serverConnectionHandlerID, const char* ident, float* result)
static PyObject * ts3func_getPreProcessorInfoValueFloat(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* ident;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &ident)){
		printf("Failed to parse args for function getPreProcessorInfoValueFloat");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	float result;
	// Function call
	unsigned int functionCallValue = functions->getPreProcessorInfoValueFloat(serverConnectionHandlerID, ident, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getPreProcessorInfoValueFloat returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("f", result);
	// Clean up
	return returnValue;
}

//unsigned int getPreProcessorConfigValue(uint64 serverConnectionHandlerID, const char* ident, char** result)
static PyObject * ts3func_getPreProcessorConfigValue(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* ident;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &ident)){
		printf("Failed to parse args for function getPreProcessorConfigValue");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getPreProcessorConfigValue(serverConnectionHandlerID, ident, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getPreProcessorConfigValue returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int setPreProcessorConfigValue(uint64 serverConnectionHandlerID, const char* ident, const char* value)
static PyObject * ts3func_setPreProcessorConfigValue(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* ident;
	const char* value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &ident, &value)){
		printf("Failed to parse args for function setPreProcessorConfigValue");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setPreProcessorConfigValue(serverConnectionHandlerID, ident, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setPreProcessorConfigValue returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getEncodeConfigValue(uint64 serverConnectionHandlerID, const char* ident, char** result)
static PyObject * ts3func_getEncodeConfigValue(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* ident;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &ident)){
		printf("Failed to parse args for function getEncodeConfigValue");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getEncodeConfigValue(serverConnectionHandlerID, ident, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getEncodeConfigValue returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getPlaybackConfigValueAsFloat(uint64 serverConnectionHandlerID, const char* ident, float* result)
static PyObject * ts3func_getPlaybackConfigValueAsFloat(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* ident;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &ident)){
		printf("Failed to parse args for function getPlaybackConfigValueAsFloat");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	float result;
	// Function call
	unsigned int functionCallValue = functions->getPlaybackConfigValueAsFloat(serverConnectionHandlerID, ident, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getPlaybackConfigValueAsFloat returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("f", result);
	// Clean up
	return returnValue;
}

//unsigned int setPlaybackConfigValue(uint64 serverConnectionHandlerID, const char* ident, const char* value)
static PyObject * ts3func_setPlaybackConfigValue(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* ident;
	const char* value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &ident, &value)){
		printf("Failed to parse args for function setPlaybackConfigValue");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setPlaybackConfigValue(serverConnectionHandlerID, ident, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setPlaybackConfigValue returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int setClientVolumeModifier(uint64 serverConnectionHandlerID, anyID clientID, float value)
static PyObject * ts3func_setClientVolumeModifier(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	float value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhf", &serverConnectionHandlerID, &clientID, &value)){
		printf("Failed to parse args for function setClientVolumeModifier");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setClientVolumeModifier(serverConnectionHandlerID, clientID, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setClientVolumeModifier returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int startVoiceRecording(uint64 serverConnectionHandlerID)
static PyObject * ts3func_startVoiceRecording(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function startVoiceRecording");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->startVoiceRecording(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call startVoiceRecording returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int stopVoiceRecording(uint64 serverConnectionHandlerID)
static PyObject * ts3func_stopVoiceRecording(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function stopVoiceRecording");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->stopVoiceRecording(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call stopVoiceRecording returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int systemset3DListenerAttributes(uint64 serverConnectionHandlerID, const TS3_VECTOR* position, const TS3_VECTOR* forward, const TS3_VECTOR* up)
static PyObject * ts3func_systemset3DListenerAttributes(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	float position_1;
	float position_2;
	float position_3;
	float forward_1;
	float forward_2;
	float forward_3;
	float up_1;
	float up_2;
	float up_3;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L(fff)(fff)(fff)", &serverConnectionHandlerID, &position_1, &position_2, &position_3, &forward_1, &forward_2, &forward_3, &up_1, &up_2, &up_3)){
		printf("Failed to parse args for function systemset3DListenerAttributes");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	TS3_VECTOR position = {position_1, position_2, position_3};
	TS3_VECTOR forward = {forward_1, forward_2, forward_3};
	TS3_VECTOR up = {up_1, up_2, up_3};
	// Function call
	unsigned int functionCallValue = functions->systemset3DListenerAttributes(serverConnectionHandlerID, &position, &forward, &up);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call systemset3DListenerAttributes returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int set3DWaveAttributes(uint64 serverConnectionHandlerID, uint64 waveHandle, const TS3_VECTOR* position)
static PyObject * ts3func_set3DWaveAttributes(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 waveHandle;
	float position_1;
	float position_2;
	float position_3;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LL(fff)", &serverConnectionHandlerID, &waveHandle, &position_1, &position_2, &position_3)){
		printf("Failed to parse args for function set3DWaveAttributes");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	TS3_VECTOR position = {position_1, position_2, position_3};
	// Function call
	unsigned int functionCallValue = functions->set3DWaveAttributes(serverConnectionHandlerID, waveHandle, &position);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call set3DWaveAttributes returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int systemset3DSettings(uint64 serverConnectionHandlerID, float distanceFactor, float rolloffScale)
static PyObject * ts3func_systemset3DSettings(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	float distanceFactor;
	float rolloffScale;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lff", &serverConnectionHandlerID, &distanceFactor, &rolloffScale)){
		printf("Failed to parse args for function systemset3DSettings");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->systemset3DSettings(serverConnectionHandlerID, distanceFactor, rolloffScale);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call systemset3DSettings returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int channelset3DAttributes(uint64 serverConnectionHandlerID, anyID clientID, const TS3_VECTOR* position)
static PyObject * ts3func_channelset3DAttributes(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	float position_1;
	float position_2;
	float position_3;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lh(fff)", &serverConnectionHandlerID, &clientID, &position_1, &position_2, &position_3)){
		printf("Failed to parse args for function channelset3DAttributes");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	TS3_VECTOR position = {position_1, position_2, position_3};
	// Function call
	unsigned int functionCallValue = functions->channelset3DAttributes(serverConnectionHandlerID, clientID, &position);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call channelset3DAttributes returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int stopConnection(uint64 serverConnectionHandlerID, const char* quitMessage)
static PyObject * ts3func_stopConnection(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* quitMessage;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &quitMessage)){
		printf("Failed to parse args for function stopConnection");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->stopConnection(serverConnectionHandlerID, quitMessage);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call stopConnection returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientMove(uint64 serverConnectionHandlerID, anyID clientID, uint64 newChannelID, const char* password, const char* returnCode)
static PyObject * ts3func_requestClientMove(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	uint64 newChannelID;
	const char* password;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LhLss", &serverConnectionHandlerID, &clientID, &newChannelID, &password, &returnCode)){
		printf("Failed to parse args for function requestClientMove");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientMove(serverConnectionHandlerID, clientID, newChannelID, password, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientMove returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientVariables(uint64 serverConnectionHandlerID, anyID clientID, const char* returnCode)
static PyObject * ts3func_requestClientVariables(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhs", &serverConnectionHandlerID, &clientID, &returnCode)){
		printf("Failed to parse args for function requestClientVariables");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientVariables(serverConnectionHandlerID, clientID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientVariables returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientKickFromChannel(uint64 serverConnectionHandlerID, anyID clientID, const char* kickReason, const char* returnCode)
static PyObject * ts3func_requestClientKickFromChannel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* kickReason;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhss", &serverConnectionHandlerID, &clientID, &kickReason, &returnCode)){
		printf("Failed to parse args for function requestClientKickFromChannel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientKickFromChannel(serverConnectionHandlerID, clientID, kickReason, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientKickFromChannel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientKickFromServer(uint64 serverConnectionHandlerID, anyID clientID, const char* kickReason, const char* returnCode)
static PyObject * ts3func_requestClientKickFromServer(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* kickReason;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhss", &serverConnectionHandlerID, &clientID, &kickReason, &returnCode)){
		printf("Failed to parse args for function requestClientKickFromServer");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientKickFromServer(serverConnectionHandlerID, clientID, kickReason, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientKickFromServer returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelDelete(uint64 serverConnectionHandlerID, uint64 channelID, int force, const char* returnCode)
static PyObject * ts3func_requestChannelDelete(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	int force;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLis", &serverConnectionHandlerID, &channelID, &force, &returnCode)){
		printf("Failed to parse args for function requestChannelDelete");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelDelete(serverConnectionHandlerID, channelID, force, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelDelete returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelMove(uint64 serverConnectionHandlerID, uint64 channelID, uint64 newChannelParentID, uint64 newChannelOrder, const char* returnCode)
static PyObject * ts3func_requestChannelMove(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	uint64 newChannelParentID;
	uint64 newChannelOrder;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLLs", &serverConnectionHandlerID, &channelID, &newChannelParentID, &newChannelOrder, &returnCode)){
		printf("Failed to parse args for function requestChannelMove");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelMove(serverConnectionHandlerID, channelID, newChannelParentID, newChannelOrder, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelMove returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestSendPrivateTextMsg(uint64 serverConnectionHandlerID, const char* message, anyID targetClientID, const char* returnCode)
static PyObject * ts3func_requestSendPrivateTextMsg(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* message;
	anyID targetClientID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lshs", &serverConnectionHandlerID, &message, &targetClientID, &returnCode)){
		printf("Failed to parse args for function requestSendPrivateTextMsg");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestSendPrivateTextMsg(serverConnectionHandlerID, message, targetClientID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestSendPrivateTextMsg returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestSendChannelTextMsg(uint64 serverConnectionHandlerID, const char* message, uint64 targetChannelID, const char* returnCode)
static PyObject * ts3func_requestSendChannelTextMsg(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* message;
	uint64 targetChannelID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LsLs", &serverConnectionHandlerID, &message, &targetChannelID, &returnCode)){
		printf("Failed to parse args for function requestSendChannelTextMsg");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestSendChannelTextMsg(serverConnectionHandlerID, message, targetChannelID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestSendChannelTextMsg returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestSendServerTextMsg(uint64 serverConnectionHandlerID, const char* message, const char* returnCode)
static PyObject * ts3func_requestSendServerTextMsg(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* message;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &message, &returnCode)){
		printf("Failed to parse args for function requestSendServerTextMsg");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestSendServerTextMsg(serverConnectionHandlerID, message, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestSendServerTextMsg returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestConnectionInfo(uint64 serverConnectionHandlerID, anyID clientID, const char* returnCode)
static PyObject * ts3func_requestConnectionInfo(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhs", &serverConnectionHandlerID, &clientID, &returnCode)){
		printf("Failed to parse args for function requestConnectionInfo");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestConnectionInfo(serverConnectionHandlerID, clientID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestConnectionInfo returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientSetWhisperList(uint64 serverConnectionHandlerID, anyID clientID, const uint64* targetChannelIDArray, const anyID* targetClientIDArray, const char* returnCode)
static PyObject * ts3func_requestClientSetWhisperList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	PyObject* targetChannelIDArray;
	PyObject* targetClientIDArray;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LhOOs", &serverConnectionHandlerID, &clientID, &targetChannelIDArray, &targetClientIDArray, &returnCode)){
		printf("Failed to parse args for function requestClientSetWhisperList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64* targetChannelIDArray_c_array = new uint64[PyObject_Length(targetChannelIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(targetChannelIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] targetChannelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			targetChannelIDArray_c_array[i] = PyInt_AsUnsignedLongLongMask(item);
			if(PyErr_Occurred()){
				delete[] targetChannelIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] targetChannelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		anyID* targetClientIDArray_c_array = new anyID[PyObject_Length(targetClientIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(targetClientIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] targetClientIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			targetClientIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] targetClientIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] targetClientIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestClientSetWhisperList(serverConnectionHandlerID, clientID, targetChannelIDArray_c_array, targetClientIDArray_c_array, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientSetWhisperList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] targetChannelIDArray_c_array;
	delete[] targetClientIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelSubscribe(uint64 serverConnectionHandlerID, const uint64* channelIDArray, const char* returnCode)
static PyObject * ts3func_requestChannelSubscribe(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	PyObject* channelIDArray;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LOs", &serverConnectionHandlerID, &channelIDArray, &returnCode)){
		printf("Failed to parse args for function requestChannelSubscribe");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64* channelIDArray_c_array = new uint64[PyObject_Length(channelIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(channelIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] channelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			channelIDArray_c_array[i] = PyInt_AsUnsignedLongLongMask(item);
			if(PyErr_Occurred()){
				delete[] channelIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] channelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelSubscribe(serverConnectionHandlerID, channelIDArray_c_array, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelSubscribe returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] channelIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelSubscribeAll(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_requestChannelSubscribeAll(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function requestChannelSubscribeAll");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelSubscribeAll(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelSubscribeAll returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelUnsubscribe(uint64 serverConnectionHandlerID, const uint64* channelIDArray, const char* returnCode)
static PyObject * ts3func_requestChannelUnsubscribe(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	PyObject* channelIDArray;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LOs", &serverConnectionHandlerID, &channelIDArray, &returnCode)){
		printf("Failed to parse args for function requestChannelUnsubscribe");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64* channelIDArray_c_array = new uint64[PyObject_Length(channelIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(channelIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] channelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			channelIDArray_c_array[i] = PyInt_AsUnsignedLongLongMask(item);
			if(PyErr_Occurred()){
				delete[] channelIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] channelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelUnsubscribe(serverConnectionHandlerID, channelIDArray_c_array, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelUnsubscribe returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] channelIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelUnsubscribeAll(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_requestChannelUnsubscribeAll(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function requestChannelUnsubscribeAll");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelUnsubscribeAll(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelUnsubscribeAll returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelDescription(uint64 serverConnectionHandlerID, uint64 channelID, const char* returnCode)
static PyObject * ts3func_requestChannelDescription(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &channelID, &returnCode)){
		printf("Failed to parse args for function requestChannelDescription");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelDescription(serverConnectionHandlerID, channelID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelDescription returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestMuteClients(uint64 serverConnectionHandlerID, const anyID* clientIDArray, const char* returnCode)
static PyObject * ts3func_requestMuteClients(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	PyObject* clientIDArray;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LOs", &serverConnectionHandlerID, &clientIDArray, &returnCode)){
		printf("Failed to parse args for function requestMuteClients");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID* clientIDArray_c_array = new anyID[PyObject_Length(clientIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(clientIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] clientIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			clientIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] clientIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] clientIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestMuteClients(serverConnectionHandlerID, clientIDArray_c_array, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestMuteClients returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] clientIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestUnmuteClients(uint64 serverConnectionHandlerID, const anyID* clientIDArray, const char* returnCode)
static PyObject * ts3func_requestUnmuteClients(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	PyObject* clientIDArray;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LOs", &serverConnectionHandlerID, &clientIDArray, &returnCode)){
		printf("Failed to parse args for function requestUnmuteClients");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID* clientIDArray_c_array = new anyID[PyObject_Length(clientIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(clientIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] clientIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			clientIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] clientIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] clientIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestUnmuteClients(serverConnectionHandlerID, clientIDArray_c_array, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestUnmuteClients returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] clientIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestClientPoke(uint64 serverConnectionHandlerID, anyID clientID, const char* message, const char* returnCode)
static PyObject * ts3func_requestClientPoke(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* message;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhss", &serverConnectionHandlerID, &clientID, &message, &returnCode)){
		printf("Failed to parse args for function requestClientPoke");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientPoke(serverConnectionHandlerID, clientID, message, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientPoke returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientIDs(uint64 serverConnectionHandlerID, const char* clientUniqueIdentifier, const char* returnCode)
static PyObject * ts3func_requestClientIDs(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* clientUniqueIdentifier;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &clientUniqueIdentifier, &returnCode)){
		printf("Failed to parse args for function requestClientIDs");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientIDs(serverConnectionHandlerID, clientUniqueIdentifier, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientIDs returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int clientChatClosed(uint64 serverConnectionHandlerID, const char* clientUniqueIdentifier, anyID clientID, const char* returnCode)
static PyObject * ts3func_clientChatClosed(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* clientUniqueIdentifier;
	anyID clientID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lshs", &serverConnectionHandlerID, &clientUniqueIdentifier, &clientID, &returnCode)){
		printf("Failed to parse args for function clientChatClosed");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->clientChatClosed(serverConnectionHandlerID, clientUniqueIdentifier, clientID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call clientChatClosed returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int clientChatComposing(uint64 serverConnectionHandlerID, anyID clientID, const char* returnCode)
static PyObject * ts3func_clientChatComposing(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhs", &serverConnectionHandlerID, &clientID, &returnCode)){
		printf("Failed to parse args for function clientChatComposing");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->clientChatComposing(serverConnectionHandlerID, clientID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call clientChatComposing returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerTemporaryPasswordAdd(uint64 serverConnectionHandlerID, const char* password, const char* description, uint64 duration, uint64 targetChannelID, const char* targetChannelPW, const char* returnCode)
static PyObject * ts3func_requestServerTemporaryPasswordAdd(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* password;
	const char* description;
	uint64 duration;
	uint64 targetChannelID;
	const char* targetChannelPW;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LssLLss", &serverConnectionHandlerID, &password, &description, &duration, &targetChannelID, &targetChannelPW, &returnCode)){
		printf("Failed to parse args for function requestServerTemporaryPasswordAdd");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerTemporaryPasswordAdd(serverConnectionHandlerID, password, description, duration, targetChannelID, targetChannelPW, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerTemporaryPasswordAdd returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerTemporaryPasswordDel(uint64 serverConnectionHandlerID, const char* password, const char* returnCode)
static PyObject * ts3func_requestServerTemporaryPasswordDel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* password;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &password, &returnCode)){
		printf("Failed to parse args for function requestServerTemporaryPasswordDel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerTemporaryPasswordDel(serverConnectionHandlerID, password, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerTemporaryPasswordDel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerTemporaryPasswordList(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_requestServerTemporaryPasswordList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function requestServerTemporaryPasswordList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerTemporaryPasswordList(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerTemporaryPasswordList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getClientID(uint64 serverConnectionHandlerID, anyID* result)
static PyObject * ts3func_getClientID(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getClientID");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID result;
	// Function call
	unsigned int functionCallValue = functions->getClientID(serverConnectionHandlerID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientID returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("h", result);
	// Clean up
	return returnValue;
}

//unsigned int getClientSelfVariableAsInt(uint64 serverConnectionHandlerID, size_t flag, int* result)
static PyObject * ts3func_getClientSelfVariableAsInt(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ll", &serverConnectionHandlerID, &flag)){
		printf("Failed to parse args for function getClientSelfVariableAsInt");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->getClientSelfVariableAsInt(serverConnectionHandlerID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientSelfVariableAsInt returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getClientSelfVariableAsString(uint64 serverConnectionHandlerID, size_t flag, char** result)
static PyObject * ts3func_getClientSelfVariableAsString(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ll", &serverConnectionHandlerID, &flag)){
		printf("Failed to parse args for function getClientSelfVariableAsString");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getClientSelfVariableAsString(serverConnectionHandlerID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientSelfVariableAsString returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int setClientSelfVariableAsInt(uint64 serverConnectionHandlerID, size_t flag, int value)
static PyObject * ts3func_setClientSelfVariableAsInt(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	size_t flag;
	int value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lli", &serverConnectionHandlerID, &flag, &value)){
		printf("Failed to parse args for function setClientSelfVariableAsInt");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setClientSelfVariableAsInt(serverConnectionHandlerID, flag, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setClientSelfVariableAsInt returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int setClientSelfVariableAsString(uint64 serverConnectionHandlerID, size_t flag, const char* value)
static PyObject * ts3func_setClientSelfVariableAsString(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	size_t flag;
	const char* value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lls", &serverConnectionHandlerID, &flag, &value)){
		printf("Failed to parse args for function setClientSelfVariableAsString");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setClientSelfVariableAsString(serverConnectionHandlerID, flag, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setClientSelfVariableAsString returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int flushClientSelfUpdates(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_flushClientSelfUpdates(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function flushClientSelfUpdates");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->flushClientSelfUpdates(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call flushClientSelfUpdates returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getClientVariableAsInt(uint64 serverConnectionHandlerID, anyID clientID, size_t flag, int* result)
static PyObject * ts3func_getClientVariableAsInt(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhl", &serverConnectionHandlerID, &clientID, &flag)){
		printf("Failed to parse args for function getClientVariableAsInt");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->getClientVariableAsInt(serverConnectionHandlerID, clientID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientVariableAsInt returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getClientVariableAsUInt64(uint64 serverConnectionHandlerID, anyID clientID, size_t flag, uint64* result)
static PyObject * ts3func_getClientVariableAsUInt64(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhl", &serverConnectionHandlerID, &clientID, &flag)){
		printf("Failed to parse args for function getClientVariableAsUInt64");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getClientVariableAsUInt64(serverConnectionHandlerID, clientID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientVariableAsUInt64 returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int getClientVariableAsString(uint64 serverConnectionHandlerID, anyID clientID, size_t flag, char** result)
static PyObject * ts3func_getClientVariableAsString(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhl", &serverConnectionHandlerID, &clientID, &flag)){
		printf("Failed to parse args for function getClientVariableAsString");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getClientVariableAsString(serverConnectionHandlerID, clientID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientVariableAsString returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getClientList(uint64 serverConnectionHandlerID, anyID** result)
static PyObject * ts3func_getClientList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getClientList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID* result;
	// Function call
	unsigned int functionCallValue = functions->getClientList(serverConnectionHandlerID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != 0; ++i){count++;}
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != 0; ++i){
		PyList_SetItem(list, i, Py_BuildValue("h", result[i]));
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	return returnValue;
}

//unsigned int getChannelOfClient(uint64 serverConnectionHandlerID, anyID clientID, uint64* result)
static PyObject * ts3func_getChannelOfClient(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lh", &serverConnectionHandlerID, &clientID)){
		printf("Failed to parse args for function getChannelOfClient");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getChannelOfClient(serverConnectionHandlerID, clientID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelOfClient returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int getChannelVariableAsInt(uint64 serverConnectionHandlerID, uint64 channelID, size_t flag, int* result)
static PyObject * ts3func_getChannelVariableAsInt(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLl", &serverConnectionHandlerID, &channelID, &flag)){
		printf("Failed to parse args for function getChannelVariableAsInt");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->getChannelVariableAsInt(serverConnectionHandlerID, channelID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelVariableAsInt returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getChannelVariableAsUInt64(uint64 serverConnectionHandlerID, uint64 channelID, size_t flag, uint64* result)
static PyObject * ts3func_getChannelVariableAsUInt64(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLl", &serverConnectionHandlerID, &channelID, &flag)){
		printf("Failed to parse args for function getChannelVariableAsUInt64");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getChannelVariableAsUInt64(serverConnectionHandlerID, channelID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelVariableAsUInt64 returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int getChannelVariableAsString(uint64 serverConnectionHandlerID, uint64 channelID, size_t flag, char** result)
static PyObject * ts3func_getChannelVariableAsString(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLl", &serverConnectionHandlerID, &channelID, &flag)){
		printf("Failed to parse args for function getChannelVariableAsString");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getChannelVariableAsString(serverConnectionHandlerID, channelID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelVariableAsString returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getChannelIDFromChannelNames(uint64 serverConnectionHandlerID, char** channelNameArray, uint64* result)
static PyObject * ts3func_getChannelIDFromChannelNames(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getChannelIDFromChannelNames");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* channelNameArray;
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getChannelIDFromChannelNames(serverConnectionHandlerID, &channelNameArray, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelIDFromChannelNames returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("sL", channelNameArray, result);
	// Clean up
	functions->freeMemory(channelNameArray);
	return returnValue;
}

//unsigned int setChannelVariableAsInt(uint64 serverConnectionHandlerID, uint64 channelID, size_t flag, int value)
static PyObject * ts3func_setChannelVariableAsInt(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	int value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLli", &serverConnectionHandlerID, &channelID, &flag, &value)){
		printf("Failed to parse args for function setChannelVariableAsInt");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setChannelVariableAsInt(serverConnectionHandlerID, channelID, flag, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setChannelVariableAsInt returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int setChannelVariableAsUInt64(uint64 serverConnectionHandlerID, uint64 channelID, size_t flag, uint64 value)
static PyObject * ts3func_setChannelVariableAsUInt64(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	uint64 value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLlL", &serverConnectionHandlerID, &channelID, &flag, &value)){
		printf("Failed to parse args for function setChannelVariableAsUInt64");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setChannelVariableAsUInt64(serverConnectionHandlerID, channelID, flag, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setChannelVariableAsUInt64 returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int setChannelVariableAsString(uint64 serverConnectionHandlerID, uint64 channelID, size_t flag, const char* value)
static PyObject * ts3func_setChannelVariableAsString(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	size_t flag;
	const char* value;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLls", &serverConnectionHandlerID, &channelID, &flag, &value)){
		printf("Failed to parse args for function setChannelVariableAsString");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->setChannelVariableAsString(serverConnectionHandlerID, channelID, flag, value);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call setChannelVariableAsString returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int flushChannelUpdates(uint64 serverConnectionHandlerID, uint64 channelID, const char* returnCode)
static PyObject * ts3func_flushChannelUpdates(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &channelID, &returnCode)){
		printf("Failed to parse args for function flushChannelUpdates");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->flushChannelUpdates(serverConnectionHandlerID, channelID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call flushChannelUpdates returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int flushChannelCreation(uint64 serverConnectionHandlerID, uint64 channelParentID, const char* returnCode)
static PyObject * ts3func_flushChannelCreation(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelParentID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &channelParentID, &returnCode)){
		printf("Failed to parse args for function flushChannelCreation");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->flushChannelCreation(serverConnectionHandlerID, channelParentID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call flushChannelCreation returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getChannelList(uint64 serverConnectionHandlerID, uint64** result)
static PyObject * ts3func_getChannelList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getChannelList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64* result;
	// Function call
	unsigned int functionCallValue = functions->getChannelList(serverConnectionHandlerID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != 0; ++i){count++;}
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != 0; ++i){
		PyList_SetItem(list, i, Py_BuildValue("L", result[i]));
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	return returnValue;
}

//unsigned int getChannelClientList(uint64 serverConnectionHandlerID, uint64 channelID, anyID** result)
static PyObject * ts3func_getChannelClientList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LL", &serverConnectionHandlerID, &channelID)){
		printf("Failed to parse args for function getChannelClientList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID* result;
	// Function call
	unsigned int functionCallValue = functions->getChannelClientList(serverConnectionHandlerID, channelID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelClientList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != 0; ++i){count++;}
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != 0; ++i){
		PyList_SetItem(list, i, Py_BuildValue("h", result[i]));
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	return returnValue;
}

//unsigned int getParentChannelOfChannel(uint64 serverConnectionHandlerID, uint64 channelID, uint64* result)
static PyObject * ts3func_getParentChannelOfChannel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LL", &serverConnectionHandlerID, &channelID)){
		printf("Failed to parse args for function getParentChannelOfChannel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getParentChannelOfChannel(serverConnectionHandlerID, channelID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getParentChannelOfChannel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int getServerConnectionHandlerList(uint64** result)
static PyObject * ts3func_getServerConnectionHandlerList(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64* result;
	// Function call
	unsigned int functionCallValue = functions->getServerConnectionHandlerList(&result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getServerConnectionHandlerList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != 0; ++i){count++;}
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != 0; ++i){
		PyList_SetItem(list, i, Py_BuildValue("L", result[i]));
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("O", list);
	// Clean up
	Py_XDECREF(list);
	return returnValue;
}

//unsigned int getServerVariableAsInt(uint64 serverConnectionHandlerID, size_t flag, int* result)
static PyObject * ts3func_getServerVariableAsInt(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ll", &serverConnectionHandlerID, &flag)){
		printf("Failed to parse args for function getServerVariableAsInt");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->getServerVariableAsInt(serverConnectionHandlerID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getServerVariableAsInt returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getServerVariableAsUInt64(uint64 serverConnectionHandlerID, size_t flag, uint64* result)
static PyObject * ts3func_getServerVariableAsUInt64(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ll", &serverConnectionHandlerID, &flag)){
		printf("Failed to parse args for function getServerVariableAsUInt64");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getServerVariableAsUInt64(serverConnectionHandlerID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getServerVariableAsUInt64 returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int getServerVariableAsString(uint64 serverConnectionHandlerID, size_t flag, char** result)
static PyObject * ts3func_getServerVariableAsString(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ll", &serverConnectionHandlerID, &flag)){
		printf("Failed to parse args for function getServerVariableAsString");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getServerVariableAsString(serverConnectionHandlerID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getServerVariableAsString returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int requestServerVariables(uint64 serverConnectionHandlerID)
static PyObject * ts3func_requestServerVariables(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function requestServerVariables");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerVariables(serverConnectionHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerVariables returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getConnectionStatus(uint64 serverConnectionHandlerID, int* result)
static PyObject * ts3func_getConnectionStatus(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &serverConnectionHandlerID)){
		printf("Failed to parse args for function getConnectionStatus");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->getConnectionStatus(serverConnectionHandlerID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getConnectionStatus returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getConnectionVariableAsUInt64(uint64 serverConnectionHandlerID, anyID clientID, size_t flag, uint64* result)
static PyObject * ts3func_getConnectionVariableAsUInt64(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhl", &serverConnectionHandlerID, &clientID, &flag)){
		printf("Failed to parse args for function getConnectionVariableAsUInt64");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getConnectionVariableAsUInt64(serverConnectionHandlerID, clientID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getConnectionVariableAsUInt64 returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int getConnectionVariableAsDouble(uint64 serverConnectionHandlerID, anyID clientID, size_t flag, double* result)
static PyObject * ts3func_getConnectionVariableAsDouble(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhl", &serverConnectionHandlerID, &clientID, &flag)){
		printf("Failed to parse args for function getConnectionVariableAsDouble");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	double result;
	// Function call
	unsigned int functionCallValue = functions->getConnectionVariableAsDouble(serverConnectionHandlerID, clientID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getConnectionVariableAsDouble returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("d", result);
	// Clean up
	return returnValue;
}

//unsigned int getConnectionVariableAsString(uint64 serverConnectionHandlerID, anyID clientID, size_t flag, char** result)
static PyObject * ts3func_getConnectionVariableAsString(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	size_t flag;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhl", &serverConnectionHandlerID, &clientID, &flag)){
		printf("Failed to parse args for function getConnectionVariableAsString");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getConnectionVariableAsString(serverConnectionHandlerID, clientID, flag, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getConnectionVariableAsString returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int cleanUpConnectionInfo(uint64 serverConnectionHandlerID, anyID clientID)
static PyObject * ts3func_cleanUpConnectionInfo(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lh", &serverConnectionHandlerID, &clientID)){
		printf("Failed to parse args for function cleanUpConnectionInfo");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->cleanUpConnectionInfo(serverConnectionHandlerID, clientID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call cleanUpConnectionInfo returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientDBIDfromUID(uint64 serverConnectionHandlerID, const char* clientUniqueIdentifier, const char* returnCode)
static PyObject * ts3func_requestClientDBIDfromUID(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* clientUniqueIdentifier;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &clientUniqueIdentifier, &returnCode)){
		printf("Failed to parse args for function requestClientDBIDfromUID");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientDBIDfromUID(serverConnectionHandlerID, clientUniqueIdentifier, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientDBIDfromUID returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientNamefromUID(uint64 serverConnectionHandlerID, const char* clientUniqueIdentifier, const char* returnCode)
static PyObject * ts3func_requestClientNamefromUID(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* clientUniqueIdentifier;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &clientUniqueIdentifier, &returnCode)){
		printf("Failed to parse args for function requestClientNamefromUID");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientNamefromUID(serverConnectionHandlerID, clientUniqueIdentifier, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientNamefromUID returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientNamefromDBID(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestClientNamefromDBID(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &clientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestClientNamefromDBID");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientNamefromDBID(serverConnectionHandlerID, clientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientNamefromDBID returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientEditDescription(uint64 serverConnectionHandlerID, anyID clientID, const char* clientDescription, const char* returnCode)
static PyObject * ts3func_requestClientEditDescription(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	const char* clientDescription;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhss", &serverConnectionHandlerID, &clientID, &clientDescription, &returnCode)){
		printf("Failed to parse args for function requestClientEditDescription");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientEditDescription(serverConnectionHandlerID, clientID, clientDescription, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientEditDescription returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientSetIsTalker(uint64 serverConnectionHandlerID, anyID clientID, int isTalker, const char* returnCode)
static PyObject * ts3func_requestClientSetIsTalker(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	int isTalker;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhis", &serverConnectionHandlerID, &clientID, &isTalker, &returnCode)){
		printf("Failed to parse args for function requestClientSetIsTalker");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientSetIsTalker(serverConnectionHandlerID, clientID, isTalker, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientSetIsTalker returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestIsTalker(uint64 serverConnectionHandlerID, int isTalkerRequest, const char* isTalkerRequestMessage, const char* returnCode)
static PyObject * ts3func_requestIsTalker(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	int isTalkerRequest;
	const char* isTalkerRequestMessage;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Liss", &serverConnectionHandlerID, &isTalkerRequest, &isTalkerRequestMessage, &returnCode)){
		printf("Failed to parse args for function requestIsTalker");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestIsTalker(serverConnectionHandlerID, isTalkerRequest, isTalkerRequestMessage, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestIsTalker returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestSendClientQueryCommand(uint64 serverConnectionHandlerID, const char* command, const char* returnCode)
static PyObject * ts3func_requestSendClientQueryCommand(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* command;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &command, &returnCode)){
		printf("Failed to parse args for function requestSendClientQueryCommand");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestSendClientQueryCommand(serverConnectionHandlerID, command, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestSendClientQueryCommand returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getTransferFileName(anyID transferID, char** result)
static PyObject * ts3func_getTransferFileName(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getTransferFileName");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getTransferFileName(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getTransferFileName returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getTransferFilePath(anyID transferID, char** result)
static PyObject * ts3func_getTransferFilePath(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getTransferFilePath");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result;
	// Function call
	unsigned int functionCallValue = functions->getTransferFilePath(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getTransferFilePath returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int getTransferFileSize(anyID transferID, uint64* result)
static PyObject * ts3func_getTransferFileSize(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getTransferFileSize");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getTransferFileSize(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getTransferFileSize returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int getTransferFileSizeDone(anyID transferID, uint64* result)
static PyObject * ts3func_getTransferFileSizeDone(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getTransferFileSizeDone");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getTransferFileSizeDone(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getTransferFileSizeDone returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int isTransferSender(anyID transferID, int* result)
static PyObject * ts3func_isTransferSender(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function isTransferSender");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->isTransferSender(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call isTransferSender returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getTransferStatus(anyID transferID, int* result)
static PyObject * ts3func_getTransferStatus(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getTransferStatus");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->getTransferStatus(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getTransferStatus returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getCurrentTransferSpeed(anyID transferID, float* result)
static PyObject * ts3func_getCurrentTransferSpeed(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getCurrentTransferSpeed");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	float result;
	// Function call
	unsigned int functionCallValue = functions->getCurrentTransferSpeed(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCurrentTransferSpeed returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("f", result);
	// Clean up
	return returnValue;
}

//unsigned int getAverageTransferSpeed(anyID transferID, float* result)
static PyObject * ts3func_getAverageTransferSpeed(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getAverageTransferSpeed");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	float result;
	// Function call
	unsigned int functionCallValue = functions->getAverageTransferSpeed(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getAverageTransferSpeed returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("f", result);
	// Clean up
	return returnValue;
}

//unsigned int getTransferRunTime(anyID transferID, uint64* result)
static PyObject * ts3func_getTransferRunTime(PyObject *self, PyObject *args){
	// Variable Declaration
	anyID transferID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "h", &transferID)){
		printf("Failed to parse args for function getTransferRunTime");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 result;
	// Function call
	unsigned int functionCallValue = functions->getTransferRunTime(transferID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getTransferRunTime returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", result);
	// Clean up
	return returnValue;
}

//unsigned int sendFile(uint64 serverConnectionHandlerID, uint64 channelID, const char* channelPW, const char* file, int overwrite, int resume, const char* sourceDirectory, anyID* result, const char* returnCode)
static PyObject * ts3func_sendFile(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* file;
	int overwrite;
	int resume;
	const char* sourceDirectory;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLssiiss", &serverConnectionHandlerID, &channelID, &channelPW, &file, &overwrite, &resume, &sourceDirectory, &returnCode)){
		printf("Failed to parse args for function sendFile");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID result;
	// Function call
	unsigned int functionCallValue = functions->sendFile(serverConnectionHandlerID, channelID, channelPW, file, overwrite, resume, sourceDirectory, &result, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call sendFile returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("h", result);
	// Clean up
	return returnValue;
}

//unsigned int requestFile(uint64 serverConnectionHandlerID, uint64 channelID, const char* channelPW, const char* file, int overwrite, int resume, const char* destinationDirectory, anyID* result, const char* returnCode)
static PyObject * ts3func_requestFile(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* file;
	int overwrite;
	int resume;
	const char* destinationDirectory;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLssiiss", &serverConnectionHandlerID, &channelID, &channelPW, &file, &overwrite, &resume, &destinationDirectory, &returnCode)){
		printf("Failed to parse args for function requestFile");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID result;
	// Function call
	unsigned int functionCallValue = functions->requestFile(serverConnectionHandlerID, channelID, channelPW, file, overwrite, resume, destinationDirectory, &result, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestFile returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("h", result);
	// Clean up
	return returnValue;
}

//unsigned int haltTransfer(uint64 serverConnectionHandlerID, anyID transferID, int deleteUnfinishedFile, const char* returnCode)
static PyObject * ts3func_haltTransfer(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID transferID;
	int deleteUnfinishedFile;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lhis", &serverConnectionHandlerID, &transferID, &deleteUnfinishedFile, &returnCode)){
		printf("Failed to parse args for function haltTransfer");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->haltTransfer(serverConnectionHandlerID, transferID, deleteUnfinishedFile, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call haltTransfer returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestFileList(uint64 serverConnectionHandlerID, uint64 channelID, const char* channelPW, const char* path, const char* returnCode)
static PyObject * ts3func_requestFileList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* path;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLsss", &serverConnectionHandlerID, &channelID, &channelPW, &path, &returnCode)){
		printf("Failed to parse args for function requestFileList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestFileList(serverConnectionHandlerID, channelID, channelPW, path, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestFileList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestFileInfo(uint64 serverConnectionHandlerID, uint64 channelID, const char* channelPW, const char* file, const char* returnCode)
static PyObject * ts3func_requestFileInfo(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* file;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLsss", &serverConnectionHandlerID, &channelID, &channelPW, &file, &returnCode)){
		printf("Failed to parse args for function requestFileInfo");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestFileInfo(serverConnectionHandlerID, channelID, channelPW, file, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestFileInfo returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestDeleteFile(uint64 serverConnectionHandlerID, uint64 channelID, const char* channelPW, const char** file, const char* returnCode)
static PyObject * ts3func_requestDeleteFile(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	PyObject* file;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLsOs", &serverConnectionHandlerID, &channelID, &channelPW, &file, &returnCode)){
		printf("Failed to parse args for function requestDeleteFile");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	const char** file_c_array = new const char*[PyObject_Length(file)];
	
	{
		PyObject *iterator = PyObject_GetIter(file);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] file_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			file_c_array[i] = PyString_AsString(item);
			if(PyErr_Occurred()){
				delete[] file_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] file_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestDeleteFile(serverConnectionHandlerID, channelID, channelPW, file_c_array, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestDeleteFile returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] file_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestCreateDirectory(uint64 serverConnectionHandlerID, uint64 channelID, const char* channelPW, const char* directoryPath, const char* returnCode)
static PyObject * ts3func_requestCreateDirectory(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPW;
	const char* directoryPath;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLsss", &serverConnectionHandlerID, &channelID, &channelPW, &directoryPath, &returnCode)){
		printf("Failed to parse args for function requestCreateDirectory");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestCreateDirectory(serverConnectionHandlerID, channelID, channelPW, directoryPath, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestCreateDirectory returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestRenameFile(uint64 serverConnectionHandlerID, uint64 fromChannelID, const char* channelPW, uint64 toChannelID, const char* toChannelPW, const char* oldFile, const char* newFile, const char* returnCode)
static PyObject * ts3func_requestRenameFile(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 fromChannelID;
	const char* channelPW;
	uint64 toChannelID;
	const char* toChannelPW;
	const char* oldFile;
	const char* newFile;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLsLssss", &serverConnectionHandlerID, &fromChannelID, &channelPW, &toChannelID, &toChannelPW, &oldFile, &newFile, &returnCode)){
		printf("Failed to parse args for function requestRenameFile");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestRenameFile(serverConnectionHandlerID, fromChannelID, channelPW, toChannelID, toChannelPW, oldFile, newFile, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestRenameFile returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestMessageAdd(uint64 serverConnectionHandlerID, const char* toClientUID, const char* subject, const char* message, const char* returnCode)
static PyObject * ts3func_requestMessageAdd(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* toClientUID;
	const char* subject;
	const char* message;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lssss", &serverConnectionHandlerID, &toClientUID, &subject, &message, &returnCode)){
		printf("Failed to parse args for function requestMessageAdd");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestMessageAdd(serverConnectionHandlerID, toClientUID, subject, message, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestMessageAdd returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestMessageDel(uint64 serverConnectionHandlerID, uint64 messageID, const char* returnCode)
static PyObject * ts3func_requestMessageDel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 messageID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &messageID, &returnCode)){
		printf("Failed to parse args for function requestMessageDel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestMessageDel(serverConnectionHandlerID, messageID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestMessageDel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestMessageGet(uint64 serverConnectionHandlerID, uint64 messageID, const char* returnCode)
static PyObject * ts3func_requestMessageGet(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 messageID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &messageID, &returnCode)){
		printf("Failed to parse args for function requestMessageGet");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestMessageGet(serverConnectionHandlerID, messageID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestMessageGet returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestMessageList(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_requestMessageList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function requestMessageList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestMessageList(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestMessageList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestMessageUpdateFlag(uint64 serverConnectionHandlerID, uint64 messageID, int flag, const char* returnCode)
static PyObject * ts3func_requestMessageUpdateFlag(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 messageID;
	int flag;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLis", &serverConnectionHandlerID, &messageID, &flag, &returnCode)){
		printf("Failed to parse args for function requestMessageUpdateFlag");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestMessageUpdateFlag(serverConnectionHandlerID, messageID, flag, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestMessageUpdateFlag returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int verifyServerPassword(uint64 serverConnectionHandlerID, const char* serverPassword, const char* returnCode)
static PyObject * ts3func_verifyServerPassword(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* serverPassword;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandlerID, &serverPassword, &returnCode)){
		printf("Failed to parse args for function verifyServerPassword");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->verifyServerPassword(serverConnectionHandlerID, serverPassword, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call verifyServerPassword returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int verifyChannelPassword(uint64 serverConnectionHandlerID, uint64 channelID, const char* channelPassword, const char* returnCode)
static PyObject * ts3func_verifyChannelPassword(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* channelPassword;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLss", &serverConnectionHandlerID, &channelID, &channelPassword, &returnCode)){
		printf("Failed to parse args for function verifyChannelPassword");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->verifyChannelPassword(serverConnectionHandlerID, channelID, channelPassword, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call verifyChannelPassword returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int banclient(uint64 serverConnectionHandlerID, anyID clientID, uint64 timeInSeconds, const char* banReason, const char* returnCode)
static PyObject * ts3func_banclient(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	anyID clientID;
	uint64 timeInSeconds;
	const char* banReason;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LhLss", &serverConnectionHandlerID, &clientID, &timeInSeconds, &banReason, &returnCode)){
		printf("Failed to parse args for function banclient");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->banclient(serverConnectionHandlerID, clientID, timeInSeconds, banReason, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call banclient returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int banadd(uint64 serverConnectionHandlerID, const char* ipRegExp, const char* nameRegexp, const char* uniqueIdentity, uint64 timeInSeconds, const char* banReason, const char* returnCode)
static PyObject * ts3func_banadd(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* ipRegExp;
	const char* nameRegexp;
	const char* uniqueIdentity;
	uint64 timeInSeconds;
	const char* banReason;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LsssLss", &serverConnectionHandlerID, &ipRegExp, &nameRegexp, &uniqueIdentity, &timeInSeconds, &banReason, &returnCode)){
		printf("Failed to parse args for function banadd");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->banadd(serverConnectionHandlerID, ipRegExp, nameRegexp, uniqueIdentity, timeInSeconds, banReason, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call banadd returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int banclientdbid(uint64 serverConnectionHandlerID, uint64 clientDBID, uint64 timeInSeconds, const char* banReason, const char* returnCode)
static PyObject * ts3func_banclientdbid(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 clientDBID;
	uint64 timeInSeconds;
	const char* banReason;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLss", &serverConnectionHandlerID, &clientDBID, &timeInSeconds, &banReason, &returnCode)){
		printf("Failed to parse args for function banclientdbid");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->banclientdbid(serverConnectionHandlerID, clientDBID, timeInSeconds, banReason, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call banclientdbid returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int bandel(uint64 serverConnectionHandlerID, uint64 banID, const char* returnCode)
static PyObject * ts3func_bandel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 banID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &banID, &returnCode)){
		printf("Failed to parse args for function bandel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->bandel(serverConnectionHandlerID, banID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call bandel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int bandelall(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_bandelall(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function bandelall");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->bandelall(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call bandelall returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestBanList(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_requestBanList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function requestBanList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestBanList(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestBanList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestComplainAdd(uint64 serverConnectionHandlerID, uint64 targetClientDatabaseID, const char* complainReason, const char* returnCode)
static PyObject * ts3func_requestComplainAdd(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	const char* complainReason;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLss", &serverConnectionHandlerID, &targetClientDatabaseID, &complainReason, &returnCode)){
		printf("Failed to parse args for function requestComplainAdd");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestComplainAdd(serverConnectionHandlerID, targetClientDatabaseID, complainReason, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestComplainAdd returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestComplainDel(uint64 serverConnectionHandlerID, uint64 targetClientDatabaseID, uint64 fromClientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestComplainDel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	uint64 fromClientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLs", &serverConnectionHandlerID, &targetClientDatabaseID, &fromClientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestComplainDel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestComplainDel(serverConnectionHandlerID, targetClientDatabaseID, fromClientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestComplainDel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestComplainDelAll(uint64 serverConnectionHandlerID, uint64 targetClientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestComplainDelAll(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &targetClientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestComplainDelAll");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestComplainDelAll(serverConnectionHandlerID, targetClientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestComplainDelAll returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestComplainList(uint64 serverConnectionHandlerID, uint64 targetClientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestComplainList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 targetClientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &targetClientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestComplainList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestComplainList(serverConnectionHandlerID, targetClientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestComplainList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupList(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_requestServerGroupList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function requestServerGroupList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupList(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupAdd(uint64 serverConnectionHandlerID, const char* groupName, int groupType, const char* returnCode)
static PyObject * ts3func_requestServerGroupAdd(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* groupName;
	int groupType;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lsis", &serverConnectionHandlerID, &groupName, &groupType, &returnCode)){
		printf("Failed to parse args for function requestServerGroupAdd");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupAdd(serverConnectionHandlerID, groupName, groupType, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupAdd returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupDel(uint64 serverConnectionHandlerID, uint64 serverGroupID, int force, const char* returnCode)
static PyObject * ts3func_requestServerGroupDel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	int force;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLis", &serverConnectionHandlerID, &serverGroupID, &force, &returnCode)){
		printf("Failed to parse args for function requestServerGroupDel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupDel(serverConnectionHandlerID, serverGroupID, force, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupDel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupAddClient(uint64 serverConnectionHandlerID, uint64 serverGroupID, uint64 clientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestServerGroupAddClient(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	uint64 clientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLs", &serverConnectionHandlerID, &serverGroupID, &clientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestServerGroupAddClient");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupAddClient(serverConnectionHandlerID, serverGroupID, clientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupAddClient returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupDelClient(uint64 serverConnectionHandlerID, uint64 serverGroupID, uint64 clientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestServerGroupDelClient(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	uint64 clientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLs", &serverConnectionHandlerID, &serverGroupID, &clientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestServerGroupDelClient");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupDelClient(serverConnectionHandlerID, serverGroupID, clientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupDelClient returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupsByClientID(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestServerGroupsByClientID(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &clientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestServerGroupsByClientID");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupsByClientID(serverConnectionHandlerID, clientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupsByClientID returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupAddPerm(uint64 serverConnectionHandlerID, uint64 serverGroupID, int continueonerror, const unsigned int* permissionIDArray, const int* permissionValueArray, const int* permissionNegatedArray, const int* permissionSkipArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestServerGroupAddPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	int continueonerror;
	PyObject* permissionIDArray;
	PyObject* permissionValueArray;
	PyObject* permissionNegatedArray;
	PyObject* permissionSkipArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLiOOOOis", &serverConnectionHandlerID, &serverGroupID, &continueonerror, &permissionIDArray, &permissionValueArray, &permissionNegatedArray, &permissionSkipArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestServerGroupAddPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionValueArray_c_array = new int[PyObject_Length(permissionValueArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionValueArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionValueArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionValueArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionNegatedArray_c_array = new int[PyObject_Length(permissionNegatedArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionNegatedArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionNegatedArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionNegatedArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionNegatedArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionNegatedArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionSkipArray_c_array = new int[PyObject_Length(permissionSkipArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionSkipArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionSkipArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionSkipArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionSkipArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionSkipArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestServerGroupAddPerm(serverConnectionHandlerID, serverGroupID, continueonerror, permissionIDArray_c_array, permissionValueArray_c_array, permissionNegatedArray_c_array, permissionSkipArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupAddPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	delete[] permissionValueArray_c_array;
	delete[] permissionNegatedArray_c_array;
	delete[] permissionSkipArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupDelPerm(uint64 serverConnectionHandlerID, uint64 serverGroupID, int continueOnError, const unsigned int* permissionIDArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestServerGroupDelPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	int continueOnError;
	PyObject* permissionIDArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLiOis", &serverConnectionHandlerID, &serverGroupID, &continueOnError, &permissionIDArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestServerGroupDelPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestServerGroupDelPerm(serverConnectionHandlerID, serverGroupID, continueOnError, permissionIDArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupDelPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupPermList(uint64 serverConnectionHandlerID, uint64 serverGroupID, const char* returnCode)
static PyObject * ts3func_requestServerGroupPermList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &serverGroupID, &returnCode)){
		printf("Failed to parse args for function requestServerGroupPermList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupPermList(serverConnectionHandlerID, serverGroupID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupPermList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestServerGroupClientList(uint64 serverConnectionHandlerID, uint64 serverGroupID, int withNames, const char* returnCode)
static PyObject * ts3func_requestServerGroupClientList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 serverGroupID;
	int withNames;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLis", &serverConnectionHandlerID, &serverGroupID, &withNames, &returnCode)){
		printf("Failed to parse args for function requestServerGroupClientList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestServerGroupClientList(serverConnectionHandlerID, serverGroupID, withNames, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestServerGroupClientList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelGroupList(uint64 serverConnectionHandlerID, const char* returnCode)
static PyObject * ts3func_requestChannelGroupList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &returnCode)){
		printf("Failed to parse args for function requestChannelGroupList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelGroupList(serverConnectionHandlerID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelGroupList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelGroupAdd(uint64 serverConnectionHandlerID, const char* groupName, int groupType, const char* returnCode)
static PyObject * ts3func_requestChannelGroupAdd(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* groupName;
	int groupType;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lsis", &serverConnectionHandlerID, &groupName, &groupType, &returnCode)){
		printf("Failed to parse args for function requestChannelGroupAdd");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelGroupAdd(serverConnectionHandlerID, groupName, groupType, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelGroupAdd returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelGroupDel(uint64 serverConnectionHandlerID, uint64 channelGroupID, int force, const char* returnCode)
static PyObject * ts3func_requestChannelGroupDel(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelGroupID;
	int force;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLis", &serverConnectionHandlerID, &channelGroupID, &force, &returnCode)){
		printf("Failed to parse args for function requestChannelGroupDel");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelGroupDel(serverConnectionHandlerID, channelGroupID, force, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelGroupDel returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelGroupAddPerm(uint64 serverConnectionHandlerID, uint64 channelGroupID, int continueonerror, const unsigned int* permissionIDArray, const int* permissionValueArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestChannelGroupAddPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelGroupID;
	int continueonerror;
	PyObject* permissionIDArray;
	PyObject* permissionValueArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLiOOis", &serverConnectionHandlerID, &channelGroupID, &continueonerror, &permissionIDArray, &permissionValueArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestChannelGroupAddPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionValueArray_c_array = new int[PyObject_Length(permissionValueArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionValueArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionValueArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionValueArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelGroupAddPerm(serverConnectionHandlerID, channelGroupID, continueonerror, permissionIDArray_c_array, permissionValueArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelGroupAddPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	delete[] permissionValueArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelGroupDelPerm(uint64 serverConnectionHandlerID, uint64 channelGroupID, int continueOnError, const unsigned int* permissionIDArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestChannelGroupDelPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelGroupID;
	int continueOnError;
	PyObject* permissionIDArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLiOis", &serverConnectionHandlerID, &channelGroupID, &continueOnError, &permissionIDArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestChannelGroupDelPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelGroupDelPerm(serverConnectionHandlerID, channelGroupID, continueOnError, permissionIDArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelGroupDelPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelGroupPermList(uint64 serverConnectionHandlerID, uint64 channelGroupID, const char* returnCode)
static PyObject * ts3func_requestChannelGroupPermList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelGroupID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &channelGroupID, &returnCode)){
		printf("Failed to parse args for function requestChannelGroupPermList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelGroupPermList(serverConnectionHandlerID, channelGroupID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelGroupPermList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestSetClientChannelGroup(uint64 serverConnectionHandlerID, const uint64* channelGroupIDArray, const uint64* channelIDArray, const uint64* clientDatabaseIDArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestSetClientChannelGroup(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	PyObject* channelGroupIDArray;
	PyObject* channelIDArray;
	PyObject* clientDatabaseIDArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LOOOis", &serverConnectionHandlerID, &channelGroupIDArray, &channelIDArray, &clientDatabaseIDArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestSetClientChannelGroup");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64* channelGroupIDArray_c_array = new uint64[PyObject_Length(channelGroupIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(channelGroupIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] channelGroupIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			channelGroupIDArray_c_array[i] = PyInt_AsUnsignedLongLongMask(item);
			if(PyErr_Occurred()){
				delete[] channelGroupIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] channelGroupIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		uint64* channelIDArray_c_array = new uint64[PyObject_Length(channelIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(channelIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] channelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			channelIDArray_c_array[i] = PyInt_AsUnsignedLongLongMask(item);
			if(PyErr_Occurred()){
				delete[] channelIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] channelIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		uint64* clientDatabaseIDArray_c_array = new uint64[PyObject_Length(clientDatabaseIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(clientDatabaseIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] clientDatabaseIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			clientDatabaseIDArray_c_array[i] = PyInt_AsUnsignedLongLongMask(item);
			if(PyErr_Occurred()){
				delete[] clientDatabaseIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] clientDatabaseIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestSetClientChannelGroup(serverConnectionHandlerID, channelGroupIDArray_c_array, channelIDArray_c_array, clientDatabaseIDArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestSetClientChannelGroup returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] channelGroupIDArray_c_array;
	delete[] channelIDArray_c_array;
	delete[] clientDatabaseIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelAddPerm(uint64 serverConnectionHandlerID, uint64 channelID, const unsigned int* permissionIDArray, const int* permissionValueArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestChannelAddPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	PyObject* permissionIDArray;
	PyObject* permissionValueArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLOOis", &serverConnectionHandlerID, &channelID, &permissionIDArray, &permissionValueArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestChannelAddPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionValueArray_c_array = new int[PyObject_Length(permissionValueArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionValueArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionValueArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionValueArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelAddPerm(serverConnectionHandlerID, channelID, permissionIDArray_c_array, permissionValueArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelAddPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	delete[] permissionValueArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelDelPerm(uint64 serverConnectionHandlerID, uint64 channelID, const unsigned int* permissionIDArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestChannelDelPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	PyObject* permissionIDArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLOis", &serverConnectionHandlerID, &channelID, &permissionIDArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestChannelDelPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelDelPerm(serverConnectionHandlerID, channelID, permissionIDArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelDelPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelPermList(uint64 serverConnectionHandlerID, uint64 channelID, const char* returnCode)
static PyObject * ts3func_requestChannelPermList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &channelID, &returnCode)){
		printf("Failed to parse args for function requestChannelPermList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelPermList(serverConnectionHandlerID, channelID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelPermList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestClientAddPerm(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, const unsigned int* permissionIDArray, const int* permissionValueArray, const int* permissionSkipArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestClientAddPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	PyObject* permissionIDArray;
	PyObject* permissionValueArray;
	PyObject* permissionSkipArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLOOOis", &serverConnectionHandlerID, &clientDatabaseID, &permissionIDArray, &permissionValueArray, &permissionSkipArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestClientAddPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionValueArray_c_array = new int[PyObject_Length(permissionValueArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionValueArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionValueArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionValueArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionSkipArray_c_array = new int[PyObject_Length(permissionSkipArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionSkipArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionSkipArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionSkipArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionSkipArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionSkipArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestClientAddPerm(serverConnectionHandlerID, clientDatabaseID, permissionIDArray_c_array, permissionValueArray_c_array, permissionSkipArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientAddPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	delete[] permissionValueArray_c_array;
	delete[] permissionSkipArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestClientDelPerm(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, const unsigned int* permissionIDArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestClientDelPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	PyObject* permissionIDArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLOis", &serverConnectionHandlerID, &clientDatabaseID, &permissionIDArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestClientDelPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestClientDelPerm(serverConnectionHandlerID, clientDatabaseID, permissionIDArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientDelPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestClientPermList(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestClientPermList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 clientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLs", &serverConnectionHandlerID, &clientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestClientPermList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestClientPermList(serverConnectionHandlerID, clientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestClientPermList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestChannelClientAddPerm(uint64 serverConnectionHandlerID, uint64 channelID, uint64 clientDatabaseID, const unsigned int* permissionIDArray, const int* permissionValueArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestChannelClientAddPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	uint64 clientDatabaseID;
	PyObject* permissionIDArray;
	PyObject* permissionValueArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLOOis", &serverConnectionHandlerID, &channelID, &clientDatabaseID, &permissionIDArray, &permissionValueArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestChannelClientAddPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		int* permissionValueArray_c_array = new int[PyObject_Length(permissionValueArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionValueArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionValueArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionValueArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionValueArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelClientAddPerm(serverConnectionHandlerID, channelID, clientDatabaseID, permissionIDArray_c_array, permissionValueArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelClientAddPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	delete[] permissionValueArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelClientDelPerm(uint64 serverConnectionHandlerID, uint64 channelID, uint64 clientDatabaseID, const unsigned int* permissionIDArray, int arraySize, const char* returnCode)
static PyObject * ts3func_requestChannelClientDelPerm(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	uint64 clientDatabaseID;
	PyObject* permissionIDArray;
	int arraySize;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLOis", &serverConnectionHandlerID, &channelID, &clientDatabaseID, &permissionIDArray, &arraySize, &returnCode)){
		printf("Failed to parse args for function requestChannelClientDelPerm");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int* permissionIDArray_c_array = new unsigned int[PyObject_Length(permissionIDArray)];
	
	{
		PyObject *iterator = PyObject_GetIter(permissionIDArray);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			permissionIDArray_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] permissionIDArray_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] permissionIDArray_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	unsigned int functionCallValue = functions->requestChannelClientDelPerm(serverConnectionHandlerID, channelID, clientDatabaseID, permissionIDArray_c_array, arraySize, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelClientDelPerm returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	delete[] permissionIDArray_c_array;
	Py_RETURN_NONE;
}

//unsigned int requestChannelClientPermList(uint64 serverConnectionHandlerID, uint64 channelID, uint64 clientDatabaseID, const char* returnCode)
static PyObject * ts3func_requestChannelClientPermList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	uint64 channelID;
	uint64 clientDatabaseID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLs", &serverConnectionHandlerID, &channelID, &clientDatabaseID, &returnCode)){
		printf("Failed to parse args for function requestChannelClientPermList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestChannelClientPermList(serverConnectionHandlerID, channelID, clientDatabaseID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestChannelClientPermList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int privilegeKeyUse(uint64 serverConnectionHandler, const char* tokenKey, const char* returnCode)
static PyObject * ts3func_privilegeKeyUse(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandler;
	const char* tokenKey;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lss", &serverConnectionHandler, &tokenKey, &returnCode)){
		printf("Failed to parse args for function privilegeKeyUse");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->privilegeKeyUse(serverConnectionHandler, tokenKey, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call privilegeKeyUse returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestPermissionList(uint64 serverConnectionHandler, const char* returnCode)
static PyObject * ts3func_requestPermissionList(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandler;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandler, &returnCode)){
		printf("Failed to parse args for function requestPermissionList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestPermissionList(serverConnectionHandler, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestPermissionList returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int requestPermissionOverview(uint64 serverConnectionHandler, uint64 clientDBID, uint64 channelID, const char* returnCode)
static PyObject * ts3func_requestPermissionOverview(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandler;
	uint64 clientDBID;
	uint64 channelID;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LLLs", &serverConnectionHandler, &clientDBID, &channelID, &returnCode)){
		printf("Failed to parse args for function requestPermissionOverview");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestPermissionOverview(serverConnectionHandler, clientDBID, channelID, returnCode);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestPermissionOverview returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int clientPropertyStringToFlag(const char* clientPropertyString, size_t* resultFlag)
static PyObject * ts3func_clientPropertyStringToFlag(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* clientPropertyString;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &clientPropertyString)){
		printf("Failed to parse args for function clientPropertyStringToFlag");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	size_t resultFlag;
	// Function call
	unsigned int functionCallValue = functions->clientPropertyStringToFlag(clientPropertyString, &resultFlag);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call clientPropertyStringToFlag returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("l", resultFlag);
	// Clean up
	return returnValue;
}

//unsigned int channelPropertyStringToFlag(const char* channelPropertyString, size_t* resultFlag)
static PyObject * ts3func_channelPropertyStringToFlag(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* channelPropertyString;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &channelPropertyString)){
		printf("Failed to parse args for function channelPropertyStringToFlag");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	size_t resultFlag;
	// Function call
	unsigned int functionCallValue = functions->channelPropertyStringToFlag(channelPropertyString, &resultFlag);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call channelPropertyStringToFlag returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("l", resultFlag);
	// Clean up
	return returnValue;
}

//unsigned int serverPropertyStringToFlag(const char* serverPropertyString, size_t* resultFlag)
static PyObject * ts3func_serverPropertyStringToFlag(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* serverPropertyString;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &serverPropertyString)){
		printf("Failed to parse args for function serverPropertyStringToFlag");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	size_t resultFlag;
	// Function call
	unsigned int functionCallValue = functions->serverPropertyStringToFlag(serverPropertyString, &resultFlag);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call serverPropertyStringToFlag returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("l", resultFlag);
	// Clean up
	return returnValue;
}

//void getAppPath(char* path, size_t maxLen)
static PyObject * ts3func_getAppPath(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* path = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	functions->getAppPath(path, TS3_STRING_BUFFER_LEN);
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", path);
	// Clean up
	delete[] path;
	return returnValue;
}

//void getResourcesPath(char* path, size_t maxLen)
static PyObject * ts3func_getResourcesPath(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* path = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	functions->getResourcesPath(path, TS3_STRING_BUFFER_LEN);
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", path);
	// Clean up
	delete[] path;
	return returnValue;
}

//void getConfigPath(char* path, size_t maxLen)
static PyObject * ts3func_getConfigPath(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* path = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	functions->getConfigPath(path, TS3_STRING_BUFFER_LEN);
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", path);
	// Clean up
	delete[] path;
	return returnValue;
}

//void getPluginPath(char* path, size_t maxLen)
static PyObject * ts3func_getPluginPath(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* path = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	functions->getPluginPath(path, TS3_STRING_BUFFER_LEN);
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", path);
	// Clean up
	delete[] path;
	return returnValue;
}

//uint64 getCurrentServerConnectionHandlerID()
static PyObject * ts3func_getCurrentServerConnectionHandlerID(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->getCurrentServerConnectionHandlerID();
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getCurrentServerConnectionHandlerID returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//void printMessage(uint64 serverConnectionHandlerID, const char* message, enum PluginMessageTarget messageTarget)
static PyObject * ts3func_printMessage(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* message;
	enum PluginMessageTarget messageTarget;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lsi", &serverConnectionHandlerID, &message, &messageTarget)){
		printf("Failed to parse args for function printMessage");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	functions->printMessage(serverConnectionHandlerID, message, messageTarget);
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//void printMessageToCurrentTab(const char* message)
static PyObject * ts3func_printMessageToCurrentTab(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* message;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &message)){
		printf("Failed to parse args for function printMessageToCurrentTab");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	functions->printMessageToCurrentTab(message);
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//void urlsToBB(const char* text, char* result, size_t maxLen)
static PyObject * ts3func_urlsToBB(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* text;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &text)){
		printf("Failed to parse args for function urlsToBB");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	functions->urlsToBB(text, result, TS3_STRING_BUFFER_LEN);
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	delete[] result;
	return returnValue;
}

//void sendPluginCommand(uint64 serverConnectionHandlerID, const char* pluginID, const char* command, int targetMode, const anyID* targetIDs, const char* returnCode)
static PyObject * ts3func_sendPluginCommand(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* pluginID;
	const char* command;
	int targetMode;
	PyObject* targetIDs;
	const char* returnCode;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LssiOs", &serverConnectionHandlerID, &pluginID, &command, &targetMode, &targetIDs, &returnCode)){
		printf("Failed to parse args for function sendPluginCommand");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	anyID* targetIDs_c_array = new anyID[PyObject_Length(targetIDs)];
	
	{
		PyObject *iterator = PyObject_GetIter(targetIDs);
		PyObject *item = NULL;
		#define CLEANUP() do{ \
			Py_XDECREF(iterator); \
			Py_XDECREF(item); \
			} while(0)
		
		int i = 0;
		
		if (iterator == NULL) {
			/* propagate error */
			delete[] targetIDs_c_array;
			CLEANUP();
			return NULL;
		}
		while ((item = PyIter_Next(iterator)) != NULL) {
			targetIDs_c_array[i] = PyInt_AsLong(item);
			if(PyErr_Occurred()){
				delete[] targetIDs_c_array;
				CLEANUP();
				return NULL;
			}
			i++;
			Py_DECREF(item);
		}
		if (PyErr_Occurred()) {
			delete[] targetIDs_c_array;
			CLEANUP();
			return NULL;
		}
		CLEANUP();
		#undef CLEANUP
	}
		// Function call
	functions->sendPluginCommand(serverConnectionHandlerID, pluginID, command, targetMode, targetIDs_c_array, returnCode);
	// Build return value
	// Clean up
	delete[] targetIDs_c_array;
	Py_RETURN_NONE;
}

//void getDirectories(const char* path, char* result, size_t maxLen)
static PyObject * ts3func_getDirectories(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* path;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &path)){
		printf("Failed to parse args for function getDirectories");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	functions->getDirectories(path, result, TS3_STRING_BUFFER_LEN);
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	delete[] result;
	return returnValue;
}

//unsigned int getServerConnectInfo(uint64 scHandlerID, char* host, unsigned short* port, char* password, size_t maxLen)
static PyObject * ts3func_getServerConnectInfo(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &scHandlerID)){
		printf("Failed to parse args for function getServerConnectInfo");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* host = new char[TS3_STRING_BUFFER_LEN];
	unsigned short port;
	char* password = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	unsigned int functionCallValue = functions->getServerConnectInfo(scHandlerID, host, &port, password, TS3_STRING_BUFFER_LEN);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getServerConnectInfo returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("sjs", host, port, password);
	// Clean up
	delete[] host;
	delete[] password;
	return returnValue;
}

//unsigned int getChannelConnectInfo(uint64 scHandlerID, uint64 channelID, char* path, char* password, size_t maxLen)
static PyObject * ts3func_getChannelConnectInfo(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	uint64 channelID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LL", &scHandlerID, &channelID)){
		printf("Failed to parse args for function getChannelConnectInfo");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* path = new char[TS3_STRING_BUFFER_LEN];
	char* password = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	unsigned int functionCallValue = functions->getChannelConnectInfo(scHandlerID, channelID, path, password, TS3_STRING_BUFFER_LEN);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getChannelConnectInfo returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("ss", path, password);
	// Clean up
	delete[] path;
	delete[] password;
	return returnValue;
}

//void createReturnCode(const char* pluginID, char* returnCode, size_t maxLen)
static PyObject * ts3func_createReturnCode(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* pluginID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "s", &pluginID)){
		printf("Failed to parse args for function createReturnCode");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* returnCode = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	functions->createReturnCode(pluginID, returnCode, TS3_STRING_BUFFER_LEN);
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", returnCode);
	// Clean up
	delete[] returnCode;
	return returnValue;
}

//unsigned int requestInfoUpdate(uint64 scHandlerID, enum PluginItemType itemType, uint64 itemID)
static PyObject * ts3func_requestInfoUpdate(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	enum PluginItemType itemType;
	uint64 itemID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "LiL", &scHandlerID, &itemType, &itemID)){
		printf("Failed to parse args for function requestInfoUpdate");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->requestInfoUpdate(scHandlerID, itemType, itemID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call requestInfoUpdate returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//uint64 getServerVersion(uint64 scHandlerID)
static PyObject * ts3func_getServerVersion(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "L", &scHandlerID)){
		printf("Failed to parse args for function getServerVersion");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->getServerVersion(scHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getServerVersion returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int isWhispering(uint64 scHandlerID, anyID clientID, int* result)
static PyObject * ts3func_isWhispering(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	anyID clientID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lh", &scHandlerID, &clientID)){
		printf("Failed to parse args for function isWhispering");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->isWhispering(scHandlerID, clientID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call isWhispering returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int isReceivingWhisper(uint64 scHandlerID, anyID clientID, int* result)
static PyObject * ts3func_isReceivingWhisper(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	anyID clientID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lh", &scHandlerID, &clientID)){
		printf("Failed to parse args for function isReceivingWhisper");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->isReceivingWhisper(scHandlerID, clientID, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call isReceivingWhisper returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getAvatar(uint64 scHandlerID, anyID clientID, char* result, size_t maxLen)
static PyObject * ts3func_getAvatar(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	anyID clientID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lh", &scHandlerID, &clientID)){
		printf("Failed to parse args for function getAvatar");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	unsigned int functionCallValue = functions->getAvatar(scHandlerID, clientID, result, TS3_STRING_BUFFER_LEN);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getAvatar returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	delete[] result;
	return returnValue;
}

//void setPluginMenuEnabled(const char* pluginID, int menuID, int enabled)
static PyObject * ts3func_setPluginMenuEnabled(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* pluginID;
	int menuID;
	int enabled;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "sii", &pluginID, &menuID, &enabled)){
		printf("Failed to parse args for function setPluginMenuEnabled");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	functions->setPluginMenuEnabled(pluginID, menuID, enabled);
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//void showHotkeySetup()
static PyObject * ts3func_showHotkeySetup(PyObject *self, PyObject *args){
	// Variable Declaration
	// Parse Tuple Call
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	functions->showHotkeySetup();
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getClientDisplayName(uint64 scHandlerID, anyID clientID, char* result, size_t maxLen)
static PyObject * ts3func_getClientDisplayName(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 scHandlerID;
	anyID clientID;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Lh", &scHandlerID, &clientID)){
		printf("Failed to parse args for function getClientDisplayName");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	char* result = new char[TS3_STRING_BUFFER_LEN];
	// Function call
	unsigned int functionCallValue = functions->getClientDisplayName(scHandlerID, clientID, result, TS3_STRING_BUFFER_LEN);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientDisplayName returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("s", result);
	// Clean up
	delete[] result;
	return returnValue;
}

//unsigned int getProfileList(enum PluginGuiProfile profile, int* defaultProfileIdx, char*** result)
static PyObject * ts3func_getProfileList(PyObject *self, PyObject *args){
	// Variable Declaration
	enum PluginGuiProfile profile;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "i", &profile)){
		printf("Failed to parse args for function getProfileList");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int defaultProfileIdx;
	char** result;
	// Function call
	unsigned int functionCallValue = functions->getProfileList(profile, &defaultProfileIdx, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getProfileList returned error code:%i", functionCallValue);
		return NULL;
	}
	int count = 0;
	for(int i = 0; result[i] != NULL; ++i){ count++; }
	PyObject* list = PyList_New(count);
	for(int i = 0; result[i] != NULL; ++i){
		PyList_SetItem(list, i, Py_BuildValue("s", result[i]));
		functions->freeMemory(result[i]);
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("iO", defaultProfileIdx, list);
	// Clean up
	Py_XDECREF(list);
	functions->freeMemory(result);
	return returnValue;
}

//unsigned int guiConnect(enum PluginConnectTab connectTab, const char* serverLabel, const char* serverAddress, const char* serverPassword, const char* nickname, const char* channel, const char* channelPassword, const char* captureProfile, const char* playbackProfile, const char* hotkeyProfile, const char* soundProfile, const char* userIdentity, const char* oneTimeKey, const char* phoneticName, uint64* scHandlerID)
static PyObject * ts3func_guiConnect(PyObject *self, PyObject *args){
	// Variable Declaration
	enum PluginConnectTab connectTab;
	const char* serverLabel;
	const char* serverAddress;
	const char* serverPassword;
	const char* nickname;
	const char* channel;
	const char* channelPassword;
	const char* captureProfile;
	const char* playbackProfile;
	const char* hotkeyProfile;
	const char* soundProfile;
	const char* userIdentity;
	const char* oneTimeKey;
	const char* phoneticName;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "isssssssssssss", &connectTab, &serverLabel, &serverAddress, &serverPassword, &nickname, &channel, &channelPassword, &captureProfile, &playbackProfile, &hotkeyProfile, &soundProfile, &userIdentity, &oneTimeKey, &phoneticName)){
		printf("Failed to parse args for function guiConnect");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 scHandlerID;
	// Function call
	unsigned int functionCallValue = functions->guiConnect(connectTab, serverLabel, serverAddress, serverPassword, nickname, channel, channelPassword, captureProfile, playbackProfile, hotkeyProfile, soundProfile, userIdentity, oneTimeKey, phoneticName, &scHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call guiConnect returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", scHandlerID);
	// Clean up
	return returnValue;
}

//unsigned int guiConnectBookmark(enum PluginConnectTab connectTab, const char* bookmarkuuid, uint64* scHandlerID)
static PyObject * ts3func_guiConnectBookmark(PyObject *self, PyObject *args){
	// Variable Declaration
	enum PluginConnectTab connectTab;
	const char* bookmarkuuid;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "is", &connectTab, &bookmarkuuid)){
		printf("Failed to parse args for function guiConnectBookmark");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	uint64 scHandlerID;
	// Function call
	unsigned int functionCallValue = functions->guiConnectBookmark(connectTab, bookmarkuuid, &scHandlerID);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call guiConnectBookmark returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("L", scHandlerID);
	// Clean up
	return returnValue;
}

//unsigned int createBookmark(const char* bookmarkuuid, const char* serverLabel, const char* serverAddress, const char* serverPassword, const char* nickname, const char* channel, const char* channelPassword, const char* captureProfile, const char* playbackProfile, const char* hotkeyProfile, const char* soundProfile, const char* uniqueUserId, const char* oneTimeKey, const char* phoneticName)
static PyObject * ts3func_createBookmark(PyObject *self, PyObject *args){
	// Variable Declaration
	const char* bookmarkuuid;
	const char* serverLabel;
	const char* serverAddress;
	const char* serverPassword;
	const char* nickname;
	const char* channel;
	const char* channelPassword;
	const char* captureProfile;
	const char* playbackProfile;
	const char* hotkeyProfile;
	const char* soundProfile;
	const char* uniqueUserId;
	const char* oneTimeKey;
	const char* phoneticName;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "ssssssssssssss", &bookmarkuuid, &serverLabel, &serverAddress, &serverPassword, &nickname, &channel, &channelPassword, &captureProfile, &playbackProfile, &hotkeyProfile, &soundProfile, &uniqueUserId, &oneTimeKey, &phoneticName)){
		printf("Failed to parse args for function createBookmark");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	// Function call
	unsigned int functionCallValue = functions->createBookmark(bookmarkuuid, serverLabel, serverAddress, serverPassword, nickname, channel, channelPassword, captureProfile, playbackProfile, hotkeyProfile, soundProfile, uniqueUserId, oneTimeKey, phoneticName);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call createBookmark returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	// Clean up
	Py_RETURN_NONE;
}

//unsigned int getPermissionIDByName(uint64 serverConnectionHandlerID, const char* permissionName, unsigned int* result)
static PyObject * ts3func_getPermissionIDByName(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* permissionName;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &permissionName)){
		printf("Failed to parse args for function getPermissionIDByName");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	unsigned int result;
	// Function call
	unsigned int functionCallValue = functions->getPermissionIDByName(serverConnectionHandlerID, permissionName, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getPermissionIDByName returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

//unsigned int getClientNeededPermission(uint64 serverConnectionHandlerID, const char* permissionName, int* result)
static PyObject * ts3func_getClientNeededPermission(PyObject *self, PyObject *args){
	// Variable Declaration
	uint64 serverConnectionHandlerID;
	const char* permissionName;
	// Parse Tuple Call
	
	if(!PyArg_ParseTuple(args, "Ls", &serverConnectionHandlerID, &permissionName)){
		printf("Failed to parse args for function getClientNeededPermission");
		return NULL;
	}
	struct TS3Functions * functions = getTS3FunctionPointers();
	// Before Function Call
	int result;
	// Function call
	unsigned int functionCallValue = functions->getClientNeededPermission(serverConnectionHandlerID, permissionName, &result);
	if(functionCallValue != ERROR_ok){
		PyErr_Format(PyExc_Exception, "Function call getClientNeededPermission returned error code:%i", functionCallValue);
		return NULL;
	}
	// Build return value
	PyObject * returnValue = Py_BuildValue("i", result);
	// Clean up
	return returnValue;
}

static PyMethodDef TS3FunctionsMethods[] = {	{"getClientLibVersion", ts3func_getClientLibVersion, METH_VARARGS,""},
	{"getClientLibVersionNumber", ts3func_getClientLibVersionNumber, METH_VARARGS,""},
	{"spawnNewServerConnectionHandler", ts3func_spawnNewServerConnectionHandler, METH_VARARGS,""},
	{"destroyServerConnectionHandler", ts3func_destroyServerConnectionHandler, METH_VARARGS,""},
	{"getErrorMessage", ts3func_getErrorMessage, METH_VARARGS,""},
	{"logMessage", ts3func_logMessage, METH_VARARGS,""},
	{"getPlaybackDeviceList", ts3func_getPlaybackDeviceList, METH_VARARGS,""},
	{"getPlaybackModeList", ts3func_getPlaybackModeList, METH_VARARGS,""},
	{"getCaptureDeviceList", ts3func_getCaptureDeviceList, METH_VARARGS,""},
	{"getCaptureModeList", ts3func_getCaptureModeList, METH_VARARGS,""},
	{"getDefaultPlaybackDevice", ts3func_getDefaultPlaybackDevice, METH_VARARGS,""},
	{"getDefaultPlayBackMode", ts3func_getDefaultPlayBackMode, METH_VARARGS,""},
	{"getDefaultCaptureDevice", ts3func_getDefaultCaptureDevice, METH_VARARGS,""},
	{"getDefaultCaptureMode", ts3func_getDefaultCaptureMode, METH_VARARGS,""},
	{"openPlaybackDevice", ts3func_openPlaybackDevice, METH_VARARGS,""},
	{"openCaptureDevice", ts3func_openCaptureDevice, METH_VARARGS,""},
	{"getCurrentPlaybackDeviceName", ts3func_getCurrentPlaybackDeviceName, METH_VARARGS,""},
	{"getCurrentPlayBackMode", ts3func_getCurrentPlayBackMode, METH_VARARGS,""},
	{"getCurrentCaptureDeviceName", ts3func_getCurrentCaptureDeviceName, METH_VARARGS,""},
	{"getCurrentCaptureMode", ts3func_getCurrentCaptureMode, METH_VARARGS,""},
	{"initiateGracefulPlaybackShutdown", ts3func_initiateGracefulPlaybackShutdown, METH_VARARGS,""},
	{"closePlaybackDevice", ts3func_closePlaybackDevice, METH_VARARGS,""},
	{"closeCaptureDevice", ts3func_closeCaptureDevice, METH_VARARGS,""},
	{"activateCaptureDevice", ts3func_activateCaptureDevice, METH_VARARGS,""},
	{"playWaveFileHandle", ts3func_playWaveFileHandle, METH_VARARGS,""},
	{"pauseWaveFileHandle", ts3func_pauseWaveFileHandle, METH_VARARGS,""},
	{"closeWaveFileHandle", ts3func_closeWaveFileHandle, METH_VARARGS,""},
	{"playWaveFile", ts3func_playWaveFile, METH_VARARGS,""},
	{"registerCustomDevice", ts3func_registerCustomDevice, METH_VARARGS,""},
	{"unregisterCustomDevice", ts3func_unregisterCustomDevice, METH_VARARGS,""},
	{"processCustomCaptureData", ts3func_processCustomCaptureData, METH_VARARGS,""},
	{"acquireCustomPlaybackData", ts3func_acquireCustomPlaybackData, METH_VARARGS,""},
	{"getPreProcessorInfoValueFloat", ts3func_getPreProcessorInfoValueFloat, METH_VARARGS,""},
	{"getPreProcessorConfigValue", ts3func_getPreProcessorConfigValue, METH_VARARGS,""},
	{"setPreProcessorConfigValue", ts3func_setPreProcessorConfigValue, METH_VARARGS,""},
	{"getEncodeConfigValue", ts3func_getEncodeConfigValue, METH_VARARGS,""},
	{"getPlaybackConfigValueAsFloat", ts3func_getPlaybackConfigValueAsFloat, METH_VARARGS,""},
	{"setPlaybackConfigValue", ts3func_setPlaybackConfigValue, METH_VARARGS,""},
	{"setClientVolumeModifier", ts3func_setClientVolumeModifier, METH_VARARGS,""},
	{"startVoiceRecording", ts3func_startVoiceRecording, METH_VARARGS,""},
	{"stopVoiceRecording", ts3func_stopVoiceRecording, METH_VARARGS,""},
	{"systemset3DListenerAttributes", ts3func_systemset3DListenerAttributes, METH_VARARGS,""},
	{"set3DWaveAttributes", ts3func_set3DWaveAttributes, METH_VARARGS,""},
	{"systemset3DSettings", ts3func_systemset3DSettings, METH_VARARGS,""},
	{"channelset3DAttributes", ts3func_channelset3DAttributes, METH_VARARGS,""},
	{"stopConnection", ts3func_stopConnection, METH_VARARGS,""},
	{"requestClientMove", ts3func_requestClientMove, METH_VARARGS,""},
	{"requestClientVariables", ts3func_requestClientVariables, METH_VARARGS,""},
	{"requestClientKickFromChannel", ts3func_requestClientKickFromChannel, METH_VARARGS,""},
	{"requestClientKickFromServer", ts3func_requestClientKickFromServer, METH_VARARGS,""},
	{"requestChannelDelete", ts3func_requestChannelDelete, METH_VARARGS,""},
	{"requestChannelMove", ts3func_requestChannelMove, METH_VARARGS,""},
	{"requestSendPrivateTextMsg", ts3func_requestSendPrivateTextMsg, METH_VARARGS,""},
	{"requestSendChannelTextMsg", ts3func_requestSendChannelTextMsg, METH_VARARGS,""},
	{"requestSendServerTextMsg", ts3func_requestSendServerTextMsg, METH_VARARGS,""},
	{"requestConnectionInfo", ts3func_requestConnectionInfo, METH_VARARGS,""},
	{"requestClientSetWhisperList", ts3func_requestClientSetWhisperList, METH_VARARGS,""},
	{"requestChannelSubscribe", ts3func_requestChannelSubscribe, METH_VARARGS,""},
	{"requestChannelSubscribeAll", ts3func_requestChannelSubscribeAll, METH_VARARGS,""},
	{"requestChannelUnsubscribe", ts3func_requestChannelUnsubscribe, METH_VARARGS,""},
	{"requestChannelUnsubscribeAll", ts3func_requestChannelUnsubscribeAll, METH_VARARGS,""},
	{"requestChannelDescription", ts3func_requestChannelDescription, METH_VARARGS,""},
	{"requestMuteClients", ts3func_requestMuteClients, METH_VARARGS,""},
	{"requestUnmuteClients", ts3func_requestUnmuteClients, METH_VARARGS,""},
	{"requestClientPoke", ts3func_requestClientPoke, METH_VARARGS,""},
	{"requestClientIDs", ts3func_requestClientIDs, METH_VARARGS,""},
	{"clientChatClosed", ts3func_clientChatClosed, METH_VARARGS,""},
	{"clientChatComposing", ts3func_clientChatComposing, METH_VARARGS,""},
	{"requestServerTemporaryPasswordAdd", ts3func_requestServerTemporaryPasswordAdd, METH_VARARGS,""},
	{"requestServerTemporaryPasswordDel", ts3func_requestServerTemporaryPasswordDel, METH_VARARGS,""},
	{"requestServerTemporaryPasswordList", ts3func_requestServerTemporaryPasswordList, METH_VARARGS,""},
	{"getClientID", ts3func_getClientID, METH_VARARGS,""},
	{"getClientSelfVariableAsInt", ts3func_getClientSelfVariableAsInt, METH_VARARGS,""},
	{"getClientSelfVariableAsString", ts3func_getClientSelfVariableAsString, METH_VARARGS,""},
	{"setClientSelfVariableAsInt", ts3func_setClientSelfVariableAsInt, METH_VARARGS,""},
	{"setClientSelfVariableAsString", ts3func_setClientSelfVariableAsString, METH_VARARGS,""},
	{"flushClientSelfUpdates", ts3func_flushClientSelfUpdates, METH_VARARGS,""},
	{"getClientVariableAsInt", ts3func_getClientVariableAsInt, METH_VARARGS,""},
	{"getClientVariableAsUInt64", ts3func_getClientVariableAsUInt64, METH_VARARGS,""},
	{"getClientVariableAsString", ts3func_getClientVariableAsString, METH_VARARGS,""},
	{"getClientList", ts3func_getClientList, METH_VARARGS,""},
	{"getChannelOfClient", ts3func_getChannelOfClient, METH_VARARGS,""},
	{"getChannelVariableAsInt", ts3func_getChannelVariableAsInt, METH_VARARGS,""},
	{"getChannelVariableAsUInt64", ts3func_getChannelVariableAsUInt64, METH_VARARGS,""},
	{"getChannelVariableAsString", ts3func_getChannelVariableAsString, METH_VARARGS,""},
	{"getChannelIDFromChannelNames", ts3func_getChannelIDFromChannelNames, METH_VARARGS,""},
	{"setChannelVariableAsInt", ts3func_setChannelVariableAsInt, METH_VARARGS,""},
	{"setChannelVariableAsUInt64", ts3func_setChannelVariableAsUInt64, METH_VARARGS,""},
	{"setChannelVariableAsString", ts3func_setChannelVariableAsString, METH_VARARGS,""},
	{"flushChannelUpdates", ts3func_flushChannelUpdates, METH_VARARGS,""},
	{"flushChannelCreation", ts3func_flushChannelCreation, METH_VARARGS,""},
	{"getChannelList", ts3func_getChannelList, METH_VARARGS,""},
	{"getChannelClientList", ts3func_getChannelClientList, METH_VARARGS,""},
	{"getParentChannelOfChannel", ts3func_getParentChannelOfChannel, METH_VARARGS,""},
	{"getServerConnectionHandlerList", ts3func_getServerConnectionHandlerList, METH_VARARGS,""},
	{"getServerVariableAsInt", ts3func_getServerVariableAsInt, METH_VARARGS,""},
	{"getServerVariableAsUInt64", ts3func_getServerVariableAsUInt64, METH_VARARGS,""},
	{"getServerVariableAsString", ts3func_getServerVariableAsString, METH_VARARGS,""},
	{"requestServerVariables", ts3func_requestServerVariables, METH_VARARGS,""},
	{"getConnectionStatus", ts3func_getConnectionStatus, METH_VARARGS,""},
	{"getConnectionVariableAsUInt64", ts3func_getConnectionVariableAsUInt64, METH_VARARGS,""},
	{"getConnectionVariableAsDouble", ts3func_getConnectionVariableAsDouble, METH_VARARGS,""},
	{"getConnectionVariableAsString", ts3func_getConnectionVariableAsString, METH_VARARGS,""},
	{"cleanUpConnectionInfo", ts3func_cleanUpConnectionInfo, METH_VARARGS,""},
	{"requestClientDBIDfromUID", ts3func_requestClientDBIDfromUID, METH_VARARGS,""},
	{"requestClientNamefromUID", ts3func_requestClientNamefromUID, METH_VARARGS,""},
	{"requestClientNamefromDBID", ts3func_requestClientNamefromDBID, METH_VARARGS,""},
	{"requestClientEditDescription", ts3func_requestClientEditDescription, METH_VARARGS,""},
	{"requestClientSetIsTalker", ts3func_requestClientSetIsTalker, METH_VARARGS,""},
	{"requestIsTalker", ts3func_requestIsTalker, METH_VARARGS,""},
	{"requestSendClientQueryCommand", ts3func_requestSendClientQueryCommand, METH_VARARGS,""},
	{"getTransferFileName", ts3func_getTransferFileName, METH_VARARGS,""},
	{"getTransferFilePath", ts3func_getTransferFilePath, METH_VARARGS,""},
	{"getTransferFileSize", ts3func_getTransferFileSize, METH_VARARGS,""},
	{"getTransferFileSizeDone", ts3func_getTransferFileSizeDone, METH_VARARGS,""},
	{"isTransferSender", ts3func_isTransferSender, METH_VARARGS,""},
	{"getTransferStatus", ts3func_getTransferStatus, METH_VARARGS,""},
	{"getCurrentTransferSpeed", ts3func_getCurrentTransferSpeed, METH_VARARGS,""},
	{"getAverageTransferSpeed", ts3func_getAverageTransferSpeed, METH_VARARGS,""},
	{"getTransferRunTime", ts3func_getTransferRunTime, METH_VARARGS,""},
	{"sendFile", ts3func_sendFile, METH_VARARGS,""},
	{"requestFile", ts3func_requestFile, METH_VARARGS,""},
	{"haltTransfer", ts3func_haltTransfer, METH_VARARGS,""},
	{"requestFileList", ts3func_requestFileList, METH_VARARGS,""},
	{"requestFileInfo", ts3func_requestFileInfo, METH_VARARGS,""},
	{"requestDeleteFile", ts3func_requestDeleteFile, METH_VARARGS,""},
	{"requestCreateDirectory", ts3func_requestCreateDirectory, METH_VARARGS,""},
	{"requestRenameFile", ts3func_requestRenameFile, METH_VARARGS,""},
	{"requestMessageAdd", ts3func_requestMessageAdd, METH_VARARGS,""},
	{"requestMessageDel", ts3func_requestMessageDel, METH_VARARGS,""},
	{"requestMessageGet", ts3func_requestMessageGet, METH_VARARGS,""},
	{"requestMessageList", ts3func_requestMessageList, METH_VARARGS,""},
	{"requestMessageUpdateFlag", ts3func_requestMessageUpdateFlag, METH_VARARGS,""},
	{"verifyServerPassword", ts3func_verifyServerPassword, METH_VARARGS,""},
	{"verifyChannelPassword", ts3func_verifyChannelPassword, METH_VARARGS,""},
	{"banclient", ts3func_banclient, METH_VARARGS,""},
	{"banadd", ts3func_banadd, METH_VARARGS,""},
	{"banclientdbid", ts3func_banclientdbid, METH_VARARGS,""},
	{"bandel", ts3func_bandel, METH_VARARGS,""},
	{"bandelall", ts3func_bandelall, METH_VARARGS,""},
	{"requestBanList", ts3func_requestBanList, METH_VARARGS,""},
	{"requestComplainAdd", ts3func_requestComplainAdd, METH_VARARGS,""},
	{"requestComplainDel", ts3func_requestComplainDel, METH_VARARGS,""},
	{"requestComplainDelAll", ts3func_requestComplainDelAll, METH_VARARGS,""},
	{"requestComplainList", ts3func_requestComplainList, METH_VARARGS,""},
	{"requestServerGroupList", ts3func_requestServerGroupList, METH_VARARGS,""},
	{"requestServerGroupAdd", ts3func_requestServerGroupAdd, METH_VARARGS,""},
	{"requestServerGroupDel", ts3func_requestServerGroupDel, METH_VARARGS,""},
	{"requestServerGroupAddClient", ts3func_requestServerGroupAddClient, METH_VARARGS,""},
	{"requestServerGroupDelClient", ts3func_requestServerGroupDelClient, METH_VARARGS,""},
	{"requestServerGroupsByClientID", ts3func_requestServerGroupsByClientID, METH_VARARGS,""},
	{"requestServerGroupAddPerm", ts3func_requestServerGroupAddPerm, METH_VARARGS,""},
	{"requestServerGroupDelPerm", ts3func_requestServerGroupDelPerm, METH_VARARGS,""},
	{"requestServerGroupPermList", ts3func_requestServerGroupPermList, METH_VARARGS,""},
	{"requestServerGroupClientList", ts3func_requestServerGroupClientList, METH_VARARGS,""},
	{"requestChannelGroupList", ts3func_requestChannelGroupList, METH_VARARGS,""},
	{"requestChannelGroupAdd", ts3func_requestChannelGroupAdd, METH_VARARGS,""},
	{"requestChannelGroupDel", ts3func_requestChannelGroupDel, METH_VARARGS,""},
	{"requestChannelGroupAddPerm", ts3func_requestChannelGroupAddPerm, METH_VARARGS,""},
	{"requestChannelGroupDelPerm", ts3func_requestChannelGroupDelPerm, METH_VARARGS,""},
	{"requestChannelGroupPermList", ts3func_requestChannelGroupPermList, METH_VARARGS,""},
	{"requestSetClientChannelGroup", ts3func_requestSetClientChannelGroup, METH_VARARGS,""},
	{"requestChannelAddPerm", ts3func_requestChannelAddPerm, METH_VARARGS,""},
	{"requestChannelDelPerm", ts3func_requestChannelDelPerm, METH_VARARGS,""},
	{"requestChannelPermList", ts3func_requestChannelPermList, METH_VARARGS,""},
	{"requestClientAddPerm", ts3func_requestClientAddPerm, METH_VARARGS,""},
	{"requestClientDelPerm", ts3func_requestClientDelPerm, METH_VARARGS,""},
	{"requestClientPermList", ts3func_requestClientPermList, METH_VARARGS,""},
	{"requestChannelClientAddPerm", ts3func_requestChannelClientAddPerm, METH_VARARGS,""},
	{"requestChannelClientDelPerm", ts3func_requestChannelClientDelPerm, METH_VARARGS,""},
	{"requestChannelClientPermList", ts3func_requestChannelClientPermList, METH_VARARGS,""},
	{"privilegeKeyUse", ts3func_privilegeKeyUse, METH_VARARGS,""},
	{"requestPermissionList", ts3func_requestPermissionList, METH_VARARGS,""},
	{"requestPermissionOverview", ts3func_requestPermissionOverview, METH_VARARGS,""},
	{"clientPropertyStringToFlag", ts3func_clientPropertyStringToFlag, METH_VARARGS,""},
	{"channelPropertyStringToFlag", ts3func_channelPropertyStringToFlag, METH_VARARGS,""},
	{"serverPropertyStringToFlag", ts3func_serverPropertyStringToFlag, METH_VARARGS,""},
	{"getAppPath", ts3func_getAppPath, METH_VARARGS,""},
	{"getResourcesPath", ts3func_getResourcesPath, METH_VARARGS,""},
	{"getConfigPath", ts3func_getConfigPath, METH_VARARGS,""},
	{"getPluginPath", ts3func_getPluginPath, METH_VARARGS,""},
	{"getCurrentServerConnectionHandlerID", ts3func_getCurrentServerConnectionHandlerID, METH_VARARGS,""},
	{"printMessage", ts3func_printMessage, METH_VARARGS,""},
	{"printMessageToCurrentTab", ts3func_printMessageToCurrentTab, METH_VARARGS,""},
	{"urlsToBB", ts3func_urlsToBB, METH_VARARGS,""},
	{"sendPluginCommand", ts3func_sendPluginCommand, METH_VARARGS,""},
	{"getDirectories", ts3func_getDirectories, METH_VARARGS,""},
	{"getServerConnectInfo", ts3func_getServerConnectInfo, METH_VARARGS,""},
	{"getChannelConnectInfo", ts3func_getChannelConnectInfo, METH_VARARGS,""},
	{"createReturnCode", ts3func_createReturnCode, METH_VARARGS,""},
	{"requestInfoUpdate", ts3func_requestInfoUpdate, METH_VARARGS,""},
	{"getServerVersion", ts3func_getServerVersion, METH_VARARGS,""},
	{"isWhispering", ts3func_isWhispering, METH_VARARGS,""},
	{"isReceivingWhisper", ts3func_isReceivingWhisper, METH_VARARGS,""},
	{"getAvatar", ts3func_getAvatar, METH_VARARGS,""},
	{"setPluginMenuEnabled", ts3func_setPluginMenuEnabled, METH_VARARGS,""},
	{"showHotkeySetup", ts3func_showHotkeySetup, METH_VARARGS,""},
	{"getClientDisplayName", ts3func_getClientDisplayName, METH_VARARGS,""},
	{"getProfileList", ts3func_getProfileList, METH_VARARGS,""},
	{"guiConnect", ts3func_guiConnect, METH_VARARGS,""},
	{"guiConnectBookmark", ts3func_guiConnectBookmark, METH_VARARGS,""},
	{"createBookmark", ts3func_createBookmark, METH_VARARGS,""},
	{"getPermissionIDByName", ts3func_getPermissionIDByName, METH_VARARGS,""},
	{"getClientNeededPermission", ts3func_getClientNeededPermission, METH_VARARGS,""},
	
	{NULL, NULL, 0, NULL}        /* Sentinel */
	};

PyMODINIT_FUNC
init_ts3functions(){
	PyObject *m;
	
	m = Py_InitModule("TS3Functions", TS3FunctionsMethods);
	if (m == NULL){
		printf("Failed to initialize TS3Functions\n");
		return;
	}
}
