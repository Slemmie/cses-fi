#include <bits/stdc++.h>

std::vector <int> dp(1e6 + 5, -1);

int f(int x) {
	if (!x) return 0;
	if (dp[x] != -1) return dp[x];
	dp[x] = 1 << 30;
	int c = x;
	while (c) {
		dp[x] = std::min(dp[x], f(x - (c % 10)) + 1);
		c /= 10;
	}
	return dp[x];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::cout << f(n) << "\n";
	
}
