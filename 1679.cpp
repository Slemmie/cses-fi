#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <std::vector <int>> g(n);
	std::vector <int> cnt(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		cnt[v]++;
	}
	std::queue <int> q;
	for (int i = 0; i < n; i++)
		if (!cnt[i])
			q.push(i);
	std::vector <int> ans;
	while (q.size()) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		if ((int)ans.size() == n) {
			for (int x : ans) std::cout << x + 1 << " ";
			std::cout << "\n";
			return 0;
		}
		for (int x : g[v]) {
			cnt[x]--;
			if (!cnt[x]) q.push(x);
		}
	}
	std::cout << "IMPOSSIBLE\n";
	
}
