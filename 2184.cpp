#include <bits/stdc++.h>

constexpr const int mxn = 200'005;

typedef long long ll;

struct RS {
	ll v[mxn];
	RS() {
		memset(v, 0, sizeof(v));
	}
	void set(int ind, int val) {
		v[ind] = val;
	}
	void init() {
		for (int i = 1; i < mxn; i++) v[i] += v[i - 1];
	}
	ll sum(int l, int r) {
		return v[r] - (l ? v[l - 1] : 0);
	}
};

struct RMN {
	int bin[18][mxn];
	RMN() {
		memset(bin, 127, sizeof(bin));
	}
	void set(int ind, int val) {
		bin[0][ind] = val;
	}
	void init() {
		for (int b = 1; b < 18; b++)
			for (int i = 0; i < mxn; i++)
				bin[b][i] = std::min(bin[b - 1][i], i + (1 << (b - 1)) < mxn ? bin[b - 1][i + (1 << (b - 1))] : 1 << 30);
	}
	int min(int l, int r) {
		if (l == r) return bin[0][l];
		const int b = std::bit_width((unsigned) (r - l)) - 1;
		return std::min(bin[b][l], bin[b][r - (1 << b) + 1]);
	}
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	RS rs[30];
	RMN rmn[30];
	int n, q; std::cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		rs[std::bit_width((unsigned) x) - 1].set(i, x);
		rmn[std::bit_width((unsigned) x) - 1].set(i, x);
	}
	for (int i = 0; i < 30; i++) rs[i].init();
	for (int i = 0; i < 30; i++) rmn[i].init();
	while (q--) {
		int l, r; std::cin >> l >> r; l--, r--;
		ll ans = 0;
		for (int i = 0; i < 30; i++) {
			if (ans >= (1 << (i + 1)) - 1) ans += rs[i].sum(l, r);
			else if (rmn[i].min(l, r) <= ans + 1) ans += rs[i].sum(l, r);
			else break;
		}
		std::cout << ++ans << (char) 10;
	}
}
