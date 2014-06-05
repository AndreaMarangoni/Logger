/*
 * Time.h
 *
 *  Created on: 4 Jun 2014
 *      Author: andy
 */

#ifndef TIME_H_
#define TIME_H_

#include <string>

class Time {
public:
	Time();
	virtual ~Time();
	const std::string getCurrentTime();
};

#endif /* TIME_H_ */
