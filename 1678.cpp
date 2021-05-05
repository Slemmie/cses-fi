#include <bits/stdc++.h>

int pop(std::vector <int>& v) { int r = v.back(); v.pop_back(); return r; }

int n, m;
std::vector <std::vector <int>> g;
std::vector <bool> vis, rvis;

std::vector <int> cur;
void dfs(int node) {
	vis[node] = rvis[node] = true;
	cur.push_back(node);
	for (int x : g[node]) {
		if (!vis[x]) dfs(x);
		else if (rvis[x]) {
			std::vector <int> now;
			while (cur.back() != x)
				now.push_back(pop(cur));
			now.push_back(x);
			now.push_back(node);
			std::cout << now.size() << "\n";
			for (int i = (int)now.size() - 1; i >= 0; i--)
				std::cout << now[i] + 1 << " \n"[!i];
			exit(0);
		}
	}
	rvis[node] = false;
	cur.pop_back();
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	vis.resize(n, false);
	rvis.resize(n, false);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
	std::cout << "IMPOSSIBLE\n";
	
}
