/*
 * AbstractCommunication.cpp
 *
 *  Created on: Jul 14, 2013
 *      Author: chris
 */

#include "AbstractCommunication.h"

/**
 *\brief The constructor should initialize the communication with the control system.
 * This includes everything needed prior to starting to communicate with the control system.
 */
AbstractCommunication::AbstractCommunication() {
	lvl = ERROR;
}

AbstractCommunication::~AbstractCommunication() {
}

const String AbstractCommunication::DEFAULT_LOCATION = "None";

void AbstractCommunication::info(String msg) {
	info(msg, DEFAULT_LOCATION);
}

void AbstractCommunication::warn(String msg) {
	warn(msg, DEFAULT_LOCATION);
}

void AbstractCommunication::error(String msg) {
	error(msg, DEFAULT_LOCATION);
}

void AbstractCommunication::info(String msg, String location) {
	if (lvl <= INFO) {
		send("INFO: " + msg + " <" + location + ">");
	}
}

void AbstractCommunication::warn(String msg, String location) {
	if (lvl <= WARN) {
		send("WARN: " + msg + " <" + location + ">");
	}
}

void AbstractCommunication::error(String msg, String location) {
	if (lvl <= ERROR) {
		send("ERROR: " + msg + " <" + location + ">");
	}
}

void AbstractCommunication::setLevel(DEBUG_LEVEL lvl) {
	this->lvl = lvl;
}
