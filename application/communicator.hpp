#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include "../threads/threads.hpp"
#include <functional>


template<ThreadInterface Thread>
class Communicator : public Thread{
private:
	std::function<void(void*)> *message_received_hook;
public:
	Communicator() : message_received_hook(nullptr) {};
	
	Communicator& setMessageReceivedHook(std::function<void(void*)> *func);

	void setup() override;
	void loop() override;
};

#include "communicator.tpp"

#endif // COMMUNICATOR_HPP