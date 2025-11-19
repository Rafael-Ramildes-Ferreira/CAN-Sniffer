#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP

#include "./dataout.hpp"

#ifdef __linux__
#error "Bluetooth is an invalid package for linux environment!"
#else

#include <NimBLEDevice.h>
#include <NimBLEServer.h>


/**
 * @brief Class to deal with setup and running of the periadical Bluetooth transmit
 * routine
*/
class BlueTooth : public Dataout
{
private:
	const char* ssid; // Nome do seu ponto de acesso

	NimBLEServer *server;
	NimBLEService *service;
	NimBLECharacteristic *characteristic;
	NimBLEAdvertising *advertising;

public:
	BlueTooth() : 
		ssid("Sniffer Bluetooth"), server(nullptr), service(nullptr),
		characteristic(nullptr), advertising(nullptr) {};

	int begin() override;
	
	int write(const char *) override;
	int fwrite(const char *, ...) override;
	const char * read() override;
	
	static volatile bool conected;
};


/**
 * @brief 	Holds callback functions for when a bluetooth conection happens
 */
class ConnectionServerCallbacks : public NimBLEServerCallbacks
{
public:
	void onConnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo) override{
		BlueTooth::conected = true;
	};

	void onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason) override{
		NimBLEDevice::startAdvertising();
		BlueTooth::conected = false;
	}
};

#endif
#endif // BLUETOOTH_HPP