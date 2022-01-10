#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

template <typename T>
class Node {
public:
	Node(T value_) {
		value = value_;
	}
	Node<T>* next = nullptr;
	T value;
};

template <typename T>
ostream& operator<<(ostream& os, const Node<T>& node) {
	os << "[Node: " << node.value << "]";
	return os;
}

template <typename T>
class Stack {
public:
	Stack() {}
	~Stack() {
		free_stack();
	}
	Stack(const Stack<T>& other) {
		cout << "sdgfgsg" << endl;
		size_t n = other.size();
		// Expensive. Need tail
		Stack<T> _stack;
		auto it = other.begin();
		for (size_t i = 0; i < n; i++) {
			_stack.push(it->value);
			it = it->next;
		}
		for (size_t i = 0; i < n; i++) {
			push(_stack.pop());
		}
	}
	Stack(Stack<T>&& other) {
		cout << "there" << endl;
		free_stack();
		top = other.top;
		size_ = other.size_;

		other.top = nullptr;
		other.size_ = 0;
	}
	Stack(initializer_list<T> init) {
		auto i = init.begin();
		for (; i != init.end(); i++) {
			push(*i);
		}
	}
	size_t size() const {
		return size_;
	}
	void push(T value) {
		if (top == nullptr) {
			top = new Node<T>(value);
		} else {
			auto new_node = new Node<T>(value);
			new_node->next = top;
			top = new_node;
		}
		size_++;
	}
	T pop() {
		if (top == nullptr) {
			throw out_of_range("Stack is empty");
		}
		T result = top->value;
		auto free_space = top;
		top = top->next;
		delete free_space;
		size_--;
		return result;
	}
	Node<T>* begin() {
		return top;
	}
	Node<T>* begin() const {
		return top;
	}

	void operator=(const Stack<T>& other) {
		// copy-and-swap
		Stack<T> copy_stack = other;
		free_stack();
		top = copy_stack.begin();
		size_ = copy_stack.size();
	}

	void operator=(Stack<T>&& other) {
		Stack<int> s = other;
		top = s.begin();
		size_ = s.size();
	}

private:
	Node<T>* top = nullptr;
	size_t size_ = 0;

	void free_stack() {
		while (top != nullptr) {
            auto free_space = top;
            top = top->next;
            delete free_space;
        }
	}
};


Stack<int> get_stack(size_t size) {
	//return { 1, 2, 3 };
	Stack<int> stack;
	for (size_t i = 0; i < size; i++) {
		stack.push(i);
	}
	return stack;
}

void push_pop_should_work() {
	Stack<int> stack;
    const int size = 10000000;
    for (size_t i = 0; i < size; i++) {
        stack.push(i);
    }
    for (size_t i = 0; i < size; i++) {
      cout << stack.pop() << " ";
    }
}

void create_with_init_list() {
    Stack<int> stack = { 1, 2, 3 };
    size_t n = stack.size();
    for (size_t i = 0; i < n; i++) {
        cout << stack.pop() << " ";
    }
}

void create_by_copy_from_other_stack() {
	Stack<int> s = { 1, 2, 3 };
	const size_t n = s.size();
    Stack<int> t = s;
    for (size_t i = 0; i < n; i++) {
        cout << "T: " << t.pop() << " ";
        cout << "S: " << s.pop() << " " << "\n";
    }
}

void create_by_move_from_other_stack() {
	Stack<int> s = { 1, 2, 3 };
	const size_t n = s.size();
    cout << "After move: " << (s.begin() == nullptr)
		 << " " << s.size() << "\n";
    Stack<int> t = move(s);
    cout << "Before move: " << (s.begin() == nullptr)
		 <<  " " << s.size() << "\n";
    for (size_t i = 0; i < n; i++) {
        cout << t.pop() << " ";
    }
}

void create_by_move_from_temp_stack() {
    const size_t n = 5;
    Stack<int> stack = get_stack(n);
    for (size_t i = 0; i < n; i++) {
        cout << stack.pop() << " ";
    }
}

void copy_assignment() {
	Stack<int> s = { 1, 2, 3 };
    Stack<int> t = { 4, 5, 6, 7, 8 };
    const size_t n = s.size();
    t = s;
    for (size_t i = 0; i < n; i++) {
        cout << "T: " << t.pop() << " ";
        cout << "S: " << s.pop() << " " << "\n";
    }
}

int main() {
	//push_pop_should_work();
	//create_with_init_list();
	//create_by_copy_from_other_stack();
	//create_by_move_from_other_stack();
	create_by_move_from_temp_stack();
	//copy_assignment();

	//Stack<int> s = { 1, 2, 3 };
	//Stack<int> t = { 4, 5, 6, 7, 8 };
	//const size_t n = s.size();

	//cout << "After move: " << (s.begin() == nullptr)
    //     << " " << s.size() << "\n";
   	//t = { 1, 2, 3 };
    //cout << "Before move: " << (s.begin() == nullptr)
    //     <<  " " << s.size() << "\n";
    //for (size_t i = 0; i < n; i++) {
    //    cout << t.pop() << " ";
    //}

	// Iteration. Need tail for range based for
	//Stack<int> s = { 1, 2, 3 };
	//auto it = s.begin();
	//for (size_t i = 0; i < s.size(); i++) {
		//cout << *it << "\n";
	//	it = it->next;
	//}
	cout << endl;
}
