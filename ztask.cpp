#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	for (const auto& x : v) {
		os << x << " ";
	}
	return os;
}

vector<size_t> zfunc(const string& s) {
	const size_t n = s.size();
	vector<size_t> z;
	z.assign(n, 0);
	z[0] = n;
	
	size_t l = 0, r = 0;
	for (size_t i = 1; i < n; i++) {
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

vector<size_t> find_occurences(const string& s, const string& t) {
	vector<size_t> zs = zfunc(s);
	vector<size_t> occurences;
	
	size_t l = 0, r = 0;
	for (size_t i = 0; i < t.size(); i++) {
	
		size_t zi = 0;
		
		if (i < r) {
			zi = min(r-i, zs[i-l]);
		}
		
		while (zi < s.size() && t[zi + i] == s[zi]) {
				zi++;
		}
		
		if (zi == s.size()) {
			occurences.push_back(i);
		}
		
		if (zi > r-i) {
			r = zi + i;
			l = i;
		}	
	}
	
	return occurences;
}

vector<size_t> prefix_matches(const string& s, const string& t) {
	vector<size_t> zs = zfunc(s);
	vector<size_t> matches(s.size());
	
	size_t l = 0, r = 0;
	size_t cnt = 0;
	
	for (size_t i = 0; i < t.size(); i++) {
	
		size_t zi = 0;
		
		if (i < r) {
			zi = min(r-i, zs[i-l]);
		}
		
		while (zi < s.size() && t[zi + i] == s[zi]) {
				zi++;
		}
		
		if (zi != 0) {
			matches[zi - 1]++;
			cnt++;
		}
		
		if (zi > r-i) {
			r = zi + i;
			l = i;
		}	
	}
	
	for (size_t i = 0; i < matches.size(); i++) {
		const size_t tmp = matches[i];
		matches[i] = cnt;
		cnt -= tmp;
	}
	
	return matches;
}

int main() {
	string t, s;
	cout << "Input t = ";
	cin >> t;
	cout << "Input s = ";
	cin >> s;
	cout << "Prefix matches: " << prefix_matches(s, t) << endl;
	// cout << "Occurences: " << find_occurences(s, t) << endl;
}



