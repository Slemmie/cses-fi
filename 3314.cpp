#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <int> oa(n);
	std::vector <std::pair <int, int>> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		oa[i] = a[i].first;
		a[i].second = i;
	}
	std::sort(a.begin(), a.end());
	std::set <int> left;
	for (int i = 0; i < n; i++) left.insert(i);
	std::vector <int> dp(n, 1);
	int ans = 0;
	for (auto [x, i] : a) {
		ans = std::max(ans, dp[i]);
		left.erase(i);
		auto r = left.upper_bound(i);
		if (r != left.end()) {
			dp[*r] = std::max(dp[*r], dp[i] + (x < oa[*r]));
		}
		if (r != left.begin()) {
			r--;
			dp[*r] = std::max(dp[*r], dp[i] + (x < oa[*r]));
		}
	}
	std::cout << ans << "\n";
}
