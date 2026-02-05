#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, m; std::cin >> n >> m;
	std::vector <std::vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v;
		g[--u].push_back(--v);
	}
	std::vector <std::bitset <50'003>> dp(n);
	for (int i = 0; i < n; i++) dp[i].set(i);
	std::vector <char> vis(n, false);
	auto f = [&] (auto&& self, int node) -> void {
		if (vis[node]) return;
		vis[node] = true;
		for (int x : g[node]) {
			self(self, x);
			dp[node] |= dp[x];
		}
	};
	for (int i = 0; i < n; i++) f(f, i);
	for (int i = 0; i < n; i++) std::cout << dp[i].count() << (i + 1 == n ? (char) 10 : ' ');
}
