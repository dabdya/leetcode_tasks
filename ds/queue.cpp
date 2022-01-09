#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Node {
public:
	Node (T value_) {
		value = value_;
	}
	Node<T>* prev = nullptr;
	T value;
};

template <typename T>
class Queue {
public:
	void push(T value) {
		auto new_node = new Node<T>(value);
		if (tail == nullptr) {
			tail = new_node;
			head = new_node;
		} else {
			tail->prev = new_node;
			tail = new_node;
		}
	}
	T pop() {
		if (head == nullptr) {
			throw out_of_range("Queue is empty");
		}
		T result = head->value;
		Node<T>* free_space = head;
		if (head->prev == nullptr) {
			head = tail = nullptr;
		} else {
			head = head->prev;
		}
		free(free_space);
		return result;
	}
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
};

int main() {
	Queue<int> q;
	const size_t size = 10000000;
	for (size_t i = 0; i < size; i++) {
		q.push(i);
	}
	for (size_t i = 0; i < size; i++) {
		cout << q.pop() << " ";
	}
	cout << endl;
	return 0;
}
