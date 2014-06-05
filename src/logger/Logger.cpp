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
	static Logger::Level reportLevel_;
	return reportLevel_;
}

const std::string Logger::toString(const Logger::Level& level) {
	switch (level) {
		case NONE:
			return "NONE";
			break;
		case DEBUG:
			return "DEBUG";
			break;
		case INFO:
			return "INFO";
			break;
		case ERROR:
			return "ERROR";
			break;
		case WARNING:
			return "WARNING";
			break;
		default:
			return "NONE";
			break;
	}
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
	os << std::string(level > DEBUG ? 0 : level - DEBUG, '\t');
	verbosity_ = level;
	return os;
}
