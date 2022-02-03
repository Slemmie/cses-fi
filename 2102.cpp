#include <bits/stdc++.h>

template <int mod> int pw(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) {
			r = ((long long)r * x) % mod;
		}
		x = ((long long)x * x) % mod;
		p >>= 1;
	}
	return r;
}

template <int base, int mod> struct Rolling {
	
	std::vector <int> v;
	static inline std::vector <int> inv;
	
	Rolling(const std::string& s) {
		v.resize(s.size(), 1);
		if (inv.size() < s.size()) {
			inv.resize(s.size(), -1);
		}
		int val = 1;
		for (int i = 0; i < (int)s.size(); i++) {
			v[i] = ((long long)val * (s[i] - 'a' + 1) + (i ? v[i - 1] : 0)) % mod;
			if (inv[i] == -1) {
				inv[i] = pw <mod> (val, mod - 2);
			}
			val = ((long long)val * base) % mod;
		}
	}
	
	int query(int l, int r) {
		return (long long)inv[l] * (v[r] - (l ? v[l - 1] : 0) + mod) % mod;
	}
	
};

struct Node {
	std::vector <Node*> child = std::vector <Node*> (26, nullptr);
	~Node() {
		for (Node*& c : child) {
			if (c) {
				delete(c);
			}
		}
	}
	inline void add(int i, const std::string& s) {
		if (i == (int)s.size()) {
			return;
		}
		if (!child[s[i] - 'a']) {
			child[s[i] - 'a'] = new Node();
		}
		child[s[i] - 'a']->add(i + 1, s);
	}
	inline bool has(int i, const std::string& s) {
		if (i == (int)s.size()) {
			return true;
		}
		if (!child[s[i] - 'a']) {
			return false;
		}
		return child[s[i] - 'a']->has(i + 1, s);
	}
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::string s; std::cin >> s;
	Rolling <69, int(1e9) + 7> rol(s);
	int block = sqrt(s.size()) / 15;
	Node trie;
	for (int i = 0; i < (int)s.size(); i++) {
		std::string t;
		for (int j = i; j <= i + block + 1 && j < (int)s.size(); j++) {
			t += s[j];
		}
		if (t.empty()) {
			break;
		}
		trie.add(0, t);
	}
	int k; std::cin >> k;
	for (int i = 0; i < k; i++) {
		std::string t; std::cin >> t;
		if ((int)t.size() >= block) {
			bool yes = false;
			Rolling <69, int(1e9) + 7> her(t);
			int here = her.query(0, (int)t.size() - 1);
			for (int j = 0; j < (int)s.size(); j++) {
				if (j + (int)t.size() - 1 >= (int)s.size()) {
					break;
				}
				if (here == rol.query(j, j + (int)t.size() - 1)) {
					yes = true;
					break;
				}
			}
			std::cout << (yes ? "YES\n" : "NO\n");
		} else {
			std::cout << (trie.has(0, t) ? "YES\n" : "NO\n");
		}
	}
	
}
