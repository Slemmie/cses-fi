#include <bits/stdc++.h>

int n, m;
std::vector <std::vector <int>> g;

std::vector <int> get_path(int s, int t) {
	std::queue <std::pair <int, int>> q;
	std::vector <int> par(n, -1);
	q.emplace(s, s);
	while (q.size()) {
		auto [u, p] = q.front(); q.pop();
		if (par[u] != -1) continue;
		par[u] = p;
		if (u == t) {
			std::vector <int> path;
			while (u != s) {
				path.push_back(u);
				u = par[u];
			}
			path.push_back(s);
			std::reverse(path.begin(), path.end());
			return path;
		}
		for (int x : g[u]) {
			q.emplace(x, u);
		}
	}
	return { };
}

std::vector <bool> vis, onp, reach;
int rc = 0;

void dfs(int node) {
	if (onp[node]) {
		rc += !reach[node];
		reach[node] = true;
	}
	if (vis[node]) return;
	vis[node] = true;
	for (int x : g[node]) dfs(x);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v;
		g[--u].push_back(--v);
	}
	auto path = get_path(0, n - 1);
	assert(path.size());
	vis.resize(n, false);
	onp = reach = vis;
	for (int x : path) vis[x] = onp[x] = true;
	std::vector <int> ans;
	for (int x : path) {
		rc -= reach[x];
		reach[x] = false;
		onp[x] = false;
		if (!rc) ans.push_back(x);
		for (int y : g[x]) dfs(y);
	}
	std::sort(ans.begin(), ans.end());
	std::cout << ans.size() << "\n";
	for (int x : ans) std::cout << x + 1 << " ";
	std::cout << "\n";
}
