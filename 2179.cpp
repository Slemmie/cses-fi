#include <bits/stdc++.h>

int n, m;
std::vector <std::vector <int>> g;
std::vector <int> deg;
std::set <std::pair <int, int>> st;
std::vector <bool> vis;

bool dfs(int node) {
	vis[node] = true;
	for (int x : g[node]) {
		if (vis[x]) {
			continue;
		}
		if (dfs(x)) {
			deg[node] ^= 1;
			st.erase({ std::min(node, x), std::max(node, x) });
			st.insert({ std::max(node, x), std::min(node, x) });
		}
	}
	return deg[node];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	deg.resize(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[std::min(u, v)] ^= 1;
		st.insert({ std::min(u, v), std::max(u, v) });
	}
	vis.resize(n, false);
	for (int i = 0; i < n; i++) {
		if (vis[i]) {
			continue;
		}
		if (dfs(i)) {
			std::cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	for (auto p : st) {
		std::cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
	
}
