/*
 * TC.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: chris
 */

#include "TC.h"

TC::TC() {
	_enabled = true;
	_executions = 0;
	_persistent_error = false;
	_error = NO_ERROR;
}

TC::~TC() {
}

void TC::enable() {
	if (!_enabled) {
		_enabled = true;
	} else {
		_error = WAS_ENABLED;
	}
}

void TC::disable() {
	if (_enabled) {
		_enabled = false;
	} else {
		_error = WAS_DISABLED;
	}
}

void TC::exec() {
	if (_enabled) {
		_executions++;
		exec_impl_();
	} else {
		_error = NOT_ENABLED;
	}
}

void TC::persist_errors(bool persist) {
	_persistent_error = persist;
}

void TC::clear_error() {
	if (_persistent_error) {
		_error = NO_ERROR;
	} else {
		_error = WAS_NOT_PERSISTENT;
	}
}

TC::ERROR_STATE TC::errno() {
	TC::ERROR_STATE rtn = _error;
	if (!_persistent_error) {
		_error = NO_ERROR;
	}
	return (rtn);
}
