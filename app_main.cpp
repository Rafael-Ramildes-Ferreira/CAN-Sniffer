#include "application/logger.hpp"
#include "application/communicator.hpp"
#include <functional>

#ifdef __linux__
#include "threads/pthread_class.hpp"
#include <iostream>
#else // __linux__
#include "threads/freertos_thread.hpp"
#endif // Not __linux__ 



void sniffer_main(){
	Communicator<FreeRTOSThread> t;
	Logger<FreeRTOSThread> t2;

	std::function<void(void*)> logger_hook (
		[&t2](void*arg)->void {
			t2.eventTrigger(arg);
		}
	);

	t.setMessageReceivedHook(&logger_hook);

	t.launch();
	t2.launch();

	t.join();
	t2.join();

	return;
}

#ifdef __linux__
int main(){
	sniffer_main();
	return 0;
}
#endif // __linux__
