/*
 * SerialCom.cpp
 *
 *  Created on: Jul 15, 2013
 *      Author: chris
 */

#include "SerialCom.h"

SerialCom::SerialCom() {

}

SerialCom::~SerialCom() {
}

void SerialCom::init() {
	Serial.begin(9600);
}

void SerialCom::send(String payload) {
	Serial.println(payload);
}

/**
 * @brief This function reads the serial input and returns all the information it reads at the time of calling.
 * @return the string received through serial communication.
 */
String SerialCom::recv() {
	String rtn = "";
	if (Serial.available()) {
		rtn = Serial.readString();
	}
	return (rtn);
}
