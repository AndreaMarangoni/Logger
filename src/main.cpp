//============================================================================
// Name        : Logger.cpp
// Author      : Andrea Marangoni
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "logger/Logger.h"

using namespace std;

int main(int argc, char *argv[]) {

	Logger::reportLevel() = Logger::DEBUG;

	while(true)
		LOG(Logger::DEBUG, " Message ");

	return 0;
}
