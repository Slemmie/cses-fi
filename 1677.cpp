#include <bits/stdc++.h>

struct Dsu {
	std::vector <int> p;
	Dsu(int s) {
		p.resize(s);
		std::iota(p.begin(), p.end(), 0);
	}
	int find(int v) {
		return v == p[v] ? v : (p[v] = find(p[v]));
	}
	void unite(int u, int v) {
		u = find(u), v = find(v);
		p[v] = u;
	}
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m, k; std::cin >> n >> m >> k;
	std::set <std::pair <int, int>> st;
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		if (u > v) {
			std::swap(u, v);
		}
		st.insert({ u, v });
	}
	std::vector <std::pair <int, int>> q(k);
	for (auto& p : q) {
		std::cin >> p.first >> p.second; p.first--, p.second--;
		if (p.first > p.second) {
			std::swap(p.first, p.second);
		}
		st.erase(p);
	}
	Dsu dsu(n);
	int ans = n;
	for (auto p : st) {
		if (dsu.find(p.first) != dsu.find(p.second)) {
			ans--;
		}
		dsu.unite(p.first, p.second);
	}
	std::vector <int> res;
	res.push_back(ans);
	for (int i = (int) q.size() - 1; i; i--) {
		if (dsu.find(q[i].first) != dsu.find(q[i].second)) {
			ans--;
		}
		dsu.unite(q[i].first, q[i].second);
		res.push_back(ans);
	}
	std::reverse(res.begin(), res.end());
	for (int x : res) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	
}
