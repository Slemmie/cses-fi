#include <bits/stdc++.h>

typedef long long ll;

constexpr const int mxn = 2'000'005;
constexpr const int mod = 1'000'000'007;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::vector <int> spf(mxn);
	for (int i = 0; i < mxn; i++) spf[i] = i;
	for (int i = 2; 2 * i * i < mxn; i++)
		if (spf[i] == i)
			for (int j = i * i; j < mxn; j += i)
				if (spf[j] == j)
					spf[j] = i;
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x, x--;
	std::vector <char> vis(n, false);
	std::unordered_map <int, int> mp;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int cnt = 0;
		int v = i;
		do {
			vis[v] = true;
			v = a[v];
			cnt++;
		} while (v != i);
		while (cnt > 1) {
			int p = spf[cnt];
			int c = 0;
			while (cnt % p == 0) {
				cnt /= p;
				c++;
			}
			mp[p] = std::max(mp[p], c);
		}
	}
	int ans = 1;
	for (auto [p, e] : mp) {
		ll now = 1;
		for (int i = 0; i < e; i++) (now *= p) %= mod;
		ans = (ll) ans * now % mod;
	}
	std::cout << ans << (char) 10;
}
