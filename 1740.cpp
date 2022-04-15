#include <bits/stdc++.h>

struct Seg {
	
	int size;
	std::vector <int> v;
	
	Seg(int s) {
		size = 1;
		while ((size <<= 1) < s);
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
		if (ind < mid) {
			add(ind, val, now * 2 + 1, l, mid);
		} else {
			add(ind, val, now * 2 + 2, mid, r);
		}
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	
	int get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
	int get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) {
			return 0;
		}
		if (l >= tl && r <= tr) {
			return v[now];
		}
		int mid = (l + r) >> 1;
		return get(tl, tr, now * 2 + 1, l, mid) + get(tl, tr, now * 2 + 2, mid, r);
	}
	
};

struct P {
	int t;
	int l, r;
	int s;
	int x;
	bool operator < (const P& oth) const {
		return s == oth.s ? t > oth.t : s < oth.s;
	}
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	Seg seg(2e6 + 5);
	std::vector <P> a(n);
	for (P& p : a) {
		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
		x1 += 1e6;
		y1 += 1e6;
		x2 += 1e6;
		y2 += 1e6;
		p.t = x1 == x2;
		p.l = p.t ? y1 : x1;
		p.r = p.t ? y2 : x2;
		p.s = y1;
		p.x = x1;
	}
	std::map <int, std::vector <int>> mp;
	std::sort(a.begin(), a.end());
	long long ans = 0;
	for (P p : a) {
		if (p.t) {
			seg.add(p.x, 1);
			mp[p.r].push_back(p.x);
		} else {
			while (mp.size() && mp.begin()->first < p.s) {
				seg.add(mp.begin()->second.back(), -1);
				mp.begin()->second.pop_back();
				if (mp.begin()->second.empty()) {
					mp.erase(mp.begin());
				}
			}
			ans += seg.get(p.l, p.r + 1);
		}
	}
	std::cout << ans << "\n";
	
}
