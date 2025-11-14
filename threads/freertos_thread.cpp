#ifndef __linux__
#include "freertos_thread.hpp"

#include <iostream>


void FreeRTOSThread::begin(){
	this->cond_lock = xSemaphoreCreateBinary();
	if(this->cond_lock == NULL){
		std::cout << "Failed to create lock" << std::endl;
	} else {
		std::cout << "Created semaphore " << this->cond_lock << std::endl;
	}
	xSemaphoreGive(this->cond_lock);
}

void FreeRTOSThread::launch(){
	this->join_lock = xSemaphoreCreateBinary();
	if(this->join_lock == NULL){
		std::cout << "Failed to create lock" << std::endl;
	}
	xTaskCreate(
		(void(*)(void*))BaseThread::entry_point,	// TaskFunction_t (a.k.a. void(*)(void*)) pvTaskCode,
		this->name, 								// const char * const pcName,
		this->stack_depth, 							// const configSTACK_DEPTH_TYPE (a.k.a. unsigned int) uxStackDepth,
		this, 										// void *pvParameters,
		this->priority, 							// UBaseType_t (a.k.a. unsigned int) uxPriority,
		&this->thread								// TaskHandle_t *pxCreatedTask
	);
}

void FreeRTOSThread::dispatch(){
	xSemaphoreGive(this->cond_lock);
}

void FreeRTOSThread::waitDispatch(){
	while(xSemaphoreTake(this->cond_lock,portMAX_DELAY) != pdTRUE);
}

void FreeRTOSThread::join(){
	while(xSemaphoreTake(this->join_lock,portMAX_DELAY) != pdTRUE);
}



void FreeRTOSThread::setName(const char* n, int size) {
	if (size < FreeRTOSThread::MAX_NAME_SIZE) {
		strncpy(this->name, n, size);
	} else {
		name[0] = '\0';
	}
}

void FreeRTOSThread::setPriority(UBaseType_t p) {
	priority = p;
}

void FreeRTOSThread::setStackDepth(configSTACK_DEPTH_TYPE depth) {
	stack_depth = depth;
}

#endif // __linux__