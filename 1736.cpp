#include <bits/stdc++.h>

typedef long long ll;

#define lsb(x) (x & (-x))

const int m = 1 << 20;

ll tree[3][m];

void add(int i, int j, ll val) {
	for (; i < m; i += lsb(i)) tree[j][i] += val;
}

ll get(int i, int j) {
	ll r = 0;
	for (; i; i -= lsb(i)) r += tree[j][i];
	return r;
}

void u(int i, ll lo, ll hi) {
	add(1, 2, lo);
	add(i + 1, 2, -lo);
	add(i + 1, 0, lo * ((ll(i) * (ll(i) + 1LL)) >> 1LL));
	add(1, 1, hi);
	add(i + 1, 1, -hi);
	add(i + 1, 0, hi * ll(i));
}

void update(int l, int r, ll lo, ll hi) {
	u(r, lo, hi);
	u(l - 1, -lo, -hi);
}

ll qu(int i) {
	return get(i, 0) + get(i, 1) * ll(i) + get(i, 2) * (ll(i) * (ll(i + 1)) >> 1LL);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll x; std::cin >> x;
		update(i, i, 0, x);
	}
	while (q--) {
		int t; std::cin >> t;
		int l, r; std::cin >> l >> r;
		if (t == 1) {
			update(l, r, 1, 1 - l);
		} else {
			std::cout << qu(r) - qu(l - 1) << "\n";
		}
	}
	
}
