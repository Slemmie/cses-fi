#include <bits/stdc++.h>
 
typedef long long ll;
 
int n;
std::vector <std::vector <int>> g;
std::vector <ll> numc, dist;
 
ll dfs1(int node, int par) {
	ll r = 0;
	for (size_t i = 0; i < g[node].size(); i++) if (g[node][i] != par) {
		r += dfs1(g[node][i], node) + numc[g[node][i]];
		numc[node] += numc[g[node][i]];
	}
	return r;
}
 
void dfs2(int node, int par, ll now) {
	dist[node] = now;
	for (size_t i = 0; i < g[node].size(); i++) if (g[node][i] != par)
		dfs2(g[node][i], node, now + n - numc[g[node][i]] * 2LL);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	g.resize(n);
	numc.resize(n, 1);
	dist.resize(n, 0);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll start = dfs1(0, -1);
	dfs2(0, -1, start);
	for (ll x : dist) std::cout << x << " ";
	std::cout << "\n";
	
}
