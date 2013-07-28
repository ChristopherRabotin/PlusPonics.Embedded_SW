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

void GlobalReceiver::process() {
	String input = com->recv();
	/*
	 * Let's get the first character from which we'll get the first three charaters.
	 */
	unsigned char *firstChar = 0x0;
	input.getBytes(firstChar, 1);
	uint32_t action = (uint32_t) firstChar[0] & 0xE;
	char reply[100];
	switch (action) {
	case 4:
		sprintf(reply, "CMD (%s)", input.c_str());
		break;
	case 1:
		sprintf(reply, "Proc (%s)", input.c_str());
		break;
	case 2:
		sprintf(reply, "Dwell (%s)", input.c_str());
		break;
	case 3:
		sprintf(reply, "Meta (%s)", input.c_str());
		break;
	default:
		sprintf(reply, "??? (%s): %x", input.c_str(), action);
	}

	com->send(String(reply));
}

void GlobalReceiver::setCom(AbstractCommunication* com) {
	this->com = com;
}

GlobalReceiver::~GlobalReceiver() {

}

