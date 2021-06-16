#include <bits/stdc++.h>

double dp[101][6 * 101];

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, l, r; std::cin >> n >> l >> r;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n * 6; j++) {
			for (int k = 1; k <= 6; k++) {
				if (j - k >= 0) {
					dp[i][j] += dp[i - 1][j - k];
				}
			}
			dp[i][j] /= 6.0;
		}
	}
	double ans = 0;
	for (int i = l; i <= r; i++) {
		ans += dp[n][i];
	}
	ans *= 1e6;
	ans = llround(ans);
	ans /= 1e6;
	std::cout << std::fixed << std::setprecision(6) << ans << "\n";
	
}
