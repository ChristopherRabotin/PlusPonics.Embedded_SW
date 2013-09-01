/*
 * Limit.h
 *
 *  Created on: Sep 1, 2013
 *      Author: chris
 */

#ifndef LIMIT_H_
#define LIMIT_H_

#include <stdint.h>

namespace TM {
/**
 * @class Limit
 * @brief This class defines how a limit is to operate.
 * This is used by any telemetry point which defines limits.
 */
class Limit {
public:
	Limit();
	virtual ~Limit();
	/**
	 * @enum LIMIT_TYPE defines if this limit is a HIGH limit or a LOW limit.
	 */
	enum LIMIT_TYPE {
		NONE, /**< this is only used for initialization of the empty constructor. */
		HIGH, /**< this defines a high limit, such as red high or yellow high. It will check that the provided value is less than the limit. */
		LOW /**< this defines a low limit, such as red low or yellow low. It will check that the provided value is greater than the limit. */
	};
	/**
	 * @brief This function will set the opcode to execute if there is an out of limit.
	 * This function should only be called once, right after initialization, but no mechanism prevent it from being called more than once.
	 * @param opc op_code
	 */
	void set_opcode(uint8_t opc);

	/**
	 * @brief This function sets the limit of the instance.
	 * This function should only be called once, right after initialization, but no mechanism prevent it from being called more than once.
	 * @param lim
	 */
	void set_limit(int32_t lim);

	/**
	 * @brief This function will check if the current value provided is within the limits.
	 * @param value value to be checked against.
	 * @return 0 if there is no OOL (since 0 is an invalid OPCODE) or the OPCODE to execute.
	 */
	uint8_t check_limit(int32_t value);
private:
	LIMIT_TYPE _type;
	uint8_t _opcode;
	int32_t _limit;
};

} /* namespace TM */
#endif /* LIMIT_H_ */
