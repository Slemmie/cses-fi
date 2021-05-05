#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::vector <int> dp(n * 1005 + 1005, 0);
	for (int i = 0; i < n; i++) {
		for (int j = a[i] + 1; j < n * 1005; j++) {
			if (!dp[j] && dp[j - a[i]] != i + 1 && dp[j - a[i]]) dp[j] = i + 1;
		}
		dp[a[i]] = i + 1;
	}
	std::vector <int> ans;
	for (int i = 0; i < n * 1005; i++) {
		if (dp[i]) ans.push_back(i);
	}
	std::cout << ans.size() << "\n";
	for (int x : ans) std::cout << x << " ";
	std::cout << "\n";
	
}
