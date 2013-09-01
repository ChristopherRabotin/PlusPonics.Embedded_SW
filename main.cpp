#include <Arduino.h>
#include "config/config.h"
#include "GlobalReceiver.h"
#include "LogicTC.h"
#include "TCProcessor.h"

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

Communicators::SerialCom com;
GlobalReceiver glrcv;
TCProcessor tcProcessor;

/**
 * @brief This function is only ran when the sketch is initialized.
 */
void setup() {

	tcProcessor.init();

	com.init();
	com.setLevel(Communicators::AbstractCommunication::INFO);
	com.info("Setting up led", "setup");
	glrcv.setCom(com);
	glrcv.setTCProcessor(tcProcessor);
}

/**
 * @brief loop() loops while Arduino is powered.
 */
void loop() {
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

	/* Let's turn on the LED. The user will turn it off from Serial. */
	tcProcessor.perform(TCProcessor::EXECUTE, 1);

	while (true) {
		loop();
	}
}
