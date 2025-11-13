#ifndef __FREERTOS_CLASS_HPP
#define __FREERTOS_CLASS_HPP

#include "threads.hpp"
#include "freertos/FreeRTOS.h"

/**
 * @class Wrapper class for FreeRTOS threads
 * @brief To run embedded in FreeRTOS-based platform.
 */
class FreeRTOSThread : private BaseThread 
{
private:
	// pthread_mutex_t cond_lock;
	TaskHandle_t thread;

public:
	void begin() override;
	void launch() override;
	void dispatch() override;
	void waitDispatch() override;
	virtual void join() override;
	
	virtual void setup() = 0;
	virtual void loop() = 0;
};

#endif // __FREERTOS_CLASS_HPP