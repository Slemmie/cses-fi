#include <bits/stdc++.h>

int n;
std::vector <int> a;
std::vector <std::vector <int>> g;
std::vector <int> ans;

std::set <int> dfs(int node, int par = -1) {
	std::set <int> st = { a[node] };
	for (int x : g[node]) {
		if (x == par) {
			continue;
		}
		auto ch = dfs(x, node);
		if (ch.size() > st.size()) {
			std::swap(st, ch);
		}
		for (int y : ch) {
			st.insert(y);
		}
	}
	ans[node] = st.size();
	return st;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::cin >> n;
	a.resize(n);
	for (int& x : a) {
		std::cin >> x;
	}
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v;
		u--, v--;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	ans.resize(n);
	dfs(0);
	for (int x : ans) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}
