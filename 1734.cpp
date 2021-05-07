#include <bits/stdc++.h>

struct Seg {
	
	int size;
	
	std::vector <int> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size << 1, 0);
	}
	
	void add(int ind, int val) {
		add(ind, val, 0, 0, size);
	}
	
	void add(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] += val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) add(ind, val, (now << 1) | 1, l, mid);
		else add(ind, val, (now << 1) + 2, mid, r);
		v[now] = v[(now << 1) | 1] + v[(now << 1) + 2];
	}
	
	int get(int ind) {
		return get(0, ind + 1, 0, 0, size);
	}
	
	int get(int tl, int tr, int now, int l, int r) {
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
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::vector <std::vector <std::pair <int, int>>> b(n);
	for (int i = 0; i < q; i++) {
		int l, r; std::cin >> l >> r; l--, r--;
		b[l].emplace_back(r, i);
	}
	std::map <int, int> last;
	std::vector <int> ans(q, -1);
	for (int i = n - 1; i >= 0; i--) {
		auto it = last.find(a[i]);
		if (it != last.end()) seg.add(it->second, -1);
		last[a[i]] = i;
		seg.add(i, 1);
		for (auto p : b[i]) ans[p.second] = seg.get(p.first);
	}
	for (int x : ans) std::cout << x << "\n";
	
}
