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
};

class Trie {
public:
	Trie(): root(new vertex()) {
	}
	
	size_t vertex_count = 0;
	vertex* const root;
	
	void add_string(const string& s) {
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


vector<pair<size_t, size_t>> aho_korasik(
	const vector<string>& w, const string& t) {
	
	Trie trie;
	for (const auto& s: w) {
		trie.add_string(s);
	}
	
	trie.build_link_report();

	vector<pair<size_t, size_t>> occurences;
	vertex* v = trie.root;
	for (size_t i = 0; i < t.size(); i++) {
		const size_t j = t[i] - ALPH_ASCII_OFFSET;
		while (v != trie.root && v->next[j] == nullptr) {
			v = v->link;
		}
		
		v = v->next[j];
		if (v == nullptr) v = trie.root;
		
		for (auto u = v; u != trie.root; u = u->report) {
			if (u->terminal) {
				occurences.push_back({i - u->len + 1, i});
			}
		}
	}
	
	return occurences;
}


vector<pair<size_t, size_t>> matrix_match(
	const vector<string>& w, const vector<string>& t) {

	Trie trie;
	for (const auto& s : w) {
		trie.add_string(s);
	}
	
	trie.build_link_report();
	
	return {};
}


int main() {
	vector<string> w = { { "ab" }, 
						 { "cd" } };
								 
	vector<string> t = { { "xrt" },
						 { "eab" },
						 { "ecd" } };
								 
	//cout << matrix_match(w, t) << endl;
	
	string p = "asfgabcc";
	vector<string> s = { "ab", "b", "cc"};
	cout << "Occurences: " << aho_korasik(s, p) << endl;
}




