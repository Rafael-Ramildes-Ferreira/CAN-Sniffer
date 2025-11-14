#include "application/logger.hpp"
#include "application/communicator.hpp"
#include <functional>

#ifdef __linux__
#include "threads/pthread_class.hpp"
#define THREAD PthreadClass
#else // __linux__
#include "threads/freertos_thread.hpp"
#define THREAD FreeRTOSThread
#endif // Not __linux__ 


void sniffer_main(){
	Communicator<THREAD> t;
	Logger<THREAD> t2;

	std::function<void(void*)> logger_hook (
		[&t2](void*arg)->void {
			t2.eventTrigger(arg);
		}
	);

	t.setMessageReceivedHook(&logger_hook);
	char name1[] = "Communicator";
	t.setName(name1,sizeof(name1));
	char name2[] = "Logger";
	t2.setName(name2,sizeof(name2));

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
