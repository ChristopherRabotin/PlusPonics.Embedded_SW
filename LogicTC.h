/*
 * LogicTC.h
 *
 *  Created on: Aug 31, 2013
 *      Author: chris
 */

#ifndef LogicTC_H_
#define LogicTC_H_

#include "AbstractTC.h"
#include <Arduino.h>
namespace TC {
/**
 * @class LogicTC
 * @brief This class enables digital writing to a given output pin with the given output value.
 * @warning This class does not check whether the pin is used in another mode. It is very important to check for any conflict beforehand!
 */
class LogicTC: public AbstractTC {
public:
	/**
	 * @brief Specify in the constructor both the output pin and the output value.
	 * @note The output pin and the output value cannot be changed after initialization.
	 * @param outputPin pin to be used as the output of this TC.
	 * @param value value which is to be sent on the given output pin.
	 */
	LogicTC(uint8_t outputPin, bool value);
	virtual ~LogicTC();
	virtual void init();
	virtual void exec_impl_();
private:
	uint8_t _outputPin;
	bool _outputValue;
};
}
#endif /* LogicTC_H_ */
