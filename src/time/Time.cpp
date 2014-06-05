/*
 * Time.cpp
 *
 *  Created on: 4 Jun 2014
 *      Author: andy
 */

#include "Time.h"

#include <sys/time.h>
#include <ctime>
#include <cstdio>


Time::Time() {
}

Time::~Time() {
}

const std::string Time::getCurrentTime() {
	char buffer[11];
	time_t t;
	time(&t);
	tm r = { 0 };
	strftime(buffer, sizeof(buffer), "%X", localtime_r(&t, &r));
	struct timeval tv;
	gettimeofday(&tv, 0);
	char result[100] = { 0 };
	std::sprintf(result, "%s.%03ld", buffer, (long) tv.tv_usec / 1000);
	return result;
}


