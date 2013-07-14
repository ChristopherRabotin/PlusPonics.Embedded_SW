#include <Arduino.h>
#include "config/config.h"

#ifdef SERIAL_COM //TODO a better way in order to distinguish different communication types.
#include "SerialCom.h"
#include "Debug.h"
#endif

int ledPin = 13;    // LED connected to digital pin 13

AbstractCommunication *com;
Debug *debug = new Debug(com);

// The setup() method runs once, when the sketch starts
void setup() {
	// initialize the digital pin as an output:
	pinMode(ledPin, OUTPUT);
	//debug->info("Setting up led", "setup");
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop() {
	digitalWrite(ledPin, HIGH);   // set the LED on
	//debug->warn("Will sleep for two seconds now.", "loop");
	delay(2000);                  // wait for a second
	digitalWrite(ledPin, LOW);    // set the LED off
	delay(1000);                  // wait for a second
}

int main(void) {

	init();
#ifdef SERIAL_COM
	com = new SerialCom();
#endif
	//debug = new Debug(com);
	setup();

	while (true) {
		loop();
	}
}
