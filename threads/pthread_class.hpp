#ifndef __PTHREAD_CLASS_HPP
#define __PTHREAD_CLASS_HPP

#include "threads.hpp"
#include <pthread.h>

/**
 * @class Wrapper class for Pthreads
 * @brief To test on Linux this class substitutes FreeRTOS-based 
 * 		class maintaining the interface
 */
class PthreadClass : public BaseThread 
{
private:
	pthread_mutex_t cond_lock;
	pthread_cond_t cond;
	pthread_t thread;

	static void *entry_point(void *arg);

public:
	void launch() override;
	void run() override;
	void dispatch() override;
	void waitDispatch() override;
	virtual void setup() = 0;
	virtual void loop() = 0;
	virtual void join() override;
};

#endif // __PTHREAD_CLASS_HPP