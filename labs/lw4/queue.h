#include <iostream>

template <typename T>

class Queue {
public:
	Queue() : front(nullptr), rear(nullptr) {}

	~Queue() {
		while (front != nullptr) {
			Node* temp = front;
			front = front->next;
			delete temp;
		}
	}

	void push(const T& value) {
		Node* newNode = new Node(value);
		if (rear == nullptr) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	void pop() {
		if (front == nullptr) {
			std::cerr << "Queue is empty. Cannot pop" << std::endl;
			return;
		}

		Node* temp = front;
		front = front->next;
		delete temp;

		if(front == nullptr) {
			rear = nullptr;
		}
	}
	T peek() const {
		if (front != nullptr) {
			return front->data;
		}
		else {
			std::cerr << "Queue is empty. cannot peek" << std::endl;
			return T();
		}
	}
	void print() const {
		Node* current = front;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

private:
	struct Node {
		T data;
		Node* next;

		Node(const T& value) : data(value), next(nullptr) {}
	};

	Node* front;
	Node* rear;
};