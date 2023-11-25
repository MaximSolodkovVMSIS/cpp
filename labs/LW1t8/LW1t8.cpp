#include "Header.h"

int main() {
	
	double r1 = 0, r2 = 0;
	while (!(std::cout << "enter r1: ",  std::cin >> r1) || (std::cin.get() != '\n')) {
		std::cout << "error" << std::endl;
		std::cin.clear();
		rewind(stdin);
	}
	while (!(std::cout << "enter r2: ", std::cin >> r2) || (std::cin.get() != '\n')) {
		std::cout << "error" << std::endl;
		std::cin.clear();
		rewind(stdin);
	}
	circle c1(r1);
	circle c2(r2);

	c1.SetRadius(r1);
	c2.SetRadius(r2);
	c1.Output();
	c2.Output();

	double LengthDifference = circle::Length(c1, c2);

	if (LengthDifference > 0) {
		std::cout << "Length with radius 1: " << r1 << " more than radius 2: " << r2 << std::endl;
	}
	else if (LengthDifference < 0) {
		std::cout << "Length with radius 2: " << r2 << " more than length with radius 1: " << r1 << std::endl;
	}
	else {
		std::cout << "Length with radius 1: " << r1 << " and radius 2: " << r2 << " are equal" << std::endl;
	}


	//std::cout << std::endl;

	//std::string input1, input2;

	//std::cout << "Enter the first string: ";
	//std::cin >> input1;
	//
	//std::cout << "Enter the second string: ";
	//std::cin >> input2;

	//MyString str1(input1.c_str());
	//MyString str2(input2.c_str());

	//if (str1 == str2) {
	//	std::cout << "Strings are equal" << std::endl;
	//}
	//else {
	//	std::cout << "Strings are not equal" << std::endl;
	//}

	//MyString result = str1 + str2;

	//std::cout << "Result: " << result.get() << std::endl;

	//std::string newstring;
	//std::cout << "Enter a new string: ";
	//std::cin >> newstring;

	//result.set(newstring.c_str());
	//std::cout << "Updated result: " << result.get() << std::endl;

	MyString myStr("Hello World");

	std::cout << "Enter the start index of string: ";
	unsigned StartIndex = 0;
	std::cin >> StartIndex;

	std::cout << "Enter the end index of string: ";
	unsigned EndIndex = 0;
	std::cin >> EndIndex;

	std::string sub = myStr(StartIndex, EndIndex);
	std::cout << sub << std::endl;

	return 0;
}