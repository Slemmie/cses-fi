#include <bits/stdc++.h>

int n, m, k;
std::vector <std::vector <int>> g;
std::vector <int> girl;
std::vector <std::pair <int, int>> ans;

bool f(int boy, std::vector <bool>& vis) {
	for (int i = 0; i < m; i++) {
		if (!vis[i] && g[boy][i]) {
			vis[i] = true;
			if (girl[i] < 0 || f(girl[i], vis)) {
				girl[i] = boy;
				return true;
			}
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m >> k;
	g.resize(n, std::vector <int> (m, 0));
	for (int i = 0; i < k; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u][v] = 1;
	}
	girl.resize(m, -1);
	for (int i = 0; i < n; i++) {
		std::vector <bool> vis(m, false);
		f(i, vis);
	}
	for (int i = 0; i < m; i++) {
		if (girl[i] == -1) continue;
		ans.emplace_back(girl[i] + 1, i + 1);
	}
	std::cout << ans.size() << "\n";
	for (auto p : ans) std::cout << p.first << " " << p.second << "\n";
	
}
