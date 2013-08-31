#include <Arduino.h>
#include "config/config.h"
#include "GlobalReceiver.h"
#include "DigitalWriteTC.h"

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
DigitalWriteTC led13_ON = DigitalWriteTC(ledPin, HIGH);
DigitalWriteTC led13_OFF = DigitalWriteTC(ledPin, LOW);

/**
 * @brief This function is only ran when the sketch is initialized.
 */
void setup() {

	led13_ON.init();
	led13_OFF.init();

	com.init();
	com.setLevel(AbstractCommunication::WARN);
	com.info("Setting up led", "setup");
	glrcv.setCom(com);
}

/**
 * @brief loop() loops while Arduino is powered.
 */
void loop() {
	led13_ON.exec();
	delay(2000);
	led13_OFF.exec();
	delay(2000);
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
