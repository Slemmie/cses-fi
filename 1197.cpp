#include <bits/stdc++.h>

typedef long long ll;

const ll inf = 1LL << 60LL;

int n, m;

struct Edge {
	
	int u, v;
	ll w;
	
};

std::vector <Edge> ed;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	ed.resize(m);
	for (int i = 0; i < m; i++) {
		std::cin >> ed[i].u >> ed[i].v >> ed[i].w, ed[i].u--, ed[i].v--;
		if (ed[i].u == ed[i].v && ed[i].w < 0LL) {
			std::cout << "YES\n";
			std::cout << ed[i].u + 1 << " " << ed[i].u + 1 << "\n";
			return 0;
		}
	}
	std::vector <ll> dist(n, 0);
	std::vector <int> par(n, -1);
	for (int i = 0; i < n; i++) {
		for (const Edge& e : ed) {
			if (dist[e.v] > dist[e.u] + e.w) {
				par[e.v] = e.u;
				dist[e.v] = dist[e.u] + e.w;
			}
		}
	}
	for (const Edge& e : ed) {
		if (dist[e.v] > dist[e.u] + e.w) {
			std::cout << "YES\n";
			std::vector <bool> vis(n, false);
			std::vector <int> ans;
			int v = e.v;
			while (!vis[v]) {
				vis[v] = true;
				ans.push_back(v);
				v = par[v];
			}
			ans.push_back(v);
			std::reverse(ans.begin(), ans.end());
			while (ans.front() != ans.back()) ans.pop_back();
			for (int x : ans) std::cout << x + 1 << " ";
			std::cout << "\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	
}
