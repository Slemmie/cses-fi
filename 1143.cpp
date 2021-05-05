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
		v[now] = std::max(v[(now << 1) | 1], v[(now << 1) + 2]);
	}
	
	int get(int req) {
		if (v[0] < req) return -1;
		return get(req, 0, 0, size);
	}
	
	int get(int req, int now, int l, int r) {
		if (!(r - l - 1)) return l;
		int mid = (l + r) >> 1;
		if (v[(now << 1) | 1] >= req) return get(req, (now << 1) | 1, l, mid);
		return get(req, (now << 1) + 2, mid, r);
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	Seg seg(n);
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		seg.add(i, p);
	}
	while (m--) {
		int req; std::cin >> req;
		int ans = seg.get(req);
		if (ans != -1) seg.add(ans, -req);
		std::cout << ans + 1 << " \n"[!m];
	}
	
}
