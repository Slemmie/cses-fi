#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::vector <int> dp(5000, 0);
	for (int i = 3; i < 5000; i++) {
		std::vector <int> now(5000, 0);
		for (int j = 1; j + j < i; j++) {
			now[dp[j] ^ dp[i - j]] |= 1;
		}
		for (int j = 0; j < 5000; j++) {
			if (!now[j]) {
				dp[i] = j;
				break;
			}
		}
	}
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		if (n >= 5000 || dp[n]) std::cout << "first\n";
		else std::cout << "second\n";
	}
	
}
