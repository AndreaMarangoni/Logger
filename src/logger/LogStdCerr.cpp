/*
 * LogStdCerr.cpp
 *
 *  Created on: 5 Jun 2014
 *      Author: andy
 */

#include "LogStdCerr.h"

void LogStdCerr::Output(const std::string& message) {
	fprintf(stderr, "%s", message.c_str());
	fflush (stderr);
}
