#pragma once

#include <stddef.h>
#include "ts3_functions.h"

void initializePython(const char * pluginPath);
void setPythonPath(const char * pluginPath);
void finalizePython();
void includeMain();
void setTS3FunctionPointers(const struct TS3Functions funcs) ;
struct TS3Functions * getTS3FunctionPointers();