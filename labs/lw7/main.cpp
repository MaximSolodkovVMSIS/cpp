#include <iostream>

#include "queue.h"


bool compare(const int a, const int b) {
	return a > b;
}

int main(void) {

	Queue<int> queue;

	queue.push(3);
	queue.push(2);
	queue.push(1);
	Queue<int>::Iterator iter = queue.begin();

	queue.sort(queue.begin(), queue.end(), compare);

	for (auto it = queue.begin(); it != queue.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	int searchValue = 2;
	auto result = queue.search(searchValue);

	if (result != queue.end()) {
		std::cout << "Value " << searchValue << " found in the queue." << std::endl;
	}
	else {
		std::cout << "Value " << searchValue << " not found in the queue." << std::endl;

	}
	return 0;

}