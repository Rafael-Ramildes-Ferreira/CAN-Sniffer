#ifndef __FREERTOS_CLASS_HPP
#define __FREERTOS_CLASS_HPP

#include "threads.hpp"
#include "freertos/FreeRTOS.h"

#include <string.h>


/**
 * @class Wrapper class for FreeRTOS threads
 * @brief To run embedded in FreeRTOS-based platform.
 */
class FreeRTOSThread : private BaseThread 
{
private:
	/* Constants ---------------------------------------------------*/
	static inline const unsigned int MAX_NAME_SIZE = 20;

	/* Thread config -----------------------------------------------*/
	TaskHandle_t thread;
	char name[FreeRTOSThread::MAX_NAME_SIZE];
	UBaseType_t priority;
	configSTACK_DEPTH_TYPE stack_depth;

	/* Attrib for platform specific method implementation ----------*/
	SemaphoreHandle_t cond_lock;
	SemaphoreHandle_t join_lock; 	// I cannot join, but it is never 
									// supposed to end the execution.

public:
	FreeRTOSThread() : 
		thread(NULL), name("nameless"), priority(3), stack_depth(2048),
		cond_lock(NULL), join_lock(NULL) { this->begin(); };

	void begin() override;
	void launch() override;
	void dispatch() override;
	void waitDispatch() override;
	virtual void join() override;

	void setName(const char* n, int size);
	void setPriority(UBaseType_t p);
	void setStackDepth(configSTACK_DEPTH_TYPE depth);
	
	virtual void setup() = 0;
	virtual void loop() = 0;
};

#endif // __FREERTOS_CLASS_HPP