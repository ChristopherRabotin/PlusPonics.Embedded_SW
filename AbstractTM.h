/*
 * AbstractTM.h
 *
 *  Created on: Sep 1, 2013
 *      Author: chris
 */

#ifndef ABSTRACTTM_H_
#define ABSTRACTTM_H_
/**
 * @namespace TM
 * @brief This namespace includes everything related to telemetry, up until it is to be reported.
 * The reporting of the telemetry is handled by the Processors namespace.
 */
namespace TM {
/**
 * @class AbstractTM
 * @brief This class defines the high level requirements of a telemetry point. It must be overwritten by low level classes.
 * A telemetry point has different reporting levels.
 *
 */
class AbstractTM {
public:
	AbstractTM();
	virtual ~AbstractTM();
	/**
	 * @enum REPORTING_STATE defines all the reporting states a TM can have.
	 */
	enum REPORTING_STATE {
		ALWAYS, /**< always report the value of the telemetry */
		ON_CHANGE, /**< only report if the value has changed */
		ON_OOL, /**< only report if this telemetry is out of limits */
		ON_REQUEST /**< if attempting to disable and was already disabled */
	};

	/**
	 * @brief This function will check the limits of this given telemetry point.
	 * It will only check the limits of the limits which are set. In other words, if the red limit is not set, then it will not check
	 * the limits for this.
	 */
	void check_limits();

	/**
	 * @brief This function changes the reporting state of this telemetry point.
	 * @note The only way to know the reporting status of a telemetry point is to request telemetry meta information.
	 * @param new_state new reporting state of this TM.
	 */
	void set_reporting_state(REPORTING_STATE new_state);
private:
	REPORTING_STATE _reporting_state;
};

} /* namespace TM */
#endif /* ABSTRACTTM_H_ */
