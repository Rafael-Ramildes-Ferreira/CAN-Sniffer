#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include "../threads/threads.hpp"


template<ThreadInterface Thread>
class Communicator : public Thread{
private:
	void (*message_received_hook)(void*);
public:
	Communicator() : message_received_hook(nullptr) {};
	void setMessageReceivedHook(void *func);

	void setup() override;
	void loop() override;
};

#endif // COMMUNICATOR_HPP