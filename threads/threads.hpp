#ifndef __THREADS_HPP
#define __THREADS_HPP

#include <type_traits>

/**
 * @class BaseThread
 * @brief Defines the interface of a thread class
 * 		Can be enforeced in compiletime after C++20
 */
class BaseThread
{
public:
	/**
	 * @brief Launches the thread in a platform-agnostic signature.
	 * 		Call BaseThread::launch() in the object to start 
	 * 		execution without directly access the OS interface.
	 */
	virtual void launch() = 0;

	/**
	 * @brief Launches the BaseThread::setup and BaseThread::loop.
	 * 		This initializes and uses the lock to halt execution at
	 * 		the end of each iteration.
	 */
	virtual void run() = 0;

	/**
	 * @brief Releases execution lock.
	 * 		Call at the end of the BaseThread::loop() to immediately 
	 * 		loop back to the beginning
	 */
	virtual void dispatch() = 0;
	

	/**
	 * @brief Waits for a signal to continue execution.
	 * 		It locks the execution of the thread at each iteration
	 * 		For continuous execution, use this->dispatch() at the end of
	 *		BaseThread::loop()
	 */
	virtual void waitDispatch() = 0;

	/**
	 * @brief Implemented by the end user to configure the 
	 * 		application.
	 */
	virtual void setup() = 0;

	/**
	 * @brief Implemented by the end user to execute in loop.
	 */
	virtual void loop() = 0;

	/**
	 * @brief Waits for the thread to finish execution.
	 * 		This implements a platform-agnostic signature.
	 */
	virtual void join() = 0;
};

/**
 * @interface Defines the thread interface
 * @brief Enforces a thread class follows the interface
 * 		(only after C++20)
 */
#if __cplusplus >= 202002L
template<class Base>
concept ThreadInterface = 
	std::is_base_of_v<BaseThread,Base> &&
    !std::is_same_v<BaseThread,Base>;
#else
#define ThreadInterface class
#endif

class FreeRTOSThread : public BaseThread {};

#endif // __THREADS_HPP