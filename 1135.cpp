#include <bits/stdc++.h>
 
int msb(int x) {
	if (!x) return 0;
	int r = 0;
	while (x) x >>= 1, r++;
	return r;
}
 
struct Node {
	int d;
	std::vector <int> an;
	std::vector <int> nei;
	Node() : d(0), an(19, 0) { }
};
 
int n, q;
std::vector <Node> g;
 
void dfs1(int node, int par) {
	static std::vector <int> vnow;
	vnow.push_back(node);
	if (par == -1) g[node].d = 0;
	else g[node].d = g[par].d + 1;
	for (size_t i = 0; (size_t(1) << i) < vnow.size(); i++)
		g[node].an[i] = vnow[vnow.size() - (1 << i) - 1];
	for (size_t i = 0; i < g[node].nei.size(); i++) {
		if (g[node].nei[i] == par) continue;
		dfs1(g[node].nei[i], node);
	}
	vnow.pop_back();
}
 
int dist(int u, int v) {
	if (g[u].d > g[v].d) std::swap(u, v);
	int r = g[v].d - g[u].d;
	while (g[v].d - g[u].d)
		v = g[v].an[msb(g[v].d - g[u].d) - 1];
	while (g[u].an[0] != g[v].an[0])
		for (int i = 18; i >= 0; i--)
			if (g[u].an[i] != g[v].an[i]) {
				u = g[u].an[i], v = g[v].an[i];
				r += 2 * (1 << i);
				break;
			}
	return r + 2 * (u != v);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> q;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].nei.push_back(v);
		g[v].nei.push_back(u);
	}
	dfs1(0, -1);
	while (q--) {
		int u, v; std::cin >> u >> v; u--, v--;
		std::cout << dist(u, v) << "\n";
	}
	
}
