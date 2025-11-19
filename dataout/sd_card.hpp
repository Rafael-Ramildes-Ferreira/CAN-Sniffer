#ifndef SD_CARD_HPP
#define SD_CARD_HPP

#include "./dataout.hpp"

#ifdef __linux__
#include <stdio.h>
#else
#define FILE void*
#endif

class SdCard : public Dataout
{
private:
	int available_size;
	FILE file;
public:
	int begin() override;
	int begin(const char *filename);

	int write(const char *) override;
	int fwrite(const char *, ...) override;
	const char * read() override;

	int getAvailableSize();
	int getUsedSize();
};

#endif // SD_CARD_HPP