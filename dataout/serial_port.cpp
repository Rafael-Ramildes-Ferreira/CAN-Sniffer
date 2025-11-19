#include "./serial_port.hpp"


int SerialPort::begin()
{ 
	return 0;
};

int SerialPort::write(const char *text){ 
	printf(text); return 0; 
};

int SerialPort::fwrite(const char *text, ...){ 
	va_list args;
	va_start(args, text);
	printf(text, args);
	va_end(args); 
	return 0; 
};

const char * SerialPort::read(){ 
	return nullptr; 
};