#include <Arduino.h>
#include "config/config.h"
#include "Debug.h"
#include "GlobalReceiver.h"

#ifdef SERIAL_COMMUNICATION
#include "SerialCom.h"
#endif

int ledPin = 13;    // LED connected to digital pin 13

AbstractCommunication *com;
GlobalReceiver *glrcv;
Debug *debug;

/**
 * @brief This function is only ran when the sketch is initialized.
 */
void setup() {
	pinMode(ledPin, OUTPUT);

#ifdef SERIAL_COMMUNICATION
	com = new SerialCom();
#endif

	debug->setLevel(Debug::WARN);
	debug->setCom(com);
	debug->info("Setting up led", "setup");

	glrcv->setCom(com);
}

/**
 * @brief loop() loops while Arduino is powered.
 */
void loop() {
	digitalWrite(ledPin, HIGH);
	debug->info("Will sleep for two seconds now.", "loop");
	delay(2000);
	digitalWrite(ledPin, LOW);
	delay(1000);
	glrcv->process();
}

/**
 * @brief where all the subsystems are started.
 * @return
 */
int main(void) {

	init();
	setup();

	while (true) {
		loop();
	}
}
