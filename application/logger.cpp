#include "logger.hpp"


/**
 * @brief Triggers the logging of an event
 * 		This is called from another thread and dispatches the 
 * 		communicator thread.
 */
template<ThreadInterface Thread>
void Logger<Thread>::eventTrigger(void *arg){
	// memcpy()
	this->dispatch();
}

template<ThreadInterface Thread>
void Logger<Thread>::setup(){
	return;
}

template<ThreadInterface Thread>
void Logger<Thread>::loop(){
	return;
}