#include <bits/stdc++.h>

typedef long long ll;

int n, k1, k2, mxd;
ll mul = -1, ans = 0;
std::vector <std::vector <int>> g;

int pref(const std::deque <int>& a, int max) {
	if (max < 0) return 0;
	if (max + 1 >= (int)a.size()) return a[0];
	return a[0] - a[max + 1];
}

void merge(std::deque <int>& a, std::deque <int>& b) {
	if (a.size() < b.size()) std::swap(a, b);
	for (int i = 0; i < (int)b.size() - 1; i++) b[i] -= b[i + 1];
	for (int i = 0; i < (int)b.size(); i++) ans += (ll)b[i] * (pref(a, k2 - i) - pref(a, k1 - 1 - i));
	for (int i = (int)b.size() - 2; i >= 0; i--) b[i] += b[i + 1];
	for (int i = 0; i < (int)b.size(); i++) a[i] += b[i];
}

std::deque <int> dfs(int node = 0, int par = -1) {
	std::deque <int> r = { 1 };
	for (int x : g[node]) if (x != par) {
		auto a = dfs(x, node);
		a.push_front(a.front());
		merge(r, a);
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> k1 >> k2;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	mxd = k1 - 1;
	dfs();
	std::cout << ans << "\n";
	
}
