#include <bits/stdc++.h>

const int mod = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::vector <std::vector <int>> dp(n, std::vector <int> (m + 2, 0));
	if (a[0] == 0) dp[0] = std::vector <int> (m + 1, 1);
	else dp[0][a[0]] = 1;
	dp[0][0] = dp[0][m + 1] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i - 1][j];
				if (dp[i][j] >= mod) dp[i][j] %= mod;
				dp[i][j] += dp[i - 1][j + 1];
				if (dp[i][j] >= mod) dp[i][j] %= mod;
			}
		} else {
			dp[i][a[i]] += dp[i - 1][a[i] - 1];
			dp[i][a[i]] += dp[i - 1][a[i]];
			if (dp[i][a[i]] >= mod) dp[i][a[i]] %= mod;
			dp[i][a[i]] += dp[i - 1][a[i] + 1];
			if (dp[i][a[i]] >= mod) dp[i][a[i]] %= mod;
		}
	}
	int ans = 0;
	for (int x : dp[n - 1]) {
		ans += x;
		if (ans >= mod) ans %= mod;
	}
	std::cout << ans << "\n";
	
}
