#include "pthread_class.hpp"


void *PthreadClass::entry_point(void *arg){
	auto self = static_cast<PthreadClass*>(arg);
	self->run();

	return nullptr;
}

void PthreadClass::launch(){
	pthread_create(&this->thread, NULL, PthreadClass::entry_point, this);
}

void PthreadClass::run(){
	this->setup();

	int i = 0;
	while(i < 10){
		this->loop();
		i++;
	}
}

void PthreadClass::dispatch(){
	return;
}

void PthreadClass::join(){
	pthread_join(this->thread, NULL);
}
