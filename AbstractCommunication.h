/*
 * AbstractCommunication.h
 *
 *  Created on: Jul 14, 2013
 *      Author: chris
 */

#ifndef ABSTRACTCOMMUNICATION_H_
#define ABSTRACTCOMMUNICATION_H_

#include <WString.h>
/**
 * \class AbstractCommunication
 * \brief This class defines how all communication should be done.
 */
class AbstractCommunication {
public:
	AbstractCommunication();
	virtual ~AbstractCommunication();
	virtual void send(String payload) = 0; // Should make AbstractCommunication unable to be instantiated.
	virtual String recv() = 0;
};

#endif /* ABSTRACTCOMMUNICATION_H_ */
