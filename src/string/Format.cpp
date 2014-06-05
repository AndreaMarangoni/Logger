/*
 * Format.cpp
 *
 *  Created on: 4 Jun 2014
 *      Author: andy
 */

#include <vector>
#include <cstdio>

#include "Format.h"

std::string Format(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	std::string buf = vformat(fmt, ap);
	va_end(ap);
	return buf;
}

std::string vformat(const char *fmt, va_list ap) {
	size_t size = 1024;
	char stackbuf[1024];
	std::vector<char> dynamicbuf;
	char *buf = &stackbuf[0];
	while (1) {
		int needed = vsnprintf(buf, size, fmt, ap);
		if (needed <= (int) size && needed >= 0) {
			return std::string(buf, (size_t) needed);
		}
		size = (needed > 0) ? (needed + 1) : (size * 2);
		dynamicbuf.resize(size);
		buf = &dynamicbuf[0];
	}
}

