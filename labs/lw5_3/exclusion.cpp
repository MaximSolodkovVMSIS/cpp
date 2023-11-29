#include "exclusion.h"

Exception::Exception(){
	code = 0;
	text[0] = '\0';
}

Exception::Exception(int errorCode, const char* errorMessage){
	code = errorCode;
	strcpy_s(this->text, errorMessage);
}

void Exception::show() const{
	std::cout << "\nError code: " << code << "\nMessage: " << text << std::endl;
}

IntException::IntException(const char* errorMessage) : Exception(1, errorMessage) {}
CharArrayException::CharArrayException(const char* errorMessage) : Exception(2, errorMessage) {}
