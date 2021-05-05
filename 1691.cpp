#include <bits/stdc++.h>

struct Edge {
	int u, v;
	bool alive = true;
};

std::vector <Edge> ed;

int n, m;
std::vector <std::vector <int>> g;

std::vector <int> stck;
std::vector <int> ans;
void dfs(int node) {
	stck.push_back(node);
	while (g[node].size()) {
		int v = node ^ ed[g[node].back()].u ^ ed[g[node].back()].v;
		if (ed[g[node].back()].alive) {
			ed[g[node].back()].alive = false;
			g[node].pop_back();
			dfs(v);
		} else g[node].pop_back();
	}	
	ans.push_back(node);
	stck.pop_back();
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	std::vector <int> deg(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(ed.size());
		g[v].push_back(ed.size());
		ed.push_back({ u, v });
		deg[u]++;
		deg[v]++;
	}
	for (int x : deg) {
		if (x & 1) {
			std::cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	dfs(0);
	for (auto e : ed) if (e.alive) {
		std::cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int x : ans) std::cout << x + 1 << " ";
	std::cout << "\n";
	
}
