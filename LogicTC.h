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
 * @brief This class enables digital writing to a given output pin with the given output value.
 * @warning This class does not check whether the pin is used in another mode. It is very important to check for any conflict beforehand!
 */
class LogicTC: public TC {
public:
	/**
	 * @brief Specify in the constructor both the output pin and the output value.
	 * @note The output pin and the output value cannot be changed after initialization.
	 * @param outputPin pin to be used as the output of this TC.
	 * @param value value which is to be sent on the given output pin.
	 */
	LogicTC(int outputPin, int value);
	virtual ~LogicTC();
	virtual void init();
	virtual void exec_impl_();
private:
	int _outputPin;
	int _outputValue;
};

#endif /* DIGITALWRITETC_H_ */
