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
#define LOG_MAX_LEVEL Logger<LogStdCerr>::DEBUG
#endif
#define LOG(level) \
  if (level > LOG_MAX_LEVEL) ;\
  else if (level > Log::reportLevel() || !Log::stream()) ; \
  else Log().get(level)

#define LOG_SOURCE_REF Format("%s [%s ,%u]", __PRETTY_FUNCTION__, __FILE__, __LINE__)

#define Log STDCERRLog

class LogStdCerr;
class STDCERRLog: public Logger<LogStdCerr> {

};

class LogStdCerr {
public:
	static FILE*& stream() {
		return Logger<LogStdCerr>::stream();
	}
	static void Output(const std::string& message);
};

#endif /* LOGSTDCERR_H_ */
