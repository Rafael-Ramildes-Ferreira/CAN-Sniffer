#include "./sd_card.hpp"


int SdCard::begin(){
	return 1;
}

int SdCard::begin(const char *filename){
	// Yes, compiler. I know I'm not using it!
	(void)filename;

	return 1;
}

int SdCard::write(const char *){
	return 1;
}

int SdCard::fwrite(const char *, ...){
	return 1;
}

const char * SdCard::read(){
	return nullptr;
}

int SdCard::getAvailableSize(){
	return 1;
}

int SdCard::getUsedSize(){
	return 1;
}