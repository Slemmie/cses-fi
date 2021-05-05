#include <bits/stdc++.h>
 
int n;
std::vector <std::vector <int>> g;
std::vector <int> ans;
 
void dfs(int node = 0, int par = -1) {
	for (int x : g[node]) if (x != par) {
		dfs(x, node);
		ans[node] &= !ans[x];
	}
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	g.resize(n);
	ans.resize(n, true);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs();
	int put = 0;
	for (int x : ans) put += !x;
	std::cout << put << "\n";
	
}
