#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, x; std::cin >> n >> x;
	std::vector <int> h(n), s(n);
	for (int& i : h) std::cin >> i;
	for (int& i : s) std::cin >> i;
	std::vector <int> dp(x + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = x - h[i]; j >= 0; j--) {
			dp[j + h[i]] = std::max(dp[j + h[i]], dp[j] + s[i]);
		}
	}
	std::cout << dp[x] << "\n";
	
}
