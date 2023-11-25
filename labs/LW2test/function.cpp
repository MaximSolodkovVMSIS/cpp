#include "Header.h"

MyString::MyString() {
	std::cout << "Constructor without parametrs was created" << std::endl;
	str = nullptr;
}

MyString::MyString(const char* s) {
	std::cout << "Constructor with parametrs was created" << std::endl;
	if (s != nullptr) {
		size_t len = strlen(s);
		str = new char[len + 1];
		strcpy_s(str, len + 1, s);
	}
	else
		str = nullptr;
}
MyString::MyString(const MyString& other) {
	std::cout << "Copy constructor with parametrs was created" << std::endl;
	if (other.str != nullptr) {
		size_t len = strlen(other.str);
		str = new char[len + 1];
		strcpy_s(str, len + 1, other.str);
	}
	else
		str = nullptr;
}

MyString::~MyString() {
	std::cout << "The destructor was called" << std::endl;
	delete[] str;
}

MyString& MyString::operator=(const MyString& other) {
	if (this == &other) {
		return *this;
	}
	if (other.str != nullptr) {
		size_t len = strlen(other.str);
		delete[] str;
		str = new char[len + 1];
		strcpy_s(str, len + 1, other.str);
	}
	else {
		delete[] str;
		str = nullptr;
	}
}

MyString MyString::operator+(const MyString& other) {
	MyString result;
	
	if (str != nullptr && other.str != nullptr) {
		size_t len1 = strlen(str);
		size_t len2 = strlen(other.str);
		size_t resultLen = len1 + len2;
		result.str = new char[resultLen + 1];
		strcpy_s(result.str, len1 + 1, str);
		strcat_s(result.str, resultLen + 1, other.str);
	}
	else if (str != nullptr) {
		result.set(str);
	}
	else if (other.str != nullptr) {
		result.set(other.str);
	}
	return result;
}

const char* MyString::get() const {
	return str;
}

void MyString::set(const char* s) {
	if (s != nullptr) {
		size_t len = strlen(s);
		delete[] str;
		str = new char[len + 1];
		strcpy_s(str, len + 1, s);
	}
	else {
		delete[] str;
		str = nullptr;
	}
}
