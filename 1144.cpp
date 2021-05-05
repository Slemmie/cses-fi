#include <bits/stdc++.h>
 
const int size = 1073741824LL;
 
struct Node {
	
	int va, in;
	
	Node* ln, * rn;
	
	Node(int VAL = 0, int IND = 0) : va(VAL), in(IND), ln(nullptr), rn(nullptr) { }
	
	~Node() {
		if (ln) delete(ln);
		if (rn) delete(rn);
	}
	
	void add(int ind, int val, int l, int r) {
		if (!(r - l - 1)) {
			va += val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) {
			if (!ln) ln = new Node(0, in * 2 + 1);
			ln->add(ind, val, l, mid);
		} else {
			if (!rn) rn = new Node(0, in * 2 + 2);
			rn->add(ind, val, mid, r);
		}
		int newv = 0;
		if (ln) newv += ln->va;
		if (rn) newv += rn->va;
		va = newv;
	}
	
	int get(int tl, int tr, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return va;
		int mid = (l + r) >> 1;
		int re = 0;
		if (ln) re += ln->get(tl, tr, l, mid);
		if (rn) re += rn->get(tl, tr, mid, r);
		return re;
	}
	
};
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	Node* head = new Node;
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		head->add(v[i], 1, 0, size);
	}
	while (q--) {
		char c; int a, b; std::cin >> c >> a >> b;
		if (c == '!') {
			head->add(v[a - 1], -1, 0, size);
			v[a - 1] = b;
			head->add(v[a - 1], 1, 0, size);
		} else {
			std::cout << head->get(a, b + 1, 0, size) << "\n";
		}
	}
	delete(head);
	
}
