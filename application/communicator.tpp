#include "communicator.hpp"
#include <iostream>


template<ThreadInterface Thread>
Communicator<Thread>& Communicator<Thread>::setMessageReceivedHook(std::function<void(void*)> *func) {
	this->message_received_hook = func;
	return *this; 
};


template<ThreadInterface Thread>
void Communicator<Thread>::setup() {
	// Initialize communication interfaces
	// Configure CAN bus, serial ports, etc.
	return;
}

template<ThreadInterface Thread>
void Communicator<Thread>::loop() {
	for(long int i = 0; i < 10000000; i++);
	std::cout << "[Comm] Receiving message!" << std::endl;
	if(this->message_received_hook != nullptr){
		(*this->message_received_hook)((void*)"[Comm] I've sent a message to Logger!\n");
	}

	this->dispatch();
}