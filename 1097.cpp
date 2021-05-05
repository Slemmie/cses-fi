#include <bits/stdc++.h>

typedef long long ll;

int n;
std::vector <ll> a;
std::vector <std::vector <ll>> dp(5001, std::vector <ll> (5001, 1LL << 60LL));

ll f(int l, int r, bool t) {
	if (l > r) return 0;
	if (dp[l][r] != (1LL << 60LL)) return dp[l][r];
	if (t) return dp[l][r] = std::min(f(l + 1, r, t ^ 1), f(l, r - 1, t ^ 1));
	if (!t) return dp[l][r] = std::max(f(l + 1, r, t ^ 1) + a[l], f(l, r - 1, t ^ 1) + a[r]);
	return 0;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	a.resize(n);
	for (ll& x : a) std::cin >> x;
	std::cout << f(0, n - 1, 0) << "\n";
	
}
