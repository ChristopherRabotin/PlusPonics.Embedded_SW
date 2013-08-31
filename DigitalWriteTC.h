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

/**
 * @class DigitalWriteTC
 * @brief This class enables digital writing to a given output pin. Note that this does not check whether the pin is used
 * in another mode. It is very important to check for any conflict beforehand!
 */
class DigitalWriteTC: public TC {
public:
	DigitalWriteTC(int outputPin, int value);
	virtual ~DigitalWriteTC();
	virtual void setup();
	virtual void exec_impl_();
private:
	int outputPin;
	int outputValue;
};

#endif /* DIGITALWRITETC_H_ */
