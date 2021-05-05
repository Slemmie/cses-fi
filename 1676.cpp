#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <int> c(n);
	std::iota(c.begin(), c.end(), 0);
	std::vector <std::vector <int>> s(n);
	for (int i = 0; i < n; i++) s[i].push_back(i);
	int cnt = n, mx = 1;
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		if (c[u] != c[v]) {
			cnt--;
			if (s[c[u]] < s[c[v]]) {
				for (int x : s[c[u]]) {
					c[x] = c[v];
					s[c[v]].push_back(x);
				}
				mx = std::max(mx, (int)s[c[v]].size());
			} else {
				for (int x : s[c[v]]) {
					c[x] = c[u];
					s[c[u]].push_back(x);
				}
				mx = std::max(mx, (int)s[c[u]].size());
			}
		}
		std::cout << cnt << " " << mx << "\n";
	}
	
}
