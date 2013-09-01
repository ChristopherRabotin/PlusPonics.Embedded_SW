/*
 * GlobalReceiver.h
 *
 *  Created on: Jul 21, 2013
 *      Author: chris
 */

#ifndef RECVPROCESSOR_H_
#define RECVPROCESSOR_H_

#include "AbstractCommunication.h"
#include "TCProcessor.h"

/**
 * @namespace Processors
 * @brief This namespace handles the processing input/output to/from the pod.
 * This includes commanding a pod, sending telemetry, debugging messages, procedure handling and meta functions.
 */
namespace Processors {
/**
 * @class GlobalReceiver
 * @brief This class is the overall handler for receiving input over whichever means of Communicators::AbstractCommunication.
 * @note Documentation of this class explains how to communicate with the pod!
 */
class GlobalReceiver {
public:
	GlobalReceiver();
	/**
	 * @brief This function fetches and processes the input. It calls com's recv() to read the latest information.
	 * <h1>Communicating to the pod</h1>
	 * This character (of the String) is the type of action requested. There are currently only four actions defines, but we
	 * use a full character in order to leave space for more actions later, but especially because of ease of testing.
	 * Only the first character is read in this function. All the rest are sent to the appropriate AbstractReceiverProcessor.
	 * <h2>Defined actions</h2>
	 * <h3>Command: "1"</h3>
	 * <p>This is how ask the pod to execute a given command.</p>
	 * <h3>Procedure: "3"</h3>
	 * <p>This is how to start an embedded procedure on the pod.</p>
	 * <h3>Telemetery information: "5"</h3>
	 * <p>This allows to request telemetry information of any given telemetry in the next telemetry frame.</p>
	 * <h3>Meta: "7"</h3>
	 * <p>This includes commands related to meta around the pod, not its operational commands.</p>
	 */
	void process();

	/**
	 * @brief This function sets the communication pointer. This is used when the empty constructor is used.
	 * @param comInstance communication instance
	 */
	void setCom(Communicators::AbstractCommunication &comInstance);

	/**
	 * @brief This function sets the TC processor. This is used when the empty constructor is used.
	 * @param tcProcInstance TCProcessor instance
	 */
	void setTCProcessor(TCProcessor &tcProcInstance);
	virtual ~GlobalReceiver();
private:
	Communicators::AbstractCommunication *_com;
	TCProcessor *_tcProcessor;
};
}
#endif /* RECVPROCESSOR_H_ */
