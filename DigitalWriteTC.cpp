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
	setup();
}

DigitalWriteTC::~DigitalWriteTC() {
}

void DigitalWriteTC::setup() {
	pinMode(this->outputPin, OUTPUT);
}

void DigitalWriteTC::exec_impl_() {
	digitalWrite(this->outputPin, this->outputValue);
}
