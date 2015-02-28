#pragma once

#ifdef WIN32
#define OS(X) Win##X
#else
#error NOT IMPLEMENTED!
#endif


void doX();