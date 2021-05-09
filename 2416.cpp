#include <bits/stdc++.h>

typedef long long ll;

struct Seg {
	
	int size;
	
	std::vector <ll> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size << 1, 0);
	}
	
	void add(int ind, ll val) {
		add(ind, val, 0, 0, size);
	}
	
	void add(int ind, ll val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] += val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) add(ind, val, (now << 1) | 1, l, mid);
		else add(ind, val, (now << 1) + 2, mid, r);
		v[now] = v[(now << 1) | 1] + v[(now << 1) + 2];
	}
	
	ll get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
	ll get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return get(tl, tr, (now << 1) | 1, l, mid) + get(tl, tr, (now << 1) + 2, mid, r);
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, Q; std::cin >> n >> Q;
	Seg seg(n);
	std::vector <ll> a(n + 1, 1LL << 60LL), pre(n + 1, 0), ans(Q, -1), con(n + 1, 0);
	std::vector <std::vector <std::pair <int, int>>> que(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		pre[i] = a[i];
		if (i) pre[i] += pre[i - 1];
	}
	pre[n] = pre[n - 1] + a[n];
	for (int i = 0; i < Q; i++) {
		int l, r; std::cin >> l >> r; l--, r--;
		que[l].push_back({ r, i });
	}
	std::deque <int> q;
	q.push_back(n);
	for (int i = n - 1; i >= 0; i--) {
		while (q.size() && a[i] >= a[q.front()]) {
			seg.add(q.front(), -con[q.front()]);
			q.pop_front();
		}
		con[i] = ll(q.front() - i - 1) * a[i] - ll(pre[q.front() - 1] - pre[i]);
		seg.add(i, con[i]);
		q.push_front(i);
		for (auto p : que[i]) {
			int ind = std::upper_bound(q.begin(), q.end(), p.first) - q.begin() - 1;
			ans[p.second] = (ind ? seg.get(i, q[ind - 1] + 1) : 0LL) + ll(p.first - q[ind]) * a[q[ind]] - ll(pre[p.first] - pre[q[ind]]);
		}
	}
	for (int i = 0; i < Q; i++) {
		std::cout << ans[i] << "\n";
	}
	
}
