#include "Header.h"

int main() {
	std::string input1, input2;

	std::cout << "Enter the first string: ";
	std::cin >> input1;

	std::cout << "Enter the second string: ";
	std::cin >> input2;

	MyString str1(input1.c_str());
	MyString str2(input2.c_str());

	MyString result = str1 + str2;

	std::cout << "Result: " << result.get() << std::endl;

	std::string newstring;
	std::cout << "Enter a new string: ";
	std::cin >> newstring;

	result.set(newstring.c_str());
	std::cout << "Updated result: " << result.get() << std::endl;

	return 0;
}