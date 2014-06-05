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

#define Log(level) \
	if (	level  > Logger::reportLevel() ) ; \
	else Logger().get(level)

#define LOG(level,message) Log(level) << message

template<typename Type>
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

private:
	static inline const std::string toString(const Logger::Level& level);
	inline Logger(const Logger&);
	inline Logger& operator=(const Logger&);
	std::ostringstream os;
};

#endif /* LOGGER_H_ */

template<typename Type>
typename Logger<Type>::Level& Logger<Type>::reportLevel() {
	static Logger<Type>::Level reportLevel_ = DEBUG;
	return reportLevel_;
}

template<typename Type>
const std::string Logger<Type>::toString(const Logger::Level& level) {
	static std::string names[] = { "CRITICAL", "ERROR", "WARNING", "INFO",
		"DEBUG", "NONE" };
	return names[level];
}

template<typename Type>
Logger<Type>::Logger() {
}

template<typename Type>
Logger<Type>::~Logger() {
	os << std::endl;
	Type::Output(os.str());
}

template<typename Type>
std::ostringstream& Logger<Type>::get(Level level) {
	os << "- " << Time().getCurrentTime();
	os << " " << Logger::toString(level) << ": ";
	return os;
}
