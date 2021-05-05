#include <bits/stdc++.h>

int n, m;
std::string s, t;

std::vector <std::vector <int>> dp(5500, std::vector <int> (5500, 1 << 30));

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> s >> t;
	n = (int)s.size();
	m = (int)t.size();
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i) dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
			if (j) dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
			if (i && j) dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
		}
	}
	std::cout << dp[n][m] << "\n";
	
}
