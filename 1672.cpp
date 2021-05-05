#include <bits/stdc++.h>

typedef long long ll;

const ll inf = 1LL << 62LL;

struct Edge {
	int u, v;
	ll w;
};

int n, m, q;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m >> q;
	std::vector <Edge> e;
	for (int i = 0; i < m; i++) {
		int u, v, w; std::cin >> u >> v >> w; u--, v--;
		e.push_back({ u, v, w });
		e.push_back({ v, u, w });
	}
	std::vector <std::vector <ll>> dist(n, std::vector <ll> (n, inf));
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	for (Edge ed : e) dist[ed.u][ed.v] = std::min(dist[ed.u][ed.v], ed.w);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist[i][k] != inf && dist[k][j] != inf)
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (dist[i][j] == inf)
				dist[i][j] = -1;
	while (q--) {
		int u, v; std::cin >> u >> v; u--, v--;
		std::cout << dist[u][v] << "\n";
	}
	
}
