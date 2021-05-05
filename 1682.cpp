#include <bits/stdc++.h>

int n, m;
std::vector <std::vector <int>> g, h;

std::vector <bool> vis;
int dfs(int node) {
	if (vis[node]) return 0;
	vis[node] = true;
	int r = 1;
	for (int x : g[node]) r += dfs(x);
	return r;
}

int dfs2(int node) {
	if (vis[node]) return 0;
	vis[node] = true;
	int r = 1;
	for (int x : h[node]) r += dfs2(x);
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	h.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		h[v].push_back(u);
	}
	vis.resize(n, false);
	if (dfs(0) != n) {
		std::cout << "NO\n";
		for (int i = 1; i < n; i++) {
			if (!vis[i]) {
				std::cout << 1 << " " << i + 1 << "\n";
				break;
			}
		}
		return 0;
	}
	vis.clear();
	vis.resize(n, false);
	if (dfs2(0) != n) {
		std::cout << "NO\n";
		for (int i = 1; i < n; i++) {
			if (!vis[i]) {
				std::cout << i + 1 << " " << 1 << std::endl;
				break;
			}
		}
		return 0;
	}
	std::cout << "YES\n";
	
}
