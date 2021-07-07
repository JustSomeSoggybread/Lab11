/*

#include "LIS3DH.h"

#include <Blynk.h>

SYSTEM_THREAD(ENABLED);

SYSTEM_MODE(MANUAL);

LIS3DHSPI accel(SPI, D3, WKP);

// setup() runs once, when the device is first turned on.
void setup() {
   // Put initialization like pinMode and begin functions here.

	Blynk.begin("z9BVvrK3aRwDnJt8MBv-hT9hgOn6usrp", IPAddress(167, 172, 234, 162), 9090);

	pinMode(D3, INPUT);
  
	LIS3DHConfig config;

	config.setAccelMode(LIS3DH::RATE_100_HZ);

	SPI.setClockSpeed(2, MHZ);

	Serial.begin(9600);
	while (!Serial.isConnected());

	Wire.begin();   
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  	// The core of your code will likely live here.
	 Blynk.run();

	LIS3DHSample sample;
	if (accel.getSample(sample)) {
		Serial.printlnf("%d,%d,%d", sample.x, sample.y, sample.z);
	}

}
*/


/*
#include "Particle.h"

#include "LIS3DH.h"

// Electron sample to print accelerometer samples to serial
// (also works on the Photon, P1, Core)

SYSTEM_THREAD(ENABLED);

// This sample only uses serial, not data, so cellular is turned off to save data
SYSTEM_MODE(MANUAL);

// Print 10 samples per second to serial
const unsigned long PRINT_SAMPLE_PERIOD = 100;

// LIS3DH is connected as in the AssetTracker, to the primary SPI with A2 as the CS (SS) pin, and INT connected to WKP
LIS3DHSPI accel(SPI, D3, WKP);

unsigned long lastPrintSample = 0;

void setup() {
	Serial.begin(9600);

	delay(5000);

	// Initialize sensors
	LIS3DHConfig config;
	config.setAccelMode(LIS3DH::RATE_100_HZ);

	bool setupSuccess = accel.setup(config);
	Serial.printlnf("setupSuccess=%d", setupSuccess);
}

void loop() {

	if (millis() - lastPrintSample >= PRINT_SAMPLE_PERIOD) {
		lastPrintSample = millis();

		LIS3DHSample sample;
		if (accel.getSample(sample)) {
			Serial.printlnf("%d,%d,%d", sample.x, sample.y, sample.z);
		}
		else {
			Serial.println("no sample");
		}
	}
}
*/

#include "LIS3DH.h"

// Electron sample to print accelerometer samples to serial
// (also works on the Photon, P1, Core)

SYSTEM_THREAD(ENABLED);

// This sample only uses serial, not data, so cellular is turned off to save data
SYSTEM_MODE(MANUAL);

// Print 10 samples per second to serial
const unsigned long PRINT_SAMPLE_PERIOD = 100;

// LIS3DH is connected as in the AssetTracker, to the primary SPI with A2 as the CS (SS) pin, and INT connected to WKP
LIS3DHSPI accel(SPI, D3, WKP);

unsigned long lastPrintSample = 0;

void setup() {
	Serial.begin(9600);

	delay(5000);

	// Initialize sensors
	LIS3DHConfig config;
	config.setAccelMode(LIS3DH::RATE_100_HZ);

	bool setupSuccess = accel.setup(config);
	Serial.printlnf("setupSuccess=%d", setupSuccess);
}

void loop() {

	if (millis() - lastPrintSample >= PRINT_SAMPLE_PERIOD) {
		lastPrintSample = millis();

		LIS3DHSample sample;
		if (accel.getSample(sample)) {
			Serial.printlnf("%d,%d,%d", sample.x, sample.y, sample.z);
		}
		else {
			Serial.println("no sample");
		}
	}
}