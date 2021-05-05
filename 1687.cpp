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
		int u, x; std::cin >> u >> x; u--;
		if (d[u] < x) { std::cout << "-1\n"; continue; }
		for (int i = 0; i < 30; i++)
			if ((x >> i) & 1) u = lca[i][u];
		std::cout << u + 1 << "\n";
	}
	
}
