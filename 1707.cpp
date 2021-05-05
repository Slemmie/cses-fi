#include <bits/stdc++.h>
 
int n, m;
std::vector <std::vector <int>> gr, g;
 
std::vector <std::vector <int>> bin;
 
std::vector <int> dep;
 
std::vector <int> cur;
void dfs1(int node, int d = 1) {
	dep[node] = d++;
	for (int i = 0; i < 20; i++) {
		int bit = 1 << i;
		if (bit > (int)cur.size()) break;
		bin[node][i] = cur[(int)cur.size() - 1 - (bit - 1)];
	}
	cur.push_back(node);
	for (int x : g[node]) dfs1(x, d);
	cur.pop_back();
}
 
int lca(int u, int v) {
	if (dep[v] > dep[u]) std::swap(u, v);
	while (dep[u] > dep[v]) {
		for (int i = 0; i < 20; i++) {
			if ((1 << i) > dep[u] - dep[v]) {
				i--;
				u = bin[u][i];
				break;
			}
		}
	}
	while (u != v) {
		if (bin[u][0] == bin[v][0]) { u = bin[u][0], v = bin[v][0]; break; }
		for (int i = 0; i < 20; i++) {
			if (bin[u][i] == bin[v][i]) {
				i--;
				u = bin[u][i];
				v = bin[v][i];
				break;
			}
		}
		if (bin[u][0] == bin[v][0]) u = bin[u][0], v = bin[v][0];
	}
	return u;
}
 
int val(int u, int v) {
	return dep[u] + dep[v] + 1 - 2 * dep[lca(u, v)];
}
 
int ans = 1 << 30;
 
void dfs2(int node) {
	for (int x : gr[node]) if ((dep[x] < dep[node] && bin[node][0] != x) || (dep[x] == dep[node] && x != node))
		ans = std::min(ans, val(node, x));
	for (int x : g[node]) dfs2(x);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	gr.resize(n);
	g.resize(n);
	dep.resize(n);
	bin.resize(n, std::vector <int> (20, -1));
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	std::vector <int> roots = { 0 };
	std::vector <bool> vis(n, false);
	std::queue <int> q;
	q.push(0);
	vis[0] = true;
	int ptr = 0;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int x : gr[now]) if (!vis[x]) g[now].push_back(x), q.push(x), vis[x] = true;
		if (q.empty()) {
			while (ptr < n && vis[ptr]) ptr++;
			if (ptr < n) q.push(ptr), roots.push_back(ptr), vis[ptr] = true;
		}
	}
	for (int x : roots) dfs1(x);
	for (int x : roots) dfs2(x);
	std::cout << (ans == (1 << 30) ? -1 : ans) << "\n";
	
}
