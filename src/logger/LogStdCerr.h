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

#ifndef LOG_MAX_LEVEL
#define LOG_MAX_LEVEL DEBUG
#endif
#define LOG(level,message) \
  if (level > LOG_MAX_LEVEL) ;\
  else if (level > Log::ReportingLevel() || !Log::Stream()) ; \
   else Log().Get(level) << message

class LogStdCerr;
class STDCERRLog : public Logger<LogStdCerr> {
};

class LogStdCerr{
public:
	typedef LogStdCerr Log;

	static void Output(const std::string& message);
};

#endif /* LOGSTDCERR_H_ */
