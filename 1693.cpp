#include <bits/stdc++.h>

int n, m;
std::vector <std::vector <int>> g;

std::vector <int> ans;

int cnt = 0;

void dfs(int node) {
	while (g[node].size()) {
		int to = g[node].back();
		g[node].pop_back();
		cnt++;
		dfs(to);
	}
	ans.push_back(node);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	std::vector <int> in(n, 0), out(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		in[v]++;
		out[u]++;
	}
	if (out[0] != in[0] + 1 || in[n - 1] != out[n - 1] + 1) {
		std::cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int i = 1; i < n - 1; i++) {
		if (in[i] != out[i]) {
			std::cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	dfs(0);
	if (cnt != m) {
		std::cout << "IMPOSSIBLE\n";
		return 0;
	}
	std::reverse(ans.begin(), ans.end());
	for (int x : ans) std::cout << x + 1 << " ";
	std::cout << "\n";
	
}
