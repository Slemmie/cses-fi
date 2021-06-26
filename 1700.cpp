#include <bits/stdc++.h>

int ind = 0;
std::map <std::vector <int>, int> mp;

int dfs(int node, int par, const std::vector <std::vector <int>>& g) {
	std::vector <int> now;
	for (int x : g[node]) if (x != par) {
		now.push_back(dfs(x, node, g));
	}
	std::sort(now.begin(), now.end());
	if (!mp.count(now)) mp[now] = ind++;
	return mp[now];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		ind = 0;
		mp.clear();
		int n; std::cin >> n;
		std::vector <std::vector <int>> g(n), h(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; std::cin >> u >> v; u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v; std::cin >> u >> v; u--, v--;
			h[u].push_back(v);
			h[v].push_back(u);
		}
		if (dfs(0, -1, g) == dfs(0, -1, h)) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	
}
