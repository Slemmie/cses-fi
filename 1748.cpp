#include <bits/stdc++.h>

constexpr int mod = 1e9 + 7;

struct Node {
	
	int v = 0;
	Node* ln = nullptr,* rn = nullptr;
	
	~Node() {
		if (ln) delete(ln);
		if (rn) delete(rn);
	}
	
	void add(int ind, int val) {
		add(ind, val, 0, 1u << 31);
	}
	
	void add(unsigned int ind, int val, unsigned int l, unsigned int r) {
		if (!(r - l - 1)) {
			v = (v + val) % mod;
			return;
		}
		unsigned int mid = (l + r) >> 1;
		if (ind < mid) {
			if (!ln) ln = new Node();
			ln->add(ind, val, l, mid);
		} else {
			if (!rn) rn = new Node();
			rn->add(ind, val, mid, r);
		}
		v = ((ln ? ln->v : 0LL) + (rn ? rn->v : 0LL)) % mod;
	}
	
	long long get(int l, int r) {
		return get(l, r, 0, 1u << 31);
	}
	
	long long get(unsigned int tl, unsigned int tr, unsigned int l, unsigned int r) {
		if (l >= tr || r <= tl) {
			return 0;
		}
		if (l >= tl && r <= tr) {
			return v;
		}
		unsigned int mid = (l + r) >> 1;
		return ((ln ? ln->get(tl, tr, l, mid) : 0LL) + (rn ? rn->get(tl, tr, mid, r) : 0LL)) % mod;
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) {
		std::cin >> x;
	}
	long long ans = 0;
	Node node;
	for (int i = n - 1; i >= 0; i--) {
		long long now = 1 + node.get(a[i] + 1, 1 << 30);
		ans = (ans + now) % mod;
		node.add(a[i], now % mod);
	}
	std::cout << ans << "\n";
	
}
