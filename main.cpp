#include <Arduino.h>
#include "config/config.h"
#include "GlobalReceiver.h"

/* The following includes enable STL for Arduino. */
#include <iterator>
#include <map>
#include <pnew.cpp> // pnew must be used the very last include.
/**
 * The following definition is only to avoid the warning when writing to Flash with PROGMEM.
 */
#ifdef PROGMEM
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#endif

#ifdef SERIAL_COMMUNICATION
#include "SerialCom.h"
#endif

int ledPin = 13;    // LED connected to digital pin 13

SerialCom com;
GlobalReceiver glrcv;

//std::map<int, const char *> TM_LIST;

/**
 * @brief This function is only ran when the sketch is initialized.
 */
void setup() {
	pinMode(ledPin, OUTPUT);
	com.init();
	com.setLevel(AbstractCommunication::WARN);
	com.info("Setting up led", "setup");
	glrcv.setCom(com);
}

/**
 * @brief loop() loops while Arduino is powered.
 */
void loop() {
	digitalWrite(ledPin, HIGH);
	delay(2000);
	digitalWrite(ledPin, LOW);
	delay(1000);
	glrcv.process();
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
