#include <bits/stdc++.h>

typedef long long ll;

struct Item {
	ll pre, sum;
};

Item merge(Item a, Item b) {
	return { std::max(a.pre, a.sum + b.pre), a.sum + b.sum };
}

struct Seg {
	
	int size;
	
	std::vector <Item> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size << 1, { 0, 0 });
	}
	
	void set(int ind, int val) {
		set(ind, val, 0, 0, size);
	}
	
	void set(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = { val, val };
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) set(ind, val, (now << 1) | 1, l, mid);
		else set(ind, val, (now << 1) + 2, mid, r);
		v[now] = merge(v[(now << 1) | 1], v[(now << 1) + 2]);
	}
	
	ll get(int l, int r) {
		return std::max(0LL, get(l, r, 0, 0, size).pre);
	}
	
	Item get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return { 0, 0 };
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return merge(get(tl, tr, (now << 1) | 1, l, mid), get(tl, tr, (now << 1) + 2, mid, r));
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	Seg seg(n);
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		seg.set(i, p);
	}
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int ind, val; std::cin >> ind >> val; ind--;
			seg.set(ind, val);
		} else {
			int l, r; std::cin >> l >> r; l--;
			std::cout << seg.get(l, r) << "\n";
		}
	}
	
}
