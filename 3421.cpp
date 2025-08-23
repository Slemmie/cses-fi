#include <bits/stdc++.h>

constexpr const int mod = 1'000'000'007;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::map <int, int> mp;
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		mp[x]++;
	}
	int ans = 0;
	int cnv = 1;
	for (auto [x, c] : mp) {
		(ans += (long long) cnv * c % mod) %= mod;
		(cnv += (long long) cnv * c % mod) %= mod;
	}
	std::cout << ans << "\n";
}
