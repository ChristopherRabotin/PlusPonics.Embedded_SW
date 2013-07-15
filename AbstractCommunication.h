/*
 * AbstractCommunication.h
 *
 *  Created on: Jul 14, 2013
 *      Author: chris
 */

#ifndef ABSTRACTCOMMUNICATION_H_
#define ABSTRACTCOMMUNICATION_H_

#include <stdio.h>
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
	 * @brief This function sends information through the communication pipe.
	 * @param payload this is string which represents the payload to be delivered.
	 */
	virtual void send(String payload) = 0; // Should make AbstractCommunication unable to be instantiated.
	/**
	 * @brief This function reads data from the pipe and returns this as a string.
	 * @return a string representing the data received from the pipe.
	 */
	virtual String recv() = 0;
};

#endif /* ABSTRACTCOMMUNICATION_H_ */
