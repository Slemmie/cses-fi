#include <bits/stdc++.h>

struct Node {
	
	long long val;
	
	Node* l,* r;
	
	Node() : val(0), l(nullptr), r(nullptr) { }
	
	~Node() {
		if (l) delete(l);
		if (r) delete(r);
	}
	
};

void update(Node*& node, int ind, long long val, int l, int r) {
	if (!node) node = new Node;
	if (!(r - l - 1)) {
		node->val = std::max(node->val, val);
		return;
	}
	int mid = (l + r) >> 1;
	if (ind < mid) update(node->l, ind, val, l, mid);
	else update(node->r, ind, val, mid, r);
	node->val = std::max(node->l ? node->l->val : 0LL, node->r ? node->r->val : 0LL);
}

long long get(Node*& node, int tl, int tr, int l, int r) {
	if (l >= tr || r <= tl) return 0;
	if (l >= tl && r <= tr) return node->val;
	int mid = (l + r) >> 1;
	return std::max(node->l ? get(node->l, tl, tr, l, mid) : 0LL,
	node->r ? get(node->r, tl, tr, mid, r) : 0LL);
}

struct O {
	
	int l, r;
	long long w;
	
	bool operator < (const O& oth) const {
		if (l == oth.l) return r < oth.r; // useless
		return l < oth.l;
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	Node* head = new Node;
	std::vector <O> o(n);
	for (O& x : o) std::cin >> x.l >> x.r >> x.w;
	std::sort(o.rbegin(), o.rend());
	for (O& x : o) {
		long long val = x.w + get(head, x.r + 1, (1 << 30) - 1, 0, 1 << 30);
		update(head, x.l, val, 0, 1 << 30);
	}
	std::cout << get(head, 0, (1 << 30) - 1, 0, 1 << 30) << "\n";
	delete(head);
	
}
