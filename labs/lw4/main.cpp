#include "queue.h"

int main() {
	Queue<int> intQueue;
	
	int count;
	std::cout << "Enter the number of int: ";
	std::cin >> count;

	for (int i = 0; i < count; i++) {
		int value;
		std::cout << "Enter int #" << (i + 1) << ": ";
		std::cin >> value;
		intQueue.push(value);
	}
	
	std::cout << "Int queue: ";
	intQueue.print();

	std::cout << "Front element: " << intQueue.peek() << std::endl;
	intQueue.pop();
	std::cout << "After pop: ";
	intQueue.print();


	Queue<std::string> stringQueue;

	int stringCount;
	std::cout << "Enter the number of string: ";
	std::cin >> stringCount;

	for (int i = 0; i < stringCount; i++) {
		std::string value;
		std::cout << "Enter string #" << (i + 1) << ": ";
		std::cin >> value;
		stringQueue.push(value);
	}

	std::cout << "String Queue: ";
	stringQueue.print();

	return 0;
}

