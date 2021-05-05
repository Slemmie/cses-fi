#include <bits/stdc++.h>
 
int msb(int x) {
	if (!x) return 0;
	int r = 0;
	while (x) x >>= 1, r++;
	return r;
}
 
struct Node {
	int d, add, sub, subhere, ans;
	std::vector <int> nei, ban;
	Node() : d(0), add(0), sub(0), subhere(0), ans(0), ban(19, 0) { }
};
 
int n, m;
std::vector <Node> g;
 
bool cmp(const int& a, const int& b) { return g[a].d > g[b].d; }
 
void dfs(int node = 0, int par = -1) {
	static std::vector <int> up;
	up.push_back(node);
	if (par == -1) g[node].d = 0;
	else g[node].d = g[par].d + 1;
	for (size_t i = 0; (size_t(1) << i) < up.size(); i++)
		g[node].ban[i] = up[up.size() - (1 << i) - 1];
	for (size_t i = 0; i < g[node].nei.size(); i++) {
		if (g[node].nei[i] == par) continue;
		dfs(g[node].nei[i], node);
	}
	up.pop_back();
}
 
int lca(int u, int v) {
	if (g[u].d > g[v].d) std::swap(u, v);
	while (g[v].d - g[u].d)
		v = g[v].ban[msb(g[v].d - g[u].d) - 1];
	while (g[u].ban[0] != g[v].ban[0])
		for (int i = 18; i >= 0; i--)
			if (g[u].ban[i] != g[v].ban[i]) {
				u = g[u].ban[i], v = g[v].ban[i];
				break;
			}
	return u == v ? u : g[u].ban[0];
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].nei.push_back(v);
		g[v].nei.push_back(u);
	}
	dfs();
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		int ca = lca(u, v);
		g[ca].sub++, g[ca].subhere += (ca != u) & (ca != v),
		g[u].add += u != ca, g[v].add += (v != ca) | (u == v);
	}
	std::vector <int> order(n);
	std::iota(order.begin(), order.end(), 0);
	std::sort(order.begin(), order.end(), cmp);
	for (int x : order) {
		static std::vector <int> change(n, 0);
		g[x].ans = change[x] + g[x].add - g[x].subhere;
		change[x] += g[x].add - g[x].sub - g[x].subhere;
		change[g[x].ban[0]] += change[x];
	}
	for (int i = 0; i < n; i++) std::cout << g[i].ans << " \n"[i == n - 1];
	
}
