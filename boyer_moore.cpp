#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
	for (const auto& x : v) {
		os << x << " ";
	}
	return os;
}


void read_data(string& t, string& s) {
	cout << "t = ";
	cin >> t;
	cout << "s = ";
	cin >> s;
}


vector<int> z_function(const string& s) {
	const size_t n = s.size();
	vector<int> z;
	z.assign(n, 0);
	z[0] = n;
	
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r) {
			z[i] = min(r-i, z[i-l]);
		}
		
		while (z[i] + i < n && s[z[i] + i] == s[z[i]]) {
				z[i]++;
		}
		
		if (z[i] + i > r) {
			r = z[i] + i;
			l = i;
		}
	}
	
	return z;
}


vector<int> build_shift(const string& s) {
	const size_t m = s.size();
	vector<int> shift;
	shift.assign(m + 1, m);
	
	vector<int> z = z_function({ s.rbegin(), s.rend() });
	reverse(z.begin(), z.end());
	cout << "Z: " << z << endl;
	
	for (int i = 0, j = 0; i < m; i++) {
		if (z[i] < i + 1) {
			j = m - z[i];
			shift[j] = m - i - 1;
		}
	}
	
	for (int i = m - 2, j = 0; i >= 0; i--) {
		if (z[i] == i + 1) {
			int h = m - i - 1;
			for (; j <= h; j++) {
				shift[j] = min(shift[j], h);
			}
		}
	}
	
	return shift;
}


vector<int> boyer_moore(const string& t, const string& s) {

	const size_t n = t.size();
	const size_t m = s.size();
	
	vector<int> occurences;
	vector<int> shift = build_shift(s);
	cout << "Shift: " << shift << endl;
	
	for (int i = 0, j = 0; i <= n - m; i += shift[j + 1]) {
		
		j = m - 1;
		while (j >= 0 && s[j] == t[i + j]) j--;
		
		if (j < 0) {
			occurences.push_back(i);
		}		
	}
	
	return occurences;
}


int main() {
	string t, s;
	read_data(t, s);
	
	vector<int> occurences = boyer_moore(t, s);
	cout << "Occurences: " << occurences << endl;
}







