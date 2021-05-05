#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

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

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	TopoSort t(n);
	for (int i = 0; i < m; i++) t.read_ed(-1, -1);
	if (!t.sort()) {
		std::cout << "0\n";
		return 0;
	}
	std::vector <ll> dp(n, 0);
	std::reverse(t.res.begin(), t.res.end());
	for (int x : t.res) {
		if (x == n - 1) dp[x] = 1;
		else {
			for (int y : t.g[x]) {
				dp[x] = (dp[x] + dp[y]) % mod;
			}
		}
	}
	std::cout << dp[0] << "\n";
	
}
