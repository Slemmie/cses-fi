#include <bits/stdc++.h>
 
int n, q;
std::vector <std::vector <int>> g, lca;
std::vector <int> d, p;
 
void dfs(int node, int dpth) {
	d[node] = dpth;
	for (int x : g[node]) dfs(x, dpth + 1);
}
 
int main() {
	
	std::cin >> n >> q;
	g.resize(n); d.resize(n); p.resize(n);
	lca.resize(30, std::vector <int> (n));
	p.front() = 0;
	for (int i = 1; i < n; i++) {
		int u; std::cin >> u;
		g[u - 1].push_back(i);
		p[i] = u - 1;
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) lca.front()[i] = p[i];
	for (int k = 1; k < 30; k++)
		for (int u = 0; u < n; u++)
			lca[k][u] = lca[k - 1][lca[k - 1][u]];
	while (q--) {
		int u, v; std::cin >> u >> v; u--; v--;
		if (d[u] < d[v]) std::swap(u, v);
		int x = d[u] - d[v];
		for (int i = 0; i < 30; i++)
			if ((x >> i) & 1) u = lca[i][u];
		if (u == v) { std::cout << u + 1 << "\n"; continue; }
		while (p[u] != p[v]) {
			for (int i = 29; i >= 0; i--) {
				if (lca[i][u] == lca[i][v]) continue;
				u = lca[i][u], v = lca[i][v];
				break;
			}
		}
		std::cout << p[u] + 1 << "\n";
	}
	
}
