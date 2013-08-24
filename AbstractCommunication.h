/*
 * AbstractCommunication.h
 *
 *  Created on: Jul 14, 2013
 *      Author: chris
 */

#ifndef ABSTRACTCOMMUNICATION_H_
#define ABSTRACTCOMMUNICATION_H_

#include <stdio.h>
#include <stdarg.h>
#include <WString.h>
/**
 * @class AbstractCommunication
 * @brief This class defines how all communication should be done.
 */
class AbstractCommunication {
public:
	AbstractCommunication();
	virtual ~AbstractCommunication();
	/**
	 * @brief This function initializes the communication. It will be called from the setup function.
	 */
	virtual void init() = 0;
	/**
	 * @brief This function sends information through the communication pipe.
	 * @param payload this is string which represents the payload to be delivered.
	 */
	virtual void send(String payload) = 0; // Should make AbstractCommunication unable to be instantiated.
	/**
	 * @brief This function reads data from the pipe and returns this as a string.
	 * @return a string representing the data received from the pipe.
	 */
	virtual String recv() = 0;

	/**
	 * @brief This function sends a formatted string through the communication pipe.
	 * @param payload this is the string to be formatted with the additional arguments. Works just like printf.
	 */
	void sendf(String payload, ...);
	/**
	 * @enum DEBUG_LEVEL Defines different levels of debugging.
	 */
	enum DEBUG_LEVEL {
		INFO = 0, /**< this is the info level */
		WARN = 5, /**< this is the warning level */
		ERROR = 10 /**< this is the error level */
	};

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

	void setLevel(DEBUG_LEVEL lvl);
private:
	static const String DEFAULT_LOCATION;
	DEBUG_LEVEL lvl;
};

#endif /* ABSTRACTCOMMUNICATION_H_ */
