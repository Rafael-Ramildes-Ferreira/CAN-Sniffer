#include "application/logger.hpp"
#include "application/communicator.hpp"

#ifdef __linux__
#include "threads/pthread_class.hpp"
#include <iostream>
#endif // __linux__



template<ThreadInterface Thread>
class Teste : public Thread
{
public:
	void setup() override {
		std::cout << "Iniciando uma thread, yay!" << std::endl;
	}
	void loop() override {
		for(long int i = 0; i < 100000000; i++);
		std::cout << "I can do this all day!" << std::endl;

		this->dispatch();
	}
};

void app_main(){
	Teste<PthreadClass> t;
	Teste<PthreadClass> t2;

	t.launch();
	t2.launch();

	t.join();
	t2.join();

	return;
}

#ifdef __linux__
int main(){
	app_main();
	return 0;
}
#endif // __linux__