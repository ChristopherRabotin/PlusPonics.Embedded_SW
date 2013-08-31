/*
 * DigitalWriteTC.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#include "DigitalWriteTC.h"

DigitalWriteTC::DigitalWriteTC(int opcode, int outputPin, int value) :
		TC(opcode) {
	this->outputPin = outputPin;
	this->outputValue = value;

}

DigitalWriteTC::~DigitalWriteTC() {
}

void DigitalWriteTC::exec_impl_() {
	digitalRead(this->outputValue);
}
