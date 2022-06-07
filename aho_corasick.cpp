#include <iostream>
#include <vector>
#include <map>

using namespace std;


template <typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) {
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <typename T>
ostream& operator << (ostream& os, vector<T>& v) {
	for (const auto& x: v) {
		os << x << " ";
	}
	return os;
}


void read_data(string& t, vector<string>& v) {
	cout << "t = ";
	cin >> t;
	
	size_t n;
	cout << "n = ";
	cin >> n;
	
	string s;
	for (size_t i = 0; i < n; i++) {
		cout << "s = ";
		cin >> s;
		v.push_back(s);
	}
}


struct Node {
public:
	bool terminal;
	map<char, Node*> next;
	size_t length;
	
	Node* link;
	Node* report;
};


class Trie {
public:
	Trie() {
		root = new Node();
	}
	
	void add_string(const string& s) {
		const int m = s.size();
		
		Node* v = root;
		for (int i = 0; i < m; i++) { 
			if (!v->next.count(s[i])) {
				v->next[s[i]] = new Node();
				node_count++;
			}
			v = v->next[s[i]];
		}
		
		v->terminal = true;
		v->length = m;
	}
	
	void build_link_report() {
		vector<Node*> bfs(node_count);
		root->link = root->report = root;
		bfs[0] = root;
		
		size_t queue_size = 1;
		for (size_t i = 0; i < queue_size; i++) {
			for (const auto& [c, v]: bfs[i]->next) {
				bfs[queue_size++] = v;
				v->link = nullptr;
				for (Node* p = bfs[i]; p != root && v->link == nullptr; p = p->link) {
					if (p->link->next.count(c)) {
						v->link = p->link->next[c];
					}
				}
				if (v->link == nullptr) v->link = root;
						
				v->report = v->link;
				if (!v->link->terminal) {
					v->report = v->link->report;
				}
			}
			
		}
	}
	
	Node* root;
	size_t node_count = 1;
};


vector<pair<int, int>> aho_corasick(const string& t, const vector<string>& vec) {

	Trie trie;
	for (const string& s: vec) {
		trie.add_string(s);
	}

	trie.build_link_report();

	const int n = t.size();
	Node* v = trie.root;
	
	vector<pair<int, int>> occurences;
	for (int i = 0; i < n; i++) {
		while (v != trie.root && !v->next.count(t[i])) {
			v = v->link;
		}
		
		v = v->next[t[i]];
		if (v == nullptr) {
			v = trie.root;
		}
		
		for (Node* u = v; u != trie.root; u = u->report) {
			if (u->terminal) {
				occurences.push_back({i - u->length + 1, i});
			}
		}
	}
	
	return occurences;
}


int main() {
	string t;
	vector<string> v;
	read_data(t, v);
	
	vector<pair<int, int>> occurences = aho_corasick(t, v);
	cout << "Occurences: " << occurences << endl;
}





