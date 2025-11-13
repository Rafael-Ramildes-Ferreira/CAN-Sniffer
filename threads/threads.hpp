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
	virtual void launch() = 0;
	virtual void run() = 0;
	virtual void dispatch() = 0;
	virtual void setup() = 0;
	virtual void loop() = 0;
	virtual void join() = 0;
};

/**
 * @interface Defines the interface of the thread
 * @brief Inforces a thread class follows the interface
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