#include <bits/stdc++.h>

std::vector <int> offr, offl;

int offset(bool which, int ind) {
	return which ? offr[ind] : offl[ind];
}

template <bool which> struct Seg {
	
	int size;
	
	std::vector <int> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size << 1, 1 << 30);
	}
	
	void set(int ind, int val) {
		set(ind, val + offset(which, ind), 0, 0, size);
	}
	
	void set(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) set(ind, val, (now << 1) | 1, l, mid);
		else set(ind, val, (now << 1) + 2, mid, r);
		v[now] = std::min(v[(now << 1) | 1], v[(now << 1) + 2]);
	}
	
	int get(int l, int r, int ind) {
		int res = -offset(which, ind);
		if (which) res += get(l, ind + 1, 0, 0, size);
		else res += get(ind, r, 0, 0, size);
		return res;
	}
	
	int get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 1 << 30;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return std::min(get(tl, tr, (now << 1) | 1, l, mid), get(tl, tr, (now << 1) + 2, mid, r));
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	offr.resize(n);
	for (int i = n - 1, cnt = 0; i >= 0; i--, cnt++) offr[i] = cnt;
	offl.resize(n, 0);
	for (int i = 0; i < n; i++) offl[i] = i;
	Seg <true> left(n);
	Seg <false> right(n);
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		left.set(i, p);
		right.set(i, p);
	}
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int ind, val; std::cin >> ind >> val; ind--;
			left.set(ind, val);
			right.set(ind, val);
		} else {
			int ind; std::cin >> ind; ind--;
			std::cout << std::min(left.get(0, n, ind), right.get(0, n, ind)) << "\n";
		}
	}
	
}
