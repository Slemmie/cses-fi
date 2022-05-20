#include <bits/stdc++.h>

int n, m;
std::vector <std::vector <int>> g;
std::vector <bool> vis;

std::set <std::pair <int, int>> st;
std::vector <std::pair <int, int>> ans;
std::vector <bool> ok;
std::vector <int> dep;

int dfs(int node, int par, int d = 0) {
	vis[node] = true;
	dep[node] = d++;
	int ret = 1 << 30;
	for (int x : g[node]) {
		if (x == par) {
			continue;
		}
		if (st.count({ node, x })) {
			continue;
		}
		st.insert({ node, x });
		st.insert({ x, node });
		ans.emplace_back(node, x);
		if (!vis[x]) {
			ret = std::min(ret, dfs(x, node, d));
		} else {
			ret = std::min(ret, dep[x]);
		}
	}
	if (ret < dep[node] || !node) {
		ok[node] = true;
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vis.resize(n, false);
	ok.resize(n, false);
	dep.resize(n, -1);
	dfs(0, -1);
	int oks = 0;
	for (bool b : ok) {
		oks += b;
	}
	if (oks != n) {
		std::cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (auto p : ans) {
		std::cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
	
}
