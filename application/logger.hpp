#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "../threads/threads.hpp"
#include "../dataout/dataout.hpp"


template<ThreadInterface Thread>
class Logger : public Thread
{
private:
	Dataout *dataout;
public:
	void eventTrigger(void *arg);

	Logger& setDataout(Dataout *d);
	
	void setup() override;
	void loop() override;
};

#include "logger.tpp"

#endif // LOGGER_HPP