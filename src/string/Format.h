/*
 * Format.h
 *
 *  Created on: 4 Jun 2014
 *      Author: andy
 */

#ifndef FORMAT_H_
#define FORMAT_H_

#include <string>
#include <cstdarg>

#define F Format

std::string Format(const char *fmt, ...);
std::string vformat (const char *fmt, va_list ap);

#endif /* FORMAT_H_ */
