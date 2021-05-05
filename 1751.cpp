#include <bits/stdc++.h>

int n;
std::vector <int> nex;
std::vector <std::vector <int>> g;
std::vector <int> col;
std::vector <int> cyc;
std::vector <int> roots;

int dfs(int node, std::vector <bool>& vis, std::vector <bool>& rec) {
	if (rec[node]) {
		cyc.push_back(0);
		return node;
	}
	if (vis[node]) return -1;
	vis[node] = rec[node] = true;
	int r = dfs(nex[node], vis, rec);
	if (r != -1) {
		roots.push_back(node);
		cyc.back()++;
		col[node] = (int)cyc.size() - 1;
		if (r == node) r = -1;
	}
	return r;
}

std::vector <int> root, dep;

void dfs2(int node, int ro) {
	root[node] = ro;
	for (int x : g[node]) if (col[x] == -1) {
		dep[x] = dep[node] + 1;
		dfs2(x, ro);
	}
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	nex.resize(n);
	g.resize(n);
	root.resize(n, -1);
	dep.resize(n, 0);
	col.resize(n, -1);
	for (int i = 0; i < n; i++) {
		std::cin >> nex[i];
		nex[i]--;
		g[nex[i]].push_back(i);
	}
	std::vector <bool> vis(n, false);
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		std::vector <bool> rec(n, false);
		dfs(i, vis, rec);
	}
	std::vector <bool> proc(n, false);
	for (int x : roots) if (!proc[x]) proc[x] = true, dfs2(x, x);
	for (int i = 0; i < n; i++) {
		if (col[i] != -1) std::cout << cyc[col[i]] << " \n"[i == n - 1];
		else std::cout << dep[i] + cyc[col[root[i]]] << " \n"[i == n - 1];
	}
	
}
