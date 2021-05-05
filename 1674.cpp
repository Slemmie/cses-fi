#include <bits/stdc++.h>
 
int n;
std::vector <std::vector <int>> g;
std::vector <int> ans;
 
int dfs(int node) {
	int r = 1;
	for (int x : g[node]) r += dfs(x);
	ans[node] = r - 1;
	return r;
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	g.resize(n);
	ans.resize(n, 0);
	for (int i = 1; i < n; i++) {
		int p; std::cin >> p;
		g[p - 1].push_back(i);
	}
	dfs(0);
	for (int x : ans) std::cout << x << " ";
	std::cout << "\n";
	
}
