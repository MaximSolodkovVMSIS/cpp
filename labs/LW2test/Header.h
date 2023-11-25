#pragma once
#include <iostream>
#include <cstring>

class MyString {
public:
	MyString();
	MyString(const char* s);
	MyString(const MyString& other);
	~MyString();

	MyString& operator=(const MyString& other);
	MyString operator+(const MyString& other);

	const char* get() const;
	void set(const char* s);
private:
	char* str;

};