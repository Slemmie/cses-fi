#include <bits/stdc++.h>
 
int n;
std::vector <std::vector <int>> g;
 
int dfs(int node = 0, int par = -1) {
	int big = 0, sum = 0;
	for (int x : g[node]) if (x != par) {
		int now = dfs(x, node);
		big = std::max(big, now);
		sum += now;
	}
	big = std::max(big, n - sum - 1);
	if (big <= (n >> 1)) {
		std::cout << node + 1 << "\n";
		exit(0);
	}
	return sum + 1;
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs();
	
}
