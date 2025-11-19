#ifndef DATAOUT_HPP
#define DATAOUT_HPP

class Dataout
{
public:
	virtual int begin() = 0;
	virtual int write(const char *) = 0;
	virtual int fwrite(const char *, ...) = 0;
	virtual const char * read() = 0;
};

#endif // __DATAOUT_HPP
