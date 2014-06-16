//============================================================================
// Name        : Logger.cpp
// Author      : Andrea Marangoni
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "logger/LogStdCerr.h"

using namespace std;


void f1();
char f2(int a);
int& f3(int a, int* b);

int main(int argc, char *argv[]) {

	STDCERRLog::reportLevel() = STDCERRLog::DEBUG;



	f1();



















	f2(97);














	int a[10] = { 1,2,3,4,5,5,6,7,8,11};

	f3(9,a);

	return 0;
}


void f1(){
	LOG(Log::INFO) << LOG_SOURCE_REF;
	return;
}

char f2(int a){
	LOG(Log::DEBUG) << LOG_SOURCE_REF;
	return (char)a;
}

int& f3(int a, int* b){
	LOG(Log::DEBUG) << LOG_SOURCE_REF;
	return b[a];
}
