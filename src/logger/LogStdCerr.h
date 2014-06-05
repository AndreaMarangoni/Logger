/*
 * LogStdCerr.h
 *
 *  Created on: 5 Jun 2014
 *      Author: andy
 */

#ifndef LOGSTDCERR_H_
#define LOGSTDCERR_H_

#include "Logger.h"

#include <string>

#define Log(level,message) STDCERRLog().get(level) << message

class LogStdCerr;
class STDCERRLog : public Logger<LogStdCerr> {
};

class LogStdCerr{
public:
	typedef LogStdCerr Log;
	static void Output(const std::string& message);
};

#endif /* LOGSTDCERR_H_ */
