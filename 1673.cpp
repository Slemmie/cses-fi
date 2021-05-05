#include <bits/stdc++.h>

typedef long long ll;

int n, m;
std::vector <std::vector <std::pair <int, ll>>> g;

bool n1() {
	std::cout << "-1\n";
	exit(0);
}

const ll inf = 1LL << 60LL;

std::vector <ll> vis;
std::vector <ll> dp;

std::vector <bool> can;

ll dfs(int node, ll sof = 0) {
	if (dp[node] != -inf) return dp[node];
	if (vis[node] != -inf) {
		if (vis[node] < sof && can[node]) n1();
		else return -inf;
	}
	vis[node] = sof;
	ll r = -inf;
	for (auto p : g[node]) {
		r = std::max(r, dfs(p.first, sof + p.second) + p.second);
	}
	vis[node] = -inf;
	if (node == n - 1) return 0;
	dp[node] = r;
	return r;
}

void prep(const std::vector <std::vector <int>>& rv) {
	std::queue <int> q;
	std::vector <bool> vi(n, false);
	q.push(n - 1);
	while (q.size()) {
		int v = q.front(); q.pop();
		if (vi[v]) continue;
		vi[v] = true;
		can[v] = true;
		for (int x : rv[v]) q.push(x);
	}
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	vis.resize(n, -inf);
	dp.resize(n, -inf);
	std::vector <std::vector <int>> rv(n);
	can.resize(n, false);
	std::vector <std::vector <ll>> am(n, std::vector <ll> (n, -inf));
	for (int i = 0; i < m; i++) {
		int u, v, w; std::cin >> u >> v >> w; u--, v--;
		am[u][v] = std::max(am[u][v], (ll)w);
		rv[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (am[i][j] != -inf)
				g[i].push_back({ j, am[i][j] });
	prep(rv);
	std::cout << dfs(0) << "\n";
	
}
