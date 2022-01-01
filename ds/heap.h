#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Heap {
public:
	size_t Size();
	void Insert(T value);
	T RemoveMin();
private:
	vector<T> data;
};

template <typename T>
void swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
void Heap<T>::Insert(T value) {
	data.push_back(value);
	size_t i = data.size() - 1;
	while (i > 0 && data[i] < data[(i - 1)/2]) {
		swap(&data[i], &data[(i - 1)/2]);
		i = (i-1)/2;
	}
}

template <typename T>
size_t Heap<T>::Size() {
	return data.size();
}

template <typename T>
T Heap<T>::RemoveMin() {
	if (!data.size()) {
		throw out_of_range("Heap is empty");
	}

	T result = data[0];
	swap(&data[0], &data[data.size() - 1]);
	data.pop_back();

	size_t n = data.size();
	size_t i = 0;
	while (true) {
		size_t j = i;
		if (2*i+1 < n && data[2*i+1] < data[j]) {
			j = 2*i+1;
		}
		if (2*i+2 < n && data[2*i+2]< data[j]) {
			j = 2*i+2;
		}
		if (i == j) { break; }
		swap(&data[i], &data[j]);
		i = j;
	}

	return result;
}
