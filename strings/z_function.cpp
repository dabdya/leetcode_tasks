#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
ostream& operator << (ostream& os, const vector<T> v) {
	for (const auto& x: v) {
		os << x << " ";
	}
	
	return os;
}

int main() {
	string t;
	cout << "t = ";
	cin >> t;
	
	const size_t n = t.size();
	vector<int> z;
	z.assign(n, 0);
	z[0] = n;
	
	int l = 0, r = 0; // [l, r)
	/*
		Будем поддерживать два числа l, r такие, что 
		на полуинтервале [0 .. r - l) значения z уже известны,
		при этом интервал должен быть максимально правым по мере вычисления
	*/
	
	for (int i = 1; i < n; i++) {
		
		if (l <= i && i < r) {
			z[i] = min(z[i - l], r - i);
		}
		
		while (z[i] + i < n && t[z[i] + i] == t[z[i]]) {
			z[i]++;
		}
		
		if (i + z[i] > r) {
			r = i + z[i];
			l = i;
		}
	}
	
	cout << "Z: " << z << endl;
}


