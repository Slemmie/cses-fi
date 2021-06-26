#include <bits/stdc++.h>

int n;
int ind = 0;
std::map <std::vector <int>, int> mp;

int dfs(int node, int par, const std::vector <std::vector <int>>& g) {
	std::vector <int> now;
	for (int x : g[node]) if (x != par) {
		now.push_back(dfs(x, node, g));
	}
	std::sort(now.begin(), now.end());
	if (!mp.count(now)) mp[now] = ind++;
	return mp[now];
}

std::vector <int> sub;
std::vector <int> cen(int node, int par, const std::vector <std::vector <int>>& g) {
	std::vector <int> r;
	int big = 0;
	sub[node] = 1;
	for (int x : g[node]) if (x != par) {
		auto now = cen(x, node, g);
		for (int y : now) r.push_back(y);
		big = std::max(big, sub[x]);
		sub[node] += sub[x];
	}
	if (big <= (n >> 1) && n - sub[node] <= (n >> 1)) r.push_back(node);
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		ind = 0;
		mp.clear();
		std::cin >> n;
		std::vector <std::vector <int>> g(n), h(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; std::cin >> u >> v; u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v; std::cin >> u >> v; u--, v--;
			h[u].push_back(v);
			h[v].push_back(u);
		}
		sub.clear(); sub.resize(n, 0);
		auto cg = cen(0, -1, g);
		sub.clear(); sub.resize(n, 0);
		auto ch = cen(0, -1, h);
		int target = dfs(cg[0], -1, g);
		bool no = true;
		for (int c : ch) {
			if (dfs(c, -1, h) == target) {
				std::cout << "YES\n";
				no = false;
				break;
			}
		}
		if (no) std::cout << "NO\n";
	}
	
}
