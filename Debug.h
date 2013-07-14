/*
 * Debug.h
 *
 *  Created on: Jul 15, 2013
 *      Author: chris
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "AbstractCommunication.h"

class Debug {
public:
	/**
	 * @brief Constructor of the Debug class.
	 * @param com AbstractCommunication instance used for communication.
	 */
	Debug(AbstractCommunication *com);
	virtual ~Debug();
	void info(String msg);
	void warn(String msg);
	void error(String msg);
	/**
	 * @brief This function sends an informational debug message.
	 * The location parameter is optional. @ref info(String msg);
	 * @param msg message to be sent
	 * @param location location where this message was emitted.
	 */
	void info(String msg, String location);
	/**
	 * @brief This function sends a warning debug message.
	 * The location parameter is optional. @ref info(String msg);
	 * @param msg message to be sent
	 * @param location location where this message was emitted.
	 */
	void warn(String msg, String location);
	/**
	 * @brief This function sends an error debug message.
	 * The location parameter is optional. @ref info(String msg);
	 * @param msg message to be sent
	 * @param location location where this message was emitted.
	 */
	void error(String msg, String location);
private:
	AbstractCommunication *com;
	static const String DEFAULT_LOCATION;
};

#endif /* DEBUG_H_ */
