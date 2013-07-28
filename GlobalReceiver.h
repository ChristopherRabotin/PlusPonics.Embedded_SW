/*
 * GlobalReceiver.h
 *
 *  Created on: Jul 21, 2013
 *      Author: chris
 */

#ifndef RECVPROCESSOR_H_
#define RECVPROCESSOR_H_

#include "AbstractCommunication.h"

class GlobalReceiver {
public:
	GlobalReceiver();
	/**
	 * @brief This function fetches and processes the input. It calls com's recv() to read the latest information.
	 * <h1>Communicating to the pod</h1>
	 * This first three bits are the type of action requested. There are currently only four actions defines, but we
	 * use three bits in order to leave space for more actions later.
	 * Only the first three bits are read in this function. All the rest is sent to the appropriate AbstractReceiverProcessor.
	 * <h2>Defined actions</h2>
	 * <h3>Command: 000b</h3>
	 * <p>This is how ask the pod to execute a given command.</p>
	 * <h3>Procedure: 001b</h3>
	 * <p>This is how to start an embedded procedure on the pod.</p>
	 * <h3>Telemetery information: 010b</h3>
	 * <p>This allows to request telemetry information of any given telemetry in the next telemetry frame.</p>
	 * <h3>Meta: 011b</h3>
	 * <p>This includes commands related to meta around the pod, not its operational commands.</p>
	 */
	void process();
	/**
	 * @brief This function sets the communication pointer. This is used when the empty constructor is used.
	 * @param com communication instance
	 */
	void setCom(AbstractCommunication *com);
	virtual ~GlobalReceiver();
private:
	AbstractCommunication *com;
};

#endif /* RECVPROCESSOR_H_ */
