#include <bits/stdc++.h>
 
int n, m;
std::vector <std::vector <int>> g;
 
std::vector <int> bck;
std::vector <bool> vis;
void dfs(int node) {
	if (vis[node]) {
		if (bck.size() > size_t(1) && bck[bck.size() - 2] == node) return;
		std::vector <int> ans(1, node + 1);
		while (bck.back() != node) {
			ans.push_back(bck.back() + 1);
			bck.pop_back();
		}
		ans.push_back(node + 1);
		std::cout << ans.size() << "\n";
		for (int x : ans) std::cout << x << " ";
		std::cout << "\n";
		exit(0);
	}
	vis[node] = true;
	bck.push_back(node);
	for (int x : g[node]) {
		dfs(x);
	}
	bck.pop_back();
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	vis.resize(n, false);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
	std::cout << "IMPOSSIBLE\n";
	
}
