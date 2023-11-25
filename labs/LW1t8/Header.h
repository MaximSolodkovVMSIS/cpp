#include <iostream>
#include <cstring>

class circle {

public:
	circle(double r);
	~circle();
	double Square();
	double Length();

	circle& operator+=(const circle& other);
	circle operator+(const circle& other);

	static double Length(circle& c1, circle& c2);

	void Output();
	void SetRadius(const double radius);
	double GetRadius();

private:
	const double pi = 3.14159265;
	double radius;
};


class MyString {
public:
	MyString();
	MyString(const char* s);
	MyString(const MyString& other);
	~MyString();

	MyString& operator=(const MyString& other);
	MyString operator+(const MyString& other);
	MyString& operator+=(const MyString& other);
	bool operator==(const MyString& other) const;
	bool operator!=(const MyString& other) const;
	char operator[](int index) const;
	std::string operator()(const unsigned start, const unsigned end);

	const char* get() const;
	void set(const char* s);

private:
	char* str;
};
