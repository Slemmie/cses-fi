#include <bits/stdc++.h>

constexpr const int mod = 1'000'000'007;

int dp[2][505][505];

int main() {
	int n, k; std::cin >> n >> k;
	if (k > 2 * n) {
		std::cout << "0\n";
		return 0;
	}
	if (n == 1 && k == 1) {
		std::cout << "1\n";
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= std::min(n, k); i++) {
		if (k - i < n) {
			dp[0][i][k - i] = 1;
		}
	}
	for (int i = n; i; i--) {
		int p[2];
		for (p[0] = 0; p[0] <= std::min(i, k); p[0]++) {
			for (p[1] = 0; p[0] + p[1] <= k && p[1] <= std::min(i, k); p[1]++) {
				int avail = i - p[i & 1];
				int left = k - p[0] - p[1];
				int& d = dp[1][p[0]][p[1]];
				for (int place = 0; place <= std::min(2, left); place++) {
					int next_p[2] = { p[0], p[1] };
					next_p[i & 1] += place;
					int ways = 1;
					if (place == 1) ways = avail * (1 + (i != n));
					if (place == 2) ways = i == n ? 0 : avail * (avail - 1);
					d += (long long) ways * dp[0][next_p[0]][next_p[1]] % mod;
					if (d >= mod) d -= mod;
				}
			}
		}
		memcpy(dp[0], dp[1], sizeof(dp[0]));
		memset(dp[1], 0, sizeof(dp[1]));
	}
	std::cout << dp[0][0][0] << "\n";
}
