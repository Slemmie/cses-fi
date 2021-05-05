#include <bits/stdc++.h>
 
int n, m;
std::vector <std::vector <int>> g;
std::set <int> s1, s2;
 
void f(int node) {
	static std::vector <bool> vis(n, false);
	if (s1.count(node) & s2.count(node)) {
		std::cout << "IMPOSSIBLE\n";
		exit(0);
	}
	if (vis[node]) return;
	vis[node] = true;
	if (s1.count(node)) {
		for (int x : g[node]) {
			s2.insert(x);
		}
		for (int x : g[node]) {
			f(x);
		}
	} else {
		for (int x : g[node]) {
			s1.insert(x);
		}
		for (int x : g[node]) {
			f(x);
		}
	}
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (!s1.count(i) & !s2.count(i)) f(i);
	}
	for (int i = 0; i < n; i++) {
		std::cout << (s1.count(i) ? 1 : 2) << " ";
	}
	std::cout << "\n";
	
}
