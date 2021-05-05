#include <bits/stdc++.h>

typedef long long ll;

int n, m;
std::vector <std::vector <std::pair <int, ll>>> g;
std::vector <ll> cnt, mn, mx, dist;
ll ans = 1LL << 60LL;

void go() {
	dist[0] = 0;
	std::priority_queue <std::pair <ll, int>> pq;
	pq.push({ 0, 0 });
	while (pq.size()) {
		auto now = pq.top(); pq.pop();
		int v = now.second;
		ll w = -now.first;
		if (dist[v] != w) continue;
		for (auto p : g[v]) {
			if (dist[p.first] > w + p.second) {
				dist[p.first] = w + p.second;
				pq.push({ -dist[p.first], p.first });
			}
		}
	}
}

bool cmp(int x, int y) {
	return dist[x] < dist[y];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	cnt.resize(n);
	mn.resize(n);
	mx.resize(n);
	dist.resize(n, 1LL << 60LL);
	for (int i = 0; i < m; i++) {
		int u, v, w; std::cin >> u >> v >> w; u--, v--;
		g[u].push_back({ v, w });
	}
	go();
	std::vector <int> order(n);
	std::iota(order.begin(), order.end(), 0);
	std::sort(order.rbegin(), order.rend(), cmp);
	cnt[n - 1] = 1;
	for (int v : order) if (v != n - 1) {
		mx[v] = -(1LL << 60LL);
		mn[v] = -mx[v];
		for (auto p : g[v]) if (dist[v] + p.second == dist[p.first]) {
			cnt[v] = (cnt[v] + cnt[p.first]) % ll(1e9 + 7);
			mx[v] = std::max(mx[v], mx[p.first] + 1LL);
			mn[v] = std::min(mn[v], mn[p.first] + 1LL);
		}
	}
	std::cout << dist[n - 1] << " " << cnt[0] << " " << mn[0] << " " << mx[0] << "\n";
	
}
