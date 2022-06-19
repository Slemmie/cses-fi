#include <bits/stdc++.h>

int n, m;
std::vector <std::vector <int>> g;
std::vector <int> ans;
std::vector <bool> vis;
std::vector <int> dep;

int dfs(int node, int par = -1, int d = 0) {
	int r = dep[node] = d;
	vis[node] = true;
	bool is = false;
	int cnt = 0;
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
		is |= (node && val >= dep[node]);
		cnt++;
	}
	is |= !node && cnt > 1;
	if (is) {
		ans.push_back(node + 1);
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
	for (int x : ans) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	
}
