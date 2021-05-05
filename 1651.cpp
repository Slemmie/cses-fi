#include <bits/stdc++.h>
 
typedef long long ll;
 
struct Seg {
	
	int size;
	std::vector <ll> v, w;
	
	Seg(int s) : size(1) {
		while (size < s) size <<= 1;
		v.resize(size * 2, 0);
		w.resize(size * 2, 0);
	}
	
	void make(const std::vector <ll>& a, int now, int l, int r) {
		if (!(r - l - 1)) {
			if (size_t(l) < a.size()) v[now] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		make(a, now * 2 + 1, l, mid);
		make(a, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	
	void make(const std::vector <ll>& a) {
		make(a, 0, 0, size);
	}
	
	void update(ll val, int tl, int tr, int now, int l, int r) {
		if (w[now]) {
			v[now] += (r - l) * w[now];
			if (r - l - 1) {
				w[now * 2 + 1] += w[now];
				w[now * 2 + 2] += w[now];
			}
			w[now] = 0;
		}
		if (l >= tr || r <= tl) return;
		if (l >= tl && r <= tr) {
			v[now] += (r - l) * val;
			if (r - l - 1) {
				w[now * 2 + 1] += val;
				w[now * 2 + 2] += val;
			}
			return;
		}
		int mid = (l + r) >> 1;
		update(val, tl, tr, now * 2 + 1, l, mid);
		update(val, tl, tr, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	
	void update(int l, int r, ll val) {
		update(val, l, r, 0, 0, size);
	}
	
	ll get(int ind, int now, int l, int r) {
		if (w[now]) {
			v[now] += (r - l) * w[now];
			if (r - l - 1) {
				w[now * 2 + 1] += w[now];
				w[now * 2 + 2] += w[now];
			}
			w[now] = 0;
		}
		if (!(r - l - 1)) return v[now];
		int mid = (l + r) >> 1;
		if (ind < mid) return get(ind, now * 2 + 1, l, mid);
		return get(ind, now * 2 + 2, mid, r);
	}
	
	ll get(int ind) {
		return get(ind, 0, 0, size);
	}
	
};
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	std::vector <ll> a(n);
	for (ll& x : a) std::cin >> x;
	Seg seg(n);
	seg.make(a);
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int l, r, v; std::cin >> l >> r >> v; l--;
			seg.update(l, r, v);
		} else {
			int ind; std::cin >> ind; ind--;
			std::cout << seg.get(ind) << "\n";
		}
	}
	
}
