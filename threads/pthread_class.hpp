#ifndef __PTHREAD_CLASS_HPP
#define __PTHREAD_CLASS_HPP

#include "threads.hpp"
#include <pthread.h>

/**
 * @class Wrapper class for Pthreads
 * @brief To test on Linux this class substitutes FreeRTOS-based 
 * 		class maintaining the interface
 */
class PthreadClass : private BaseThread 
{
private:
	pthread_mutex_t cond_lock;
	pthread_t thread;

public:
	PthreadClass() { this->begin(); };
	void begin() override;
	void launch() override;
	void dispatch() override;
	void waitDispatch() override;
	virtual void join() override;
	
	virtual void setup() = 0;
	virtual void loop() = 0;
};

#endif // __PTHREAD_CLASS_HPP