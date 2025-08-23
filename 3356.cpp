#include <bits/stdc++.h>

struct Seg {
	int size;
	std::vector <int> v;
	Seg(int s) {
		size = 1;
		while (size <= s) size <<= 1;
		v.resize(size << 1, 1 << 30);
	}
	void update(int ind, int val) {
		update(ind, val, 0, 0, size);
	}
	void update(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) update(ind, val, now * 2 + 1, l, mid);
		else update(ind, val, now * 2 + 2, mid, r);
		v[now] = std::min(v[now * 2 + 1], v[now * 2 + 2]);
	}
	int query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
	int query(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 1 << 30;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return std::min(query(tl, tr, now * 2 + 1, l, mid), query(tl, tr, now * 2 + 2, mid, r));
	}
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, q; std::cin >> n >> q;
	std::map <int, std::set <int>> mp;
	Seg seg(n);
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		a[i] = x;
		if (mp[x].size()) seg.update(*mp[x].rbegin(), i);
		mp[x].insert(i);
	}
	while (q--) {
		int t; std::cin >> t;
		if (t == 1) {
			int k, u; std::cin >> k >> u;
			k--;
			auto it = mp[a[k]].find(k);
			if (std::next(it) != mp[a[k]].end() && it != mp[a[k]].begin()) seg.update(*std::prev(it), *std::next(it));
			else if (it != mp[a[k]].begin()) seg.update(*std::prev(it), 1 << 30);
			mp[a[k]].erase(k);
			mp[u].insert(k);
			it = mp[u].find(k);
			if (std::next(it) != mp[u].end()) seg.update(k, *std::next(it));
			else seg.update(k, 1 << 30);
			if (it != mp[u].begin()) seg.update(*std::prev(it), k);
			a[k] = u;
		} else {
			int l, r; std::cin >> l >> r;
			l--, r--;
			int mx = seg.query(l, r + 1);
			std::cout << (mx > r ? "YES\n" : "NO\n");
		}
	}
}
