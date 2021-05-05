#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <std::vector <std::pair <int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; std::cin >> u >> v >> w; u--, v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	std::vector <bool> vis(n, false);
	std::priority_queue <std::pair <int, int>> pq;
	pq.push({ 0, 0 });
	int cnt = 0;
	long long ans = 0;
	while (pq.size()) {
		auto now = pq.top(); pq.pop();
		int v = now.second;
		int w = -now.first;
		if (vis[v]) continue;
		vis[v] = true;
		cnt++;
		ans += (long long)w;
		for (auto p : g[v]) pq.push({ -p.second, p.first });
	}
	if (cnt == n) std::cout << ans << "\n";
	else std::cout << "IMPOSSIBLE\n";
	
}
