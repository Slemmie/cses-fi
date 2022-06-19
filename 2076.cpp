#include <bits/stdc++.h>

int n, m;
std::vector <std::vector <int>> g;
std::vector <std::pair <int, int>> ans;
std::vector <bool> vis;
std::vector <int> dep;

int dfs(int node, int par = -1, int d = 0) {
	int r = dep[node] = d;
	vis[node] = true;
	for (int x : g[node]) {
		if (x == par) {
			continue;
		}
		if (vis[x]) {
			r = std::min(r, dep[x]);
			continue;
		}
		int val = dfs(x, node, d + 1);
		r = std::min(r, val);
		if (val >= dep[x]) {
			ans.emplace_back(node + 1, x + 1);
		}
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vis.resize(n, false);
	dep.resize(n);
	dfs(0);
	std::cout << ans.size() << "\n";
	for (auto p : ans) {
		std::cout << p.first << " " << p.second << "\n";
	}
	
}
