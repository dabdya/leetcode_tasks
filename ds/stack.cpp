#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Node {
public:
	Node(T value_) {
		value = value_;
	}
	Node<T>* next = nullptr;
	int value;
};

template <typename T>
class Stack {
public:
	void push(T value) {
		if (top == nullptr) {
			top = new Node<T>(value);
		} else {
			auto new_node = new Node<T>(value);
			new_node->next = top;
			top = new_node;
		}
	}
	T pop() {
		if (top == nullptr) {
			throw out_of_range("Stack is empty");
		}
		T result = top->value;
		auto free_space = top;
		top = top->next;
		free(free_space);
		return result;
	}
private:
	Node<T>* top = nullptr;
};

int main() {
	Stack<int> stack;
	const int size = 10000000;
	for (size_t i = 0; i < size; i++) {
		stack.push(i);
	}
	for (size_t i = 0; i < size; i++) {
		cout << stack.pop() << " ";
	}
	cout << endl;
}
