#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	ll dp[int(1e6) + 1];
	memset(dp, 0, sizeof(dp));
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = ll(i - 1) * (dp[i - 1] + dp[i - 2]);
		dp[i] %= mod;
	}
	std::cout << dp[n] << "\n";
	
}
