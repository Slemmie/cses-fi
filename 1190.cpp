#include <bits/stdc++.h>

typedef long long ll;

struct Item {
	ll pre, suf, sum, entire;
	Item() : pre(0), suf(0), sum(0), entire(0) { }
	Item(int _pre, int _suf, int _sum) : pre(_pre), suf(_suf), sum(_sum), entire(_sum) { }
};

Item merge(Item a, Item b) {
	Item r;
	r.sum = std::max({ a.sum, b.sum, a.suf + b.pre });
	r.pre = std::max(a.pre, a.entire + b.pre);
	r.suf = std::max(b.suf, b.entire + a.suf);
	r.entire = a.entire + b.entire;
	return r;
}

struct Seg {
	
	int size;
	
	std::vector <Item> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size << 1, Item());
	}
	
	void set(int ind, int val) {
		set(ind, val, 0, 0, size);
	}
	
	void set(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = Item(val, val, val);
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) set(ind, val, (now << 1) | 1, l, mid);
		else set(ind, val, (now << 1) + 2, mid, r);
		v[now] = merge(v[(now << 1) | 1], v[(now << 1) + 2]);
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	Seg seg(n);
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		seg.set(i, x);
	}
	while (q--) {
		int ind, val; std::cin >> ind >> val; ind--;
		seg.set(ind, val);
		std::cout << seg.v[0].sum << "\n";
	}
	
}
