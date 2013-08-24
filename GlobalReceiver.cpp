/*
 * GlobalReceiver.cpp
 *
 *  Created on: Jul 21, 2013
 *      Author: chris
 */

#include "GlobalReceiver.h"

GlobalReceiver::GlobalReceiver() {
	this->com = NULL;
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
	String input = com->recv();
	if(input.length() == 0) return;
	char action = input.c_str()[0];
	switch (action) {
	case '1':
		com->sendf("CMD (%s)", input.c_str());
		break;
	case '3':
		com->sendf("Procedure (%s)", input.c_str());
		break;
	case '5':
		com->sendf("Dwell (%s)", input.c_str());
		break;
	case '7':
		com->sendf("Meta (%s)", input.c_str());
		break;
	default:
		com->sendf("??? '%s' | %s b | a: %s b", input.c_str(),
				byte_to_binary(input.toInt()), byte_to_binary((int) action));
	}
}

void GlobalReceiver::setCom(AbstractCommunication &comInstance) {
	com = &comInstance;
}

GlobalReceiver::~GlobalReceiver() {

}

