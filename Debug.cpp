/*
 * Debug.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: chris
 */

#include "Debug.h"

const String Debug::DEFAULT_LOCATION = "None";

Debug::Debug(AbstractCommunication* com, DEBUG_LEVEL lvl) {
	this->com = com;
	this->lvl = lvl;
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
	if (this->lvl <= INFO) {
		com->send("INFO: " + msg + " <" + location + ">");
	}
}

void Debug::warn(String msg, String location) {
	if (this->lvl <= WARN) {
		com->send("WARN: " + msg + " <" + location + ">");
	}
}

Debug::Debug() {
	this->com = NULL;
	this->lvl = INFO;
}

void Debug::setCom(AbstractCommunication* com) {
	this->com = com;
}

void Debug::error(String msg, String location) {
	if (this->lvl <= ERROR) {
		com->send("ERROR: " + msg + " <" + location + ">");
	}
}

void Debug::setLevel(DEBUG_LEVEL lvl) {
	this->lvl = lvl;
}
