/*
 * Debug.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: chris
 */

#include "Debug.h"

const String Debug::DEFAULT_LOCATION = "None";

Debug::Debug(AbstractCommunication* com) {
	this->com = com;
}

Debug::~Debug() {
}

void Debug::info(String msg) {
	info(msg, DEFAULT_LOCATION);
}

void Debug::warn(String msg) {
	warn(msg, DEFAULT_LOCATION);
}

void Debug::error(String msg) {
	error(msg, DEFAULT_LOCATION);
}

void Debug::info(String msg, String location) {
	com->send("INFO: " + msg + " <" + location + ">");
}

void Debug::warn(String msg, String location) {
	com->send("WARN: " + msg + " <" + location + ">");
}

void Debug::error(String msg, String location) {
	com->send("ERROR: " + msg + " <" + location + ">");
}
