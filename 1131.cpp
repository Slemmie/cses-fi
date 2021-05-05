#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::vector <int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	std::queue <int> q;
	std::vector <int> ans(n, 0), cnt(n, 0);
	for (int i = 0; i < n; i++) {
		cnt[i] = g[i].size();
		if (cnt[i] < 2) q.push(i), ans[i] = 1;
	}
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int x : g[now]) if (!(--cnt[x] - 1)) q.push(x), ans[x] = ans[now] + 1;
	}
	int mx = *std::max_element(ans.begin(), ans.end()) - 1;
	int mxx = 0;
	for (int x : ans) mxx += x == mx + 1;
	std::cout << (mxx >= 2) + mx * 2 << "\n";
	
}
