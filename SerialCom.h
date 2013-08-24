/*
 * SerialCom.h
 *
 *  Created on: Jul 15, 2013
 *      Author: chris
 */

#ifndef SERIALCOM_H_
#define SERIALCOM_H_

#include "AbstractCommunication.h"
#include <Arduino.h>
#include <HardwareSerial.h> // TODO Eventually use SoftSerial.h since it uses interrupts to read incoming messages.
// #include <SoftwareSerial.h>
/**
 * \class SerialCom
 * \brief This class defines serial communication with the control system.
 */
class SerialCom: public AbstractCommunication {
public:
	SerialCom();
	virtual ~SerialCom();
	virtual void init();
	virtual void send(String payload);
	virtual String recv();
};

#endif /* SERIALCOM_H_ */
