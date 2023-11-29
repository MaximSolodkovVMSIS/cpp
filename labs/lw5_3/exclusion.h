#pragma once
#include <iostream>
#include <cstring>


class Exception {
public: 
	Exception();
	Exception(int errorCode, const char* errorMessage);
	void show() const;

private:
	char text[256];
	int code;
};

class IntException : public Exception {
public: 
	IntException(const char* errorMessage);
};

class CharArrayException : public Exception {
public: 
	CharArrayException(const char* errorMessage);
};
