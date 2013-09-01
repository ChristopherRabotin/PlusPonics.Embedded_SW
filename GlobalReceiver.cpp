/*
 * GlobalReceiver.cpp
 *
 *  Created on: Jul 21, 2013
 *      Author: chris
 */

#include "GlobalReceiver.h"

GlobalReceiver::GlobalReceiver() {
	_com = NULL;
	_tcProcessor = NULL;
}

const char *byte_to_binary(int x) {
	static char b[9];
	b[0] = '\0';

	int z;
	for (z = 128; z > 0; z >>= 1) {
		strcat(b, ((x & z) == z) ? "1" : "0");
	}

	return (b);
}

void GlobalReceiver::process() {
	String input = _com->recv();
	if(input.length() == 0) return;
	char action = input.c_str()[0];
	switch (action) {
	case '1':
		_com->sendf("CMD (%s)", input.c_str());
		_tcProcessor->processRecv(input.substring(1));
		break;
	case '3':
		_com->sendf("Procedure (%s)", input.c_str());
		break;
	case '5':
		_com->sendf("Dwell (%s)", input.c_str());
		break;
	case '7':
		_com->sendf("Meta (%s)", input.c_str());
		break;
	default:
		_com->sendf("??? '%s' | %s b | a: %s b", input.c_str(),
				byte_to_binary(input.toInt()), byte_to_binary((int) action));
	}
}

void GlobalReceiver::setCom(Communicators::AbstractCommunication &comInstance) {
	_com = &comInstance;
}

void GlobalReceiver::setTCProcessor(TCProcessor& tcProcInstance) {
	_tcProcessor = &tcProcInstance;
}

GlobalReceiver::~GlobalReceiver() {

}

