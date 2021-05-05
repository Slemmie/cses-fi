#include <bits/stdc++.h>
 
struct Path {
	int val, ch;
	Path() : val(0), ch(-1) { }
	Path(int VAL, int CH) : val(VAL), ch(CH) { }
};
 
void add(std::pair <Path, Path>& p, Path nw) {
	if (nw.val > p.second.val) {
		p.second = nw;
		if (p.second.val > p.first.val) std::swap(p.first, p.second);
	}
}
 
int n;
std::vector <std::vector <int>> g;
std::vector <std::pair <Path, Path>> p;
std::vector <int> par;
std::vector <std::vector <int>> process;
 
int dfs(int node = 0, int pa = -1, int d = 0) {
	static std::vector <bool> vis(n, false);
	if (vis[node]) return -1e6;
	vis[node] = true;
	par[node] = pa;
	process[d].push_back(node);
	for (int x : g[node]) {
		int now = dfs(x, node, d + 1);
		add(p[node], Path(now, x));
	}
	return p[node].first.val + 1;
}
 
std::vector <int> maxup;
int bestof(int node) {
	if (!node) {
		maxup[node] = 0;
		return p[node].first.val;
	}
	int upofup = 1 + maxup[par[node]];
	int downofup = 1 + (p[par[node]].first.ch == node ? p[par[node]].second.val : p[par[node]].first.val);
	maxup[node] = std::max(upofup, downofup);
	return std::max(p[node].first.val, std::max(upofup, downofup));
}
 
int main() {
	
	std::cin >> n;
	g.resize(n); p.resize(n); par.resize(n); maxup.resize(n); process.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	dfs();
	std::vector <int> ans(n);
	for (const auto& v : process) {
		for (int x : v) {
			ans[x] = bestof(x);
		}
	}
	for (int x : ans) std::cout << x << " ";
	std::cout << "\n";
	
}
