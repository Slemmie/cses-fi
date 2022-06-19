#include <bits/stdc++.h>

struct Dsu {
	
	std::vector <int> p;
	std::vector <int> s;
	
	Dsu(int size) {
		p.resize(size);
		std::iota(p.begin(), p.end(), 0);
		s.resize(size, 1);
	}
	
	int find(int x) {
		return x == p[x] ? x : (p[x] = find(p[x]));
	}
	
	void unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (s[u] < s[v]) {
			std::swap(u, v);
		}
		s[u] += s[v];
		p[v] = u;
	}
	
	int size(int x) {
		return s[find(x)];
	}
	
};

int n, m, q;
std::vector <int> ans;
std::vector <std::vector <std::pair <int, int>>> g;
std::vector <int> par;
std::vector <int> dep;
std::vector <int> pav;

void dfs(int node, int pa = -1, int d = 0) {
	par[node] = pa;
	dep[node] = d++;
	for (auto x : g[node]) {
		if (x.first != pa) {
			dfs(x.first, node, d);
			pav[x.first] = x.second;
		}
	}
}

int query(int u, int v) {
	int res = 0;
	while (u != v) {
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		res = std::max(res, pav[u]);
		u = par[u];
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m >> q;
	ans.resize(q, -1);
	dep.resize(n, 0);
	par.resize(n, -1);
	pav.resize(n, -1);
	g.resize(n);
	Dsu dsu(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		if (dsu.find(u) == dsu.find(v)) {
			continue;
		}
		g[dsu.find(u)].emplace_back(dsu.find(v), i + 1);
		g[dsu.find(v)].emplace_back(dsu.find(u), i + 1);
		dsu.unite(u, v);
	}
	std::vector <int> root(n);
	for (int i = 0; i < n; i++) {
		root[i] = dsu.find(i);
		if (root[i] == i) {
			dfs(i);
		}
	}
	for (int i = 0; i < q; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		if (dsu.find(u) != dsu.find(v)) {
			std::cout << "-1\n";
			continue;
		}
		std::cout << query(u, v) << "\n";
	}
	
}
