/*
 * Logger.h
 *
 *  Created on: 4 Jun 2014
 *      Author: andy
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <sstream>

#define Log(level) \
	if (level > Logger::reportLevel()) ; \
	Logger().get(level)

#define LOG(level) Log(level)

class Logger {
public:
	enum Level {
		NONE,
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		CRITICAL
	};

	Logger();
	virtual ~Logger();
	std::ostringstream& get(Level level = NONE);
	static Logger::Level& reportLevel();
private:
	static const std::string toString(const Logger::Level& level);
	Logger(const Logger&);
	Logger& operator=(const Logger&);
	Logger::Level verbosity_;
	std::ostringstream os;
};

#endif /* LOGGER_H_ */
