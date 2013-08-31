/*
 * DigitalWriteTC.h
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#ifndef DIGITALWRITETC_H_
#define DIGITALWRITETC_H_

#include "TC.h"
#include <Arduino.h>

class DigitalWriteTC: public TC {
public:
	DigitalWriteTC(int opcode, int outputPin, int value);
	virtual ~DigitalWriteTC();
	virtual void exec_impl_();
private:
	int outputPin;
	int outputValue;
};

#endif /* DIGITALWRITETC_H_ */
