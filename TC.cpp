/*
 * TC.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: chris
 */

#include "TC.h"

TC::TC(int opcode) {
	enabled = true;
	running = false;
	executions = 0;
	persistent_error = false;
	error = NO_ERROR;
}

TC::~TC() {
}

void TC::enable() {
	if (!running) {
		if (!enabled) {
			enabled = true;
		} else {
			error = WAS_ENABLED;
		}
	} else {
		error = READ_ONLY;
	}
}

void TC::disable() {
	if (!running) {
		if (enabled) {
			enabled = false;
		} else {
			error = WAS_DISABLED;
		}
	} else {
		error = READ_ONLY;
	}
}

void TC::start() {
	if (enabled) {
		if (!running) {
			running = true;
			__stop();
		} else {
			error = WAS_RUNNING;
		}
	} else {
		error = NOT_ENABLED;
	}
}

void TC::stop() {
	if (enabled) {
		if (running) {
			running = false;
			__stop();
		} else {
			error = WAS_STOPPED;
		}
	} else {
		error = NOT_ENABLED;
	}
}

void TC::persist_errors(bool persist) {
	persistent_error = persist;
}

void TC::clear_error() {
	if (persistent_error) {
		error = NO_ERROR;
	} else {
		error = WAS_NOT_PERSISTENT;
	}
}

TC::ERROR_STATE TC::errno() {
	TC::ERROR_STATE rtn = error;
	if (!persistent_error) {
		error = NO_ERROR;
	}
	return (rtn);
}
