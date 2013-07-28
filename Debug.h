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
	 * @enum DEBUG_LEVEL Defines different levels of debugging.
	 */
	enum DEBUG_LEVEL {
		INFO = 0, /**< this is the info level */
		WARN = 5, /**< this is the warning level */
		ERROR = 10 /**< this is the error level */
	};
	/**
	 * @brief Constructor of the Debug class.
	 * @param com AbstractCommunication instance used for communication
	 * @param lvl level of debugging needed
	 */
	Debug(AbstractCommunication* com, DEBUG_LEVEL lvl);
	/**
	 * @brief Empty constructor for initialization only.
	 */
	Debug();
	virtual ~Debug();
	void info(String msg);
	void warn(String msg);
	void error(String msg);
	/**
	 * @brief This function sends an informational debug message.
	 * The location parameter is optional. @ref info(String msg);
	 * @param msg message to be sent
	 * @param location location where this message was emitted
	 */
	void info(String msg, String location);
	/**
	 * @brief This function sends a warning debug message.
	 * The location parameter is optional. @ref warn(String msg);
	 * @param msg message to be sent
	 * @param location location where this message was emitted
	 */
	void warn(String msg, String location);
	/**
	 * @brief This function sends an error debug message.
	 * The location parameter is optional. @ref error(String msg);
	 * @param msg message to be sent
	 * @param location location where this message was emitted
	 */
	void error(String msg, String location);
	/**
	 * @brief This function sets the communication pointer. This is used when the empty constructor is used.
	 * @param com communication instance
	 */
	void setCom(AbstractCommunication *com);

	void setLevel(DEBUG_LEVEL lvl);
private:
	AbstractCommunication *com;
	static const String DEFAULT_LOCATION;
	DEBUG_LEVEL lvl;
};

#endif /* DEBUG_H_ */
