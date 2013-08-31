/*
 * TC.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: chris
 */

#include "TC.h"

TC::TC(int opcode) {
	enabled = true;
	executions = 0;
	persistent_error = false;
	error = NO_ERROR;
}

TC::~TC() {
}

void TC::enable() {
	if (!enabled) {
		enabled = true;
	} else {
		error = WAS_ENABLED;
	}
}

void TC::disable() {
	if (enabled) {
		enabled = false;
	} else {
		error = WAS_DISABLED;
	}
}

void TC::exec() {
	if (enabled) {
		this->executions++;
		exec_impl_();
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
