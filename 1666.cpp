#include <bits/stdc++.h>
 
int n, m;
std::vector <std::vector <int>> g;
 
std::vector <bool> vis;
void f(int node) {
	if (vis[node]) return;
	vis[node] = true;
	for (int x : g[node]) f(x);
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
	std::vector <int> ans;
	for (int i = 0; i < n; i++) if (!vis[i]) {
		ans.push_back(i + 1);
		f(i);
	}
	std::cout << ans.size() - 1 << "\n";
	for (int i = 0; i < (int)ans.size() - 1; i++) {
		std::cout << ans[i] << " " << ans[i + 1] << "\n";
	}
	
}
