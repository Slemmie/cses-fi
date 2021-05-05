#include <bits/stdc++.h>

class TopoSort {
	
public:
	
	int size;
	bool good;
	std::vector <int> res, in;
	std::vector <std::vector <int>> g;
	
	TopoSort(int _size) : size(_size), good(false), in(_size, 0), g(_size) { }
	
	inline void add(int u, int v) { in[v]++; g[u].push_back(v); }
	
	inline void read_ed(int du = 0, int dv = 0) {
		int u, v;
		std::cin >> u >> v;
		u += du, v += dv;
		g[u].push_back(v);
		in[v]++;
	}
	
	bool sort() {
		if (!res.empty())
			res.clear();
		std::queue <int> q;
		for (int i = 0; i < size; i++)
			if (!in[i])
				q.push(i);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			res.push_back(v);
			for (int x : g[v]) {
				in[x]--;
				if (!in[x])
					q.push(x);
			}
		}
		return good = (int)res.size() == size;
	}
	
};

const int inf = 1 << 30;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	TopoSort ts(n);
	for (int i = 0; i < m; i++) ts.read_ed(-1, -1);
	if (!ts.sort()) {
		std::cout << "IMPOSSIBLE\n";
		return 0;
	}
	std::reverse(ts.res.begin(), ts.res.end());
	std::vector <int> dp(n, 0);
	for (int x : ts.res) {
		if (x == n - 1) dp[x] = 1;
		else {
			dp[x] = -inf;
			for (int y : ts.g[x])
				if (dp[y] != -inf)
					dp[x] = std::max(dp[x], dp[y] + 1);
		}
	}
	if (dp[0] == -inf) {
		std::cout << "IMPOSSIBLE\n";
		return 0;
	}
	std::cout << dp[0] << "\n";
	std::vector <int> ans = { 0 };
	while (ans.back() != n - 1) {
		for (int x : ts.g[ans.back()]) {
			if (dp[ans.back()] == dp[x] + 1) {
				ans.push_back(x);
				break;
			}
		}
	}
	for (int x : ans) std::cout << x + 1 << " ";
	std::cout << "\n";
	
}
