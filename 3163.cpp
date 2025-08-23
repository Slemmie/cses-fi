#include <bits/stdc++.h>

struct Seg {
	int size;
	std::vector <int> v;
	Seg(int s) {
		size = 1;
		while (size <= s) size <<= 1;
		v.resize(size << 1, 0);
	}
	void update(int ind, int val) {
		update(ind, val, 0, 0, size);
	}
	void update(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] += val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) update(ind, val, now * 2 + 1, l, mid);
		else update(ind, val, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	int query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
	int query(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return query(tl, tr, now * 2 + 1, l, mid) + query(tl, tr, now * 2 + 2, mid, r);
	}
};

struct Q {
	int l, r;
	int lb, ub;
	int i;
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, q; std::cin >> n >> q;
	std::vector <int> a(n);
	std::vector <std::pair <int, int>> aa(n);
	for (int& x : a) std::cin >> x;
	for (int i = 0; i < n; i++) aa[i] = { a[i], i };
	std::sort(aa.begin(), aa.end());
	std::vector <Q> qu(q);
	for (int i = 0; i < q; i++) {
		std::cin >> qu[i].l >> qu[i].r >> qu[i].lb >> qu[i].ub;
		qu[i].i = i;
		qu[i].l--, qu[i].r--;
	}
	std::vector <int> ans(q, 0);
	std::sort(qu.begin(), qu.end(), [] (const Q& lhs, const Q& rhs) -> bool { return lhs.lb < rhs.lb; });
	Seg seg(n);
	int ai = 0;
	for (const Q& cq : qu) {
		while (ai < n && aa[ai].first < cq.lb) seg.update(aa[ai++].second, 1);
		ans[cq.i] -= seg.query(cq.l, cq.r + 1);
	}
	std::sort(qu.begin(), qu.end(), [] (const Q& lhs, const Q& rhs) -> bool { return lhs.ub < rhs.ub; });
	seg = Seg(n);
	ai = 0;
	for (const Q& cq : qu) {
		while (ai < n && aa[ai].first <= cq.ub) seg.update(aa[ai++].second, 1);
		ans[cq.i] += seg.query(cq.l, cq.r + 1);
	}
	for (int x : ans) std::cout << x << "\n";
}
