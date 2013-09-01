/*
 * LogicTC.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#include "LogicTC.h"

LogicTC::LogicTC(uint8_t outputPin, bool value) :
		AbstractTC() {
	_outputPin = outputPin;
	_outputValue = value;
}

LogicTC::~LogicTC() {
}

void LogicTC::init() {
	pinMode(_outputPin, OUTPUT);
}

void LogicTC::exec_impl_() {
	digitalWrite(_outputPin, _outputValue);
}
