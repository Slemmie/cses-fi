#include <bits/stdc++.h>

typedef long long ll;

struct P {
	
	int v;
	ll w;
	bool f;
	
	bool operator < (const P& other) const { return w < other.w; }
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <std::vector <std::pair <int, ll>>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v; ll w; std::cin >> u >> v >> w; u--, v--;
		g[u].push_back({ v, w });
	}
	std::priority_queue <P> pq;
	std::vector <std::vector <bool>> vis(2, std::vector <bool> (n, false));
	pq.push({ 0, 0, false });
	while (pq.size()) {
		P x = pq.top(); pq.pop();
		if (x.v == n - 1) {
			std::cout << -x.w << "\n";
			return 0;
		}
		if (vis[x.f][x.v]) continue;
		vis[x.f][x.v] = true;
		for (auto p : g[x.v]) {
			pq.push({ p.first, x.w - p.second, x.f });
			if (!x.f) pq.push({ p.first, x.w - (p.second >> 1LL), true });
		}
	}
	std::cerr << "...yes" << std::endl;
	
}
