#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "../threads/threads.hpp"


template<ThreadInterface Thread>
class Logger : public Thread{
public:
	void eventTrigger(void *arg);
	
	void setup() override;
	void loop() override;
};

#endif // LOGGER_HPP