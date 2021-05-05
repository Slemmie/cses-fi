#include <bits/stdc++.h>

const int mod = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::string> g(n);
	for (auto& x : g) std::cin >> x;
	std::vector <std::vector <int>> dp(n + 1, std::vector <int> (n + 1, 0));
	dp[n - 1][n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) * (g[i][j] == '.');
			if (dp[i][j] >= mod) dp[i][j] %= mod;
		}
	}
	std::cout << dp[0][0] << "\n";
	
}
