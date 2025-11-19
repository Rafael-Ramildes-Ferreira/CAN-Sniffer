#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include "./dataout.hpp"
#include <stdio.h>
#include <cstdarg>

class SerialPort : public Dataout
{
public:
	// ESP-IDF already starts the serial port for printing.
	int begin() override { return 0; };
	int write(const char *text) override { printf(text); return 0; };
	int fwrite(const char *text, ...) override { 
		va_list args;
		va_start(args, text);
		// vprintf(text, args);
		printf(text, args);
		va_end(args); 
		return 0; 
	};
	const char * read() override { return nullptr; };
};

#endif // SERIALPORT_HPP