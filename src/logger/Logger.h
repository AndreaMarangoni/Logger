/*
 * Logger.h
 *
 *  Created on: 4 Jun 2014
 *      Author: andy
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "../time/Time.h"

#include <cstdio>
#include <sstream>

template<typename Class>
class Logger {
public:
	enum Level {
		CRITICAL = 0,
		ERROR,
		WARNING,
		INFO,
		DEBUG,
		NONE
	};
	inline Logger();
	inline virtual ~Logger();
	inline std::ostringstream& get(Level level = NONE);
	static inline Logger::Level& reportLevel();
	static inline FILE*& stream();

private:
	static inline const std::string toString(const Logger::Level& level);
	inline Logger(const Logger&);
	inline Logger& operator=(const Logger&);
	std::ostringstream os;
};

#endif /* LOGGER_H_ */

template<typename Class>
typename Logger<Class>::Level& Logger<Class>::reportLevel() {
	static Logger<Class>::Level reportLevel_ = NONE;
	return reportLevel_;
}

template<typename Class>
FILE*& Logger<Class>::stream(){
	static FILE* stream_ = stderr;
	return stream_;
}


template<typename Class>
const std::string Logger<Class>::toString(const Logger::Level& level) {
	static std::string names[] = { "CRITICAL", "ERROR", "WARNING", "INFO",
		"DEBUG", "NONE" };
	return names[level];
}

template<typename Class>
Logger<Class>::Logger() {
}

template<typename Class>
Logger<Class>::~Logger() {
	os << std::endl;
	Class::Output(os.str());
}

template<typename Class>
std::ostringstream& Logger<Class>::get(Level level) {
	os << "- " << Time().getCurrentTime();
	os << " " << Logger::toString(level) << ": ";
	return os;
}
