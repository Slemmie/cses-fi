#include <bits/stdc++.h>
 
typedef long long ll;
 
struct Seg {
	
	int size;
	std::vector <ll> v;
	
	Seg(int s) : size(1) {
		while (size < s) size <<= 1;
		v.resize(size * 2, 0);
	}
	
	void make(const std::vector <int>& a, int now, int l, int r) {
		if (!(r - l - 1)) {
			if (size_t(l) < a.size()) v[now] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		make(a, now * 2 + 1, l, mid);
		make(a, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	
	void make(const std::vector <int>& a) {
		make(a, 0, 0, size);
	}
	
	void update(ll val, int ind, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) update(val, ind, now * 2 + 1, l, mid);
		else update(val, ind, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	
	void update(int ind, int val) {
		update(val, ind, 0, 0, size);
	}
	
	ll get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return get(tl, tr, now * 2 + 1, l, mid) + get(tl, tr, now * 2 + 2, mid, r);
	}
	
	ll get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
};
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	Seg seg(n);
	seg.make(a);
	while (q--) {
		int type, u, v; std::cin >> type >> u >> v;
		if (type == 1) {
			seg.update(u - 1, v);
		} else {
			std::cout << seg.get(u - 1, v) << "\n";
		}
	}
	
}
