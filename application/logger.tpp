#include "logger.hpp"
#include <iostream>


/**
 * @brief Triggers the logging of an event
 * 		This is called from another thread and dispatches the 
 * 		communicator thread.
 */
template<ThreadInterface Thread>
void Logger<Thread>::eventTrigger(void *arg){
	if(this->dataout != nullptr){
		this->dataout->write((const char*)arg);
	}
	this->dispatch();
}


template<ThreadInterface Thread>
Logger<Thread>& Logger<Thread>::setDataout(Dataout *d){
	this->dataout = d;
	return *this;
}

template<ThreadInterface Thread>
void Logger<Thread>::setup(){
	return;
}

template<ThreadInterface Thread>
void Logger<Thread>::loop(){
	std::cout << "[Logger] Running logger" << std::endl;
	return;
}