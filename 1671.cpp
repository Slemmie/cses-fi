#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <std::vector <std::pair <int, ll>>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w; std::cin >> u >> v >> w; u--, v--;
		g[u].push_back({ v, w });
	}
	std::priority_queue <std::pair <ll, int>> pq;
	pq.push({ 0, 0 });
	std::vector <ll> ans(n, -1);
	while (pq.size()) {
		auto now = pq.top(); pq.pop();
		int v = now.second;
		ll w = -now.first;
		if (ans[v] != -1LL) continue;
		ans[v] = w;
		for (auto p : g[v]) pq.push({ -w - p.second, p.first });
	}
	for (ll x : ans) std::cout << x << " ";
	std::cout << "\n";
	
}
