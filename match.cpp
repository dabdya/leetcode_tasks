#include <iostream>
#include <vector>
#include <string>

#define ALPH_SIZE 26
#define ALPH_ASCII_OFFSET 97

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	for (const auto& x : v) {
		os << x << " ";
	}
	return os;
}

template <typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}


struct vertex {
	bool terminal = false;
	vertex* next[ALPH_SIZE];
	
	vertex* report;
	vertex* link;
	
	size_t len;
	size_t label;
};

class Trie {
public:
	Trie(): root(new vertex()) {
	}
	
	size_t vertex_count = 0;
	vertex* const root;
	
	void add_string(const string& s, size_t label) {
		vertex* v = root;
		for (const auto& c : s) {
			vertex*& next_v = v->next[c - ALPH_ASCII_OFFSET];
			if (next_v == nullptr) {
				next_v = new vertex();
				v->next[c - ALPH_ASCII_OFFSET] = next_v;
				vertex_count++;
			}
			v = next_v;
		}
		
		v->terminal = true;
		v->len = s.size();
		v->label = label;
	}
	
	void build_link_report() {
		vertex* bfs[vertex_count];
		
		root->link = root->report = root;
		bfs[0] = root;
		
		for (size_t i = 0, k = 1; i < k; i++) {
			
			for (size_t j = 0; j < ALPH_SIZE; j++) {
				if (bfs[i]->next[j] == nullptr) continue;
				vertex* v = bfs[i]->next[j];
				bfs[k++] = v;
				
				for (auto p = bfs[i]; p != root 
					&& v->link == nullptr; p = p->link) {
					v->link = p->link->next[j];
				}
				
				if (v->link == nullptr) v->link = root;
				
				v->report = v->link;
				if (!v->link->terminal) {
					v->report = v->link->report;
				}
			}
		}
	}
};

vector<pair<size_t, size_t>> matrix_match(
	const vector<string>& w, const vector<string>& t) {
	
	const size_t m = t[0].size(), n = t.size();
	
	Trie trie;
	
	size_t label = 0;
	for (const auto& s : w) {
		trie.add_string(s, label);
		label += m;
	}
	
	trie.build_link_report();
	
	vector<size_t> c;
	c.assign(m*n, 0);
	
	vertex* v = trie.root;
	for (size_t i = 0; i < n * m; i++) {
		const size_t j = t[i / m][i % m] - ALPH_ASCII_OFFSET;
		while (v != trie.root && v->next[j] == nullptr) {
			v = v->link;
		}
		
		v = v->next[j];
		if (v == nullptr) v = trie.root;
		
		for (auto u = v; u != trie.root; u = u->report) {
			if (u->terminal) {
				c[max<size_t>(i - u->len + 1 - u->label, 0)]++; 
			}
		}
	}
	
	vector<pair<size_t, size_t>> occurences;
	for (size_t i = 0; i < c.size(); i++) {
		if (c[i] == w.size()) {
			occurences.push_back({i / m, i % m});
		}
	}

	return occurences;
}


int main() {
	vector<string> w = { {"e"} };
								 
	vector<string> t = { { "xrtq" },
						 { "eabt" },
						 { "ecab" },
						 { "eeca" } };
								 
	cout << matrix_match(w, t) << endl;
}




