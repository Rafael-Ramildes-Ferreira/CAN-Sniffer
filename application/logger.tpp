#include "logger.hpp"
#include <iostream>


/**
 * @brief Triggers the logging of an event
 * 		This is called from another thread and dispatches the 
 * 		communicator thread.
 */
template<ThreadInterface Thread>
void Logger<Thread>::eventTrigger(void *arg){
	// memcpy()
	std::cout << "[Logger] Receive an event!" << std::endl;
	this->dispatch();
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