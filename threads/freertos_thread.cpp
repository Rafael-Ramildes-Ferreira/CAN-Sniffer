#include "freertos_thread.hpp"


void FreeRTOSThread::begin(){
	// pthread_mutex_init(&this->cond_lock, NULL);
	return;
}

void FreeRTOSThread::launch(){
	// pthread_create(&this->thread, NULL, BaseThread::entry_point, this);
	return;
}

void FreeRTOSThread::dispatch(){
	// pthread_mutex_unlock(&this->cond_lock);
	return;
}

void FreeRTOSThread::waitDispatch(){
	// pthread_mutex_lock(&this->cond_lock);
	return;
}

void FreeRTOSThread::join(){
	// pthread_join(this->thread, NULL);
	return;
}
