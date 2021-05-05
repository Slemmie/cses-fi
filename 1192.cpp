#include <bits/stdc++.h>
 
int n, m;
std::vector <std::string> g;
 
void dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '#') return;
	g[i][j] = '#';
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	for (auto& x : g) std::cin >> x;
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (g[i][j] == '.') ans++, dfs(i, j);
	std::cout << ans << "\n";
	
}
