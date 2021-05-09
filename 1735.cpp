#include <bits/stdc++.h>

typedef long long ll;

struct Seg {
	
	int size;
	
	std::vector <ll> v, t, w;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size << 1, 0);
		t.resize(size << 1, 1);
		w.resize(size << 1, 0);
	}
	
	void update(int now, int l, int r) {
		v[now] = t[now] * v[now] + w[now] * ll(r - l);
		if (r - l - 1) {
			if (!t[now])
				t[(now << 1) | 1] = w[(now << 1) | 1] =
				t[(now << 1) + 2] = w[(now << 1) + 2] = 0;
			w[(now << 1) | 1] += w[now];
			w[(now << 1) + 2] += w[now];
		}
		t[now] = 1;
		w[now] = 0;
	}
	
	void change(int tl, int tr, ll a, ll b, int now, int l, int r) {
		update(now, l, r);
		if (l >= tr || r <= tl) return;
		if (l >= tl && r <= tr) {
			t[now] = a;
			w[now] = b;
			update(now, l, r);
			return;
		}
		int mid = (l + r) >> 1;
		change(tl, tr, a, b, (now << 1) | 1, l, mid);
		change(tl, tr, a, b, (now << 1) + 2, mid, r);
		v[now] = v[(now << 1) | 1] + v[(now << 1) + 2];
	}
	
	ll get(int tl, int tr, int now, int l, int r) {
		update(now, l, r);
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return get(tl, tr, (now << 1) | 1, l, mid) + get(tl, tr, (now << 1) + 2, mid, r);
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	Seg seg(n);
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		seg.change(i, i + 1, 0, x, 0, 0, seg.size);
	}
	while (q--) {
		int t; std::cin >> t;
		if (t == 3) {
			int l, r; std::cin >> l >> r; l--;
			std::cout << seg.get(l, r, 0, 0, seg.size) << "\n";
		} else {
			int l, r, x; std::cin >> l >> r >> x; l--;
			seg.change(l, r, t == 1, x, 0, 0, seg.size);
		}
	}
	
}
