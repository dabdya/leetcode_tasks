#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "heap.h"

using namespace std;

vector<int> heap_sort(Heap<int> heap) {
	size_t n = heap.Size();
	vector<int> sorted_data(n);
	for (size_t i = 0; i < n; i++) {
		sorted_data[i] = heap.RemoveMin();
	}
	return sorted_data;
}

ostream& operator<<(ostream& os, const vector<int>& v) {
	for (const auto& x : v) {
		os << x << " ";
	}
	return os;
}

int main() {
	cout << "Heap sort program" << endl;
	cout << "Enter operations count: ";
	size_t n;
	cin >> n;
	cout << "Use commands { SORT, INSERT, REMOVE_MIN }" << endl;
	Heap<int> heap;
	for (size_t i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "INSERT") {
			int value;
			cin >> value;
			heap.Insert(value);
		}
		else if (cmd == "REMOVE_MIN") {
			try {
				int removed = heap.RemoveMin();
				cout << "MinValue " << removed << " "
				     << "was removed" << endl;
			}
			catch (out_of_range error) {
				cout << error.what() << endl;
			}
		}
		else if (cmd == "SORT") {
			cout << heap_sort(heap) << endl;
		}
		else {
			cout << "Invalid command" << endl;
		}
	}
	return 0;
}
