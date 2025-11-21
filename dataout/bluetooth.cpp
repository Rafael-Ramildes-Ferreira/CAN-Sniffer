#include "./bluetooth.hpp"

#include <stdio.h>
#include <string.h>

inline const char SERVICE_UUID[] = "d954d273-3c61-493e-a46e-20789c69cab2";
inline const char CHARACT_UUID[] = "f3b645fc-8de9-45ae-b4e4-d0da295bd30f";

volatile bool BlueTooth::conected = false; 

// It is limited by the app I'm using to read the Bluetooth
// Maybe I'm being dumb :P
inline const uint16_t MTU_MAX_SIZE = 23;


template<typename T>
inline T min(T p1, T p2){
	return (p1<p2)?p1:p2;
}

int BlueTooth::begin(){
	if(!NimBLEDevice::init(this->ssid) || !NimBLEDevice::setMTU(MTU_MAX_SIZE)){
		return 1;
	}

	this->server = NimBLEDevice::createServer();
	this->server->setCallbacks(new ConnectionServerCallbacks());
	this->service = this->server->createService(SERVICE_UUID);
	this->characteristic = this->service->createCharacteristic(CHARACT_UUID,
		NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::NOTIFY);
	auto descriptor = new NimBLE2904();
	descriptor->setFormat(NimBLE2904::FORMAT_UTF8);
	this->characteristic->addDescriptor(descriptor);
	this->characteristic->setValue("No new messages!");

	this->service->start();

	this->advertising = NimBLEDevice::getAdvertising();
    this->advertising->setName(this->ssid);
	this->advertising->addServiceUUID(this->service->getUUID());
	// pAdvertising->setScanResponse(true);
	// pAdvertising->setMinPreferred(0x04);  // (0x06) functions that help with iPhone connections issue
	// // pAdvertising->setMinPreferred(0x12);
	NimBLEDevice::startAdvertising();

	return 0;
}


int BlueTooth::write(const char *text){
	int totalLen = strlen(text);
	const int PACKET_SIZE = NimBLEDevice::getMTU() - 3;
	char buffer[PACKET_SIZE];

	for(int i = 0; i < totalLen; i += PACKET_SIZE - 1) {
		int chunk = min(PACKET_SIZE - 1, totalLen - i);
		memcpy(buffer, text + i, chunk);
		buffer[chunk] = '\0';

		this->characteristic->setValue(buffer);
		if(!this->characteristic->notify()){
			return 1;
		}
		vTaskDelay(100/portTICK_PERIOD_MS);  // [Todo: add delay method in thread class]
	}
	return 0;
}

int BlueTooth::fwrite(const char *text, ...){
	va_list args;
	char ftext[MTU_MAX_SIZE-3];
	va_start(args, text);
	sprintf(ftext, text, args);
	va_end(args); 

	return this->write(ftext);
}

const char * BlueTooth::read(){
	return 0;
}
