#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	int w[20];
	for (int i = 0; i < n; i++) std::cin >> w[i];
	std::pair <int, int>dp[1 << 20];
	for (int i = 1; i < (1 << n); i++) dp[i] = { n, 0 };
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if ((~mask >> i) & 1) {
				if (dp[mask].second + w[i] <= m)
					dp[mask | (1 << i)] = std::min(dp[mask | (1 << i)], { dp[mask].first, dp[mask].second + w[i] });
				else
					dp[mask | (1 << i)] = std::min(dp[mask | (1 << i)], { dp[mask].first + 1, w[i] });
			}
		}
	}
	std::cout << dp[(1 << n) - 1].first + 1 << "\n";
	
}
