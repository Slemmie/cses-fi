#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, m; std::cin >> n >> m;
	std::vector <int> a(n), b(m);
	for (int& x : a) std::cin >> x;
	for (int& x : b) std::cin >> x;
	std::vector <std::vector <int>> dp(n + 1, std::vector <int> (m + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			dp[i + 1][j + 1] = std::max({ dp[i + 1][j + 1], dp[i][j + 1], dp[i + 1][j] });
		}
	}
	std::cout << dp[n][m] << "\n";
	std::vector <int> ans;
	int i = n, j = m;
	while (dp[i][j]) {
		if (dp[i][j] == dp[i - 1][j - 1] + 1 && a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--, j--;
		} else if (dp[i][j - 1] > dp[i - 1][j]) j--;
		else i--;
	}
	while (ans.size()) std::cout << ans.back() << " \n"[ans.size() == 1], ans.pop_back();
}
