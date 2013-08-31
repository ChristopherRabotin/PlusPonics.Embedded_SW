/*
 * DigitalWriteTC.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#include "DigitalWriteTC.h"

DigitalWriteTC::DigitalWriteTC(int outputPin, int value) :
		TC() {
	_outputPin = outputPin;
	_outputValue = value;
}

DigitalWriteTC::~DigitalWriteTC() {
}

void DigitalWriteTC::init() {
	pinMode(_outputPin, OUTPUT);
}

void DigitalWriteTC::exec_impl_() {
	digitalWrite(_outputPin, _outputValue);
}
