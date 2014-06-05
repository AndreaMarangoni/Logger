/*
 * Logger.cpp
 *
 *  Created on: 4 Jun 2014
 *      Author: andy
 */

#include "Logger.h"
#include "../time/Time.h"

#include <cstdio>

Logger::Level& Logger::reportLevel() {
	static Logger::Level reportLevel_ = DEBUG;
	return reportLevel_;
}

const std::string Logger::toString(const Logger::Level& level) {
	static std::string names[] ={
				"CRITICAL",
				"ERROR",
				"WARNING",
				"INFO",
				"DEBUG",
				"NONE"
	};
	return names[level];
}

Logger::Logger() {
}

Logger::~Logger() {
	os << std::endl;
	fprintf(stderr, "%s", os.str().c_str());
	fflush(stderr);
}

std::ostringstream& Logger::get(Level level) {
	os << "- " << Time().getCurrentTime();
	os << " " << Logger::toString(level) << ": ";
	return os;
}
