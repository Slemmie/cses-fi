#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, m; std::cin >> n >> m;
	std::vector <std::vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	auto bfs = [&] (int source) -> int {
		std::vector <bool> vis(n, false);
		std::queue <int> q;
		std::vector <int> dist(n);
		dist[source] = 0;
		vis[source] = true;
		q.push(source);
		int ans = 1 << 30;
		while (q.size()) {
			int v = q.front();
			q.pop();
			for (int x : g[v]) {
				if (!vis[x]) {
					vis[x] = true;
					dist[x] = dist[v] + 1;
					q.push(x);
				} else if (dist[x] >= dist[v]) {
					ans = std::min(ans, dist[x] + dist[v] + 1);
				}
			}
		}
		return ans;
	};
	int ans = 1 << 30;
	for (int i = 0; i < n; i++) {
		ans = std::min(ans, bfs(i));
	}
	std::cout << (ans == 1 << 30 ? -1 : ans) << "\n";
}
