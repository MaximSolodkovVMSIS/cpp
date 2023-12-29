#pragma once
#include <iostream>
#include <ios>
#include <fstream>

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
		if (front == nullptr) {
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

	void writeToTextFile(const std::string& filename) const {
		std::ofstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filename << "\n";
			return;
		}

		Node* current = front;
		while (current != nullptr) {
			file << current->data << " ";
			current = current->next;
		}

		file.close();
	}

	// Чтение из текстового файла и вывод в консоль
	void readFromTextFileAndPrint(const std::string& filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filename << "\n";
			return;
		}

		T value;
		while (file >> value) {
			std::cout << value << " ";
		}

		if (file.fail() && !file.eof()) {
			std::cerr << "Error reading from file: " << filename << "\n";
		}

		file.close();
		std::cout << std::endl;  // Добавляем новую строку после вывода данных
	}

	// Запись в бинарный файл
	void writeToBinaryFile(const std::string& filename) const {
		std::ofstream file(filename, std::ios::binary | std::ios::trunc);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filename << "\n";
			return;
		}

		Node* current = front;
		while (current != nullptr) {
			file.write(reinterpret_cast<char*>(&current->data), sizeof(T));
			current = current->next;
		}

		file.close();
	}

	// Чтение из бинарного файла и вывод в консоль
	void readFromBinaryFileAndPrint(const std::string& filename) {
		std::ifstream file(filename, std::ios::binary);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filename << "\n";
			return;
		}

		T value;
		while (file.read(reinterpret_cast<char*>(&value), sizeof(T))) {
			std::cout << value << " ";
		}

		if (!file.eof()) {
			std::cerr << "Error reading from file: " << filename << "\n";
		}

		file.close();
		std::cout << std::endl;  // Добавляем новую строку после вывода данных
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

