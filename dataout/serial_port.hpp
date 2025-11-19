#ifndef SERIALPORT_HPP
#define SERIALPORT_HPP

#include "./dataout.hpp"
#include <stdio.h>
#include <cstdarg>

class SerialPort : public Dataout
{
public:
	// ESP-IDF already starts the serial port for printing.
	int begin() override;
	int write(const char *text) override;
	int fwrite(const char *text, ...) override;
	const char * read() override;
};

#endif // SERIALPORT_HPP