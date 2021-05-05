#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <std::vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	std::vector <int> par(n, -1);
	std::vector <bool> vis(n, false);
	std::priority_queue <std::pair <int, std::pair <int, int>>> pq;
	pq.push({ 0, { 0, 0 } });
	while (pq.size()) {
		auto now = pq.top(); pq.pop();
		if (vis[now.second.first]) continue;
		vis[now.second.first] = true;
		par[now.second.first] = now.second.second;
		if (now.second.first == n - 1) {
			std::cout << -now.first + 1 << "\n";
			int cur = now.second.first;
			std::vector <int> ans;
			while (cur) {
				ans.push_back(cur + 1);
				cur = par[cur];
			}
			std::reverse(ans.begin(), ans.end());
			std::cout << "1";
			for (int x : ans) std::cout << " " << x;
			std::cout << "\n";
			return 0;
		}
		for (int x : g[now.second.first]) pq.push({ now.first - 1, { x, now.second.first } });
	}
	std::cout << "IMPOSSIBLE\n";
	
}
