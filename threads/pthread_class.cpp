#include "pthread_class.hpp"


void *PthreadClass::entry_point(void *arg){
	auto self = static_cast<PthreadClass*>(arg);
	self->run();

	self->dispatch();

	return nullptr;
}

void PthreadClass::launch(){
	pthread_create(&this->thread, NULL, PthreadClass::entry_point, this);
}

void PthreadClass::run(){
	pthread_mutex_init(&this->cond_lock, NULL);

	this->setup();

	int i = 0;
	while(i < 10){
		this->waitDispatch();

		this->loop();
		i++;
	}
}

/**
 * @brief Releases execution lock.
 * 		Call at the end of the PthreadClass::loop() to immediately 
 * 		loop back to the beginning
 */
void PthreadClass::dispatch(){
	pthread_mutex_unlock(&this->cond_lock);
}

/**
 * @brief Waits for a signal to continue execution.
 * 		It locks the execution of the thread at each iteration
 * 		For continuous execution, use this->dispatch() at the end of
 * 		PthreadClass::loop()
 */
void PthreadClass::waitDispatch(){
	pthread_mutex_lock(&this->cond_lock);
}

void PthreadClass::join(){
	pthread_join(this->thread, NULL);
}
