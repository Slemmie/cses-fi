#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int a, b; std::cin >> a >> b;
	std::vector <std::vector <int>> dp(a + 1, std::vector <int> (b + 1, 1 << 29));
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == j) { dp[i][j] = 0; continue; }
			for (int k = 1; k < i; k++) dp[i][j] = std::min(dp[i][j], dp[k][j] + dp[i - k][j]);
			for (int k = 1; k < j; k++) dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[i][j - k]);
			dp[i][j]++;
		}
	}
	std::cout << dp[a][b] << "\n";
	
}
