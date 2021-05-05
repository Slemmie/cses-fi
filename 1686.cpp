#include <bits/stdc++.h>

typedef long long ll;

class StronglyConnectedComponents {
	
public:
	
	int size;
	std::vector <std::vector <int>> g, h;
	std::vector <int> topo, col;
	std::vector <bool> vis;
	
	StronglyConnectedComponents(int _size) :
	size(_size),
	g(_size),
	h(_size),
	col(_size, -1),
	vis(_size, false)
	{ }
	
	inline void add(int u, int v) { g[u].push_back(v); h[v].push_back(u); }	
	inline void read_ed(int du, int dv) {
		int u, v;
		std::cin >> u >> v;
		u += du, v += dv;
		add(u, v);
	}
	
	void sort(int node) {
		vis[node] = true;
		for (int x : g[node])
			if (!vis[x])
				sort(x);
		topo.push_back(node);
	}
	
	void dfs(int node, int c) {
		col[node] = c;
		for (int x : h[node])
			if (col[x] == -1)
				dfs(x, c);
	}
	
	void init() {
		for (int i = 0; i < size; i++)
			if (!vis[i])
				sort(i);
		std::reverse(topo.begin(), topo.end());
		for (int x : topo)
			if (col[x] == -1)
				dfs(x, x);
	}
	
};

int n, m;
std::vector <int> k;

ll dfs(int node, std::vector <std::vector <int>>& h, std::vector <ll>& K, std::vector <ll>& dp) {
	if (dp[node] != -1) return dp[node];
	ll r = 0;
	for (int x : h[node]) r = std::max(r, dfs(x, h, K, dp));
	return dp[node] = r + K[node];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	k.resize(n);
	for (int& x : k) std::cin >> x;
	StronglyConnectedComponents scc(n);
	for (int i = 0; i < m; i++) scc.read_ed(-1, -1);
	scc.init();
	std::vector <std::vector <int>> h(n);
	std::vector <ll> K(n, 0);
	for (int i = 0; i < n; i++) {
		K[scc.col[i]] += ll(k[i]);
		for (int x : scc.g[i]) if (scc.col[x] != scc.col[i]) h[scc.col[i]].push_back(scc.col[x]);
	}
	std::vector <ll> dp(n, -1);
	for (int i = 0; i < n; i++) dfs(i, h, K, dp);
	ll ans = 0;
	for (ll x : dp) ans = std::max(ans, x);
	std::cout << ans << "\n";
	
}
