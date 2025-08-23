#include <bits/stdc++.h>

typedef long long ll;

struct Item {
	ll ans = 0;
	ll pre = 0, suf = 0;
	ll sum = 0;
};

Item merge(const Item& lhs, const Item& rhs) {
	Item res;
	res.ans = std::max({ lhs.ans, rhs.ans, lhs.suf + rhs.pre });
	res.pre = std::max(lhs.pre, lhs.sum + rhs.pre);
	res.suf = std::max(rhs.suf, lhs.suf + rhs.sum);
	res.sum = lhs.sum + rhs.sum;
	return res;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, q; std::cin >> n >> q;
	std::vector <std::vector <Item>> tbl(19, std::vector <Item> (n));
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		tbl[0][i] = { std::max(0, x), std::max(0, x), std::max(0, x), x };
	}
	for (int b = 1; b < 19; b++)
		for (int i = 0; i + (1 << b) <= n; i++)
			tbl[b][i] = merge(tbl[b - 1][i], tbl[b - 1][i + (1 << (b - 1))]);
	while (q--) {
		int l, r; std::cin >> l >> r;
		l--, r--;
		int len = r - l + 1;
		Item ans;
		for (int b = 0; b < 19; b++) {
			if (len >> b & 1) {
				ans = merge(ans, tbl[b][l]);
				l += 1 << b;
			}
		}
		std::cout << ans.ans << "\n";
	}
}
