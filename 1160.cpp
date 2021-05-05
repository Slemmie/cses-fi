#include <bits/stdc++.h>

int n, q;
std::vector <std::vector <int>> g;
std::vector <int> nex;

std::vector <std::vector <int>> cyc;
std::vector <int> roots;
std::vector <int> col;
std::vector <int> pos;

int dfs(int node, std::vector <bool>& vis, std::vector <bool>& rec) {
	if (rec[node]) {
		cyc.resize(cyc.size() + 1);
		return node;
	}
	if (vis[node]) return -1;
	vis[node] = true;
	rec[node] = true;
	int r = dfs(nex[node], vis, rec);
	if (r != -1) {
		roots.push_back(node);
		cyc.back().push_back(node);
		col[node] = (int)cyc.size() - 1;
		if (node == r) r = -1;
	}
	return r;
}

std::vector <int> dep;
std::vector <int> root;
std::vector <std::vector <int>> ind;

void dfs2(int node, int ro) {
	static std::vector <bool> vis(n, false);
	if (vis[node]) return;
	vis[node] = true;
	static int cnt = 0;
	ind[0][node] = cnt++;
	root[node] = ro;
	for (int x : g[node]) if (col[x] == -1) {
		dep[x] = dep[node] + 1;
		dfs2(x, ro);
	}
	ind[1][node] = cnt;
}

int get(int u, int v) {
	if (col[root[u]] != col[root[v]]) return -1;
	if (root[v] != v && root[v] != root[u]) return -1;
	if (root[u] == root[v]) {
		if (ind[0][u] >= ind[0][v] && ind[0][u] < ind[1][v]) return dep[u] - dep[v];
		return -1;
	}
	int r = dep[u];
	u = root[u];
	if (pos[v] >= pos[u]) return pos[v] - pos[u] + r;
	r += (int)cyc[col[u]].size() - 1 - pos[u];
	return r + 1 + pos[v];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> q;
	g.resize(n);
	nex.resize(n);
	col.resize(n, -1);
	dep.resize(n, 0);
	root.resize(n, -1);
	ind.resize(2, std::vector <int> (n, -1));
	pos.resize(n, 1 << 30);
	for (int i = 0; i < n; i++) {
		int v; std::cin >> v; v--;
		nex[i] = v;
		g[v].push_back(i);
	}
	std::vector <bool> vis(n, false);
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		std::vector <bool> rec(n, false);
		size_t sz = cyc.size();
		dfs(i, vis, rec);
		if (sz != cyc.size()) std::reverse(cyc.back().begin(), cyc.back().end());
		if (sz != cyc.size()) for (int j = 0; j < (int)cyc.back().size(); j++) pos[cyc.back()[j]] = j;
	}
	for (int x : roots) dfs2(x, x);
	while (q--) {
		int u, v; std::cin >> u >> v; u--, v--;
		std::cout << get(u, v) << "\n";
	}
	
}
