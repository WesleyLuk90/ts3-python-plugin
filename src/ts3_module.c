#include "ts3_module.h"
#include <stdio.h>

static PyObject * ts3mod_test(PyObject *self, PyObject *args);
static PyObject * ts3mod_register_client_event_handler(PyObject *self, PyObject *args);

static PyMethodDef TS3ModuleMethods[] = {
    {
    	"register_client_event_handler", ts3mod_register_client_event_handler, METH_VARARGS,
    	"Call to register the object that recieves the events"
    },
    {
    	"test", ts3mod_test, METH_VARARGS,
    	"Test to make sure the module is loaded."
    },
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyObject * clientEventHandlerList;

PyMODINIT_FUNC
init_ts3mod(){
	PyObject *m;

    m = Py_InitModule("TS3Module", TS3ModuleMethods);
    if (m == NULL){
    	printf("Failed to initialize TS3Module\n");
        return;
    }

    printf("Creating clientEventHandlerList\n");
    clientEventHandlerList = PyList_New(0);
}

PyObject * getClientEventHandlerIterator(){
	return PyObject_GetIter(clientEventHandlerList);
}

static PyObject *
ts3mod_test(PyObject *self, PyObject *args){
	printf("From TS3Module: it works, Hello World!\n");
	Py_RETURN_NONE;
}

static PyObject *
ts3mod_register_client_event_handler(PyObject *self, PyObject *args){
	PyObject * handler;
	if(!PyArg_ParseTuple(args, "O", &handler)){
		return NULL;
	}
	PyList_Append(clientEventHandlerList, handler);
	Py_RETURN_NONE;
}
