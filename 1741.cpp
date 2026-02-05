#include <bits/stdc++.h>

typedef long long ll;

constexpr const int R = 2'000'005;

struct Seg {
	int laz[R * 4];
	int sum[R * 4];
	int ran[R * 4];

	void build(int now, int l, int r) {
		if (!(r - l - 1)) {
			sum[now] = 0;
			ran[now] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(now * 2 + 1, l, mid);
		build(now * 2 + 2, mid, r);
		auto p = merge({ sum[now * 2 + 1], ran[now * 2 + 1] }, { sum[now * 2 + 2], ran[now * 2 + 2] });
		sum[now] = p.first;
		ran[now] = p.second;
	}

	std::pair <int, int> merge(std::pair <int, int> l, std::pair <int, int> r) {
		if (l.first < r.first) return l;
		if (r.first < l.first) return r;
		return { l.first, l.second + r.second };
	}

	void push(int now, int l, int r) {
		sum[now] += laz[now];
		if (r - l - 1) laz[now * 2 + 1] += laz[now], laz[now * 2 + 2] += laz[now];
		laz[now] = 0;
	}

	void update(int val, int tl, int tr, int now, int l, int r) {
		push(now, l, r);
		if (l >= r) return;
		if (l >= tr || r <= tl) return;
		if (l >= tl && r <= tr) {
			laz[now] += val;
			push(now, l, r);
			return;
		}
		int mid = (l + r) >> 1;
		update(val, tl, tr, now * 2 + 1, l, mid);
		update(val, tl, tr, now * 2 + 2, mid, r);
		auto p = merge({ sum[now * 2 + 1], ran[now * 2 + 1] }, { sum[now * 2 + 2], ran[now * 2 + 2] });
		sum[now] = p.first;
		ran[now] = p.second;
	}

	std::pair <int, int> query(int tl, int tr, int now, int l, int r) {
		push(now, l, r);
		if (l >= r) return { 1, 0 };
		if (l >= tr || r <= tl) return { 1, 0 };
		if (l >= tl && r <= tr) return { sum[now], ran[now] };
		int mid = (l + r) >> 1;
		return merge(query(tl, tr, now * 2 + 1, l, mid), query(tl, tr, now * 2 + 2, mid, r));
	}
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	Seg seg;
	memset(seg.laz, 0, sizeof(seg.laz));
	memset(seg.sum, 0, sizeof(seg.sum));
	memset(seg.ran, 0, sizeof(seg.ran));
	seg.build(0, 0, R);
	std::vector <std::vector <std::pair <int, int>>> ops[2];
	ops[0].resize(R);
	ops[1].resize(R);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
		x1 += 1'000'001;
		y1 += 1'000'001;
		x2 += 1'000'001;
		y2 += 1'000'001;
		ops[0][y1].emplace_back(x1, x2);
		ops[1][y2].emplace_back(x1, x2);
	}
	ll ans = (ll) (R - 0) * (R - 1);
	for (int i = 1; i < R; i++) {
		for (auto [l, r] : ops[0][i]) seg.update(+1, l + 1, r + 1, 0, 0, R);
		for (auto [l, r] : ops[1][i]) seg.update(-1, l + 1, r + 1, 0, 0, R);
		auto node = seg.query(0, R, 0, 0, R);
		ans -= node.second * !node.first;
	}
	std::cout << ans << (char) 10;
}
