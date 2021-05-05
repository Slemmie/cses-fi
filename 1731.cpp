#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

int n, k;
std::string s;

struct Node {
	
	char c;
	bool end_here;
	std::vector <Node*> nxt;
	
	Node(char _c) : c(_c), end_here(false), nxt(26, nullptr) { }
	
	~Node() {
		for (Node*& node : nxt)
			if (node)
				delete(node);
	}
	
	void add(const std::string& t, int ind) {
		if (ind == (int)t.length()) {
			end_here = true;
			return;
		}
		if (!nxt[t[ind] - 'a'])
			nxt[t[ind] - 'a'] = new Node(t[ind]);
		nxt[t[ind] - 'a']->add(t, ind + 1);
	}
	
	Node* find(char target) {
		return nxt[target - 'a'];
	}
	
};

Node* head = new Node('$');

std::vector <ll> dp;

ll f(int pos) {
	if (pos == n) return 1;
	if (dp[pos] != -1LL) return dp[pos];
	ll r = 0;
	Node* node = head;
	for (int i = pos; i < n; i++) {
		node = node->find(s[i]);
		if (!node) break;
		if (node->end_here) r = (r + f(i + 1)) % mod;
	}
	return dp[pos] = r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> s >> k;
	n = s.length();
	dp.resize(n, -1);
	for (int i = 0; i < k; i++) {
		std::string t; std::cin >> t;
		head->add(t, 0);
	}
	std::cout << f(0) << "\n";
	delete(head);
	
}
