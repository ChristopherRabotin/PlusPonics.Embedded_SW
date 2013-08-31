/*
 * DigitalWriteTC.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#include "DigitalWriteTC.h"

DigitalWriteTC::DigitalWriteTC(int outputPin, int value) :
		TC() {
	this->outputPin = outputPin;
	this->outputValue = value;
}

DigitalWriteTC::~DigitalWriteTC() {
}

void DigitalWriteTC::init() {
	pinMode(this->outputPin, OUTPUT);
}

void DigitalWriteTC::exec_impl_() {
	digitalWrite(this->outputPin, this->outputValue);
}
