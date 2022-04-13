#include <bits/stdc++.h>

struct Node {
	
	Node* l = nullptr,* r = nullptr;
	
	~Node() {
		if (l) delete(l);
		if (r) delete(r);
	}
	
	void add(int val, int b = 30) {
		if (!(~b)) {
			return;
		}
		if (val & (1 << b)) {
			if (!r) {
				r = new Node();
			}
			r->add(val, b - 1);
		} else {
			if (!l) {
				l = new Node();
			}
			l->add(val, b - 1);
		}
	}
	
	int get(int val, int b = 30) {
		if (!(~b)) {
			return 0;
		}
		if (!l && !r) {
			return val & ((1 << b) - 1);
		}
		if (val & (1 << b)) {
			if (l) {
				return l->get(val, b - 1) | (1 << b);
			} else {
				return r->get(val, b - 1);
			}
		} else {
			if (r) {
				return r->get(val, b - 1) | (1 << b);
			} else {
				return l->get(val, b - 1);
			}
		}
		assert(false);
		return 0;
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) {
		std::cin >> x;
	}
	for (int i = 1; i < n; i++) {
		a[i] ^= a[i - 1];
	}
	Node node;
	node.add(0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = std::max(ans, node.get(a[i]));
		node.add(a[i]);
	}
	std::cout << ans << "\n";
	
}
