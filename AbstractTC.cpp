/*
 * AbstractTC.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: chris
 */

#include "AbstractTC.h"
namespace TC {
AbstractTC::AbstractTC() {
	_enabled = true;
	_executions = 0;
	_persistent_error = false;
	_error = NO_ERROR;
}

AbstractTC::~AbstractTC() {
}

void AbstractTC::enable() {
	if (!_enabled) {
		_enabled = true;
	} else {
		_error = WAS_ENABLED;
	}
}

void AbstractTC::disable() {
	if (_enabled) {
		_enabled = false;
	} else {
		_error = WAS_DISABLED;
	}
}

void AbstractTC::exec() {
	if (_enabled) {
		_executions++;
		exec_impl_();
	} else {
		_error = NOT_ENABLED;
	}
}

void AbstractTC::persist_errors(bool persist) {
	_persistent_error = persist;
}

void AbstractTC::clear_error() {
	if (_persistent_error) {
		_error = NO_ERROR;
	} else {
		_error = WAS_NOT_PERSISTENT;
	}
}

AbstractTC::ERROR_STATE AbstractTC::errno() {
	AbstractTC::ERROR_STATE rtn = _error;
	if (!_persistent_error) {
		_error = NO_ERROR;
	}
	return (rtn);
}
}
