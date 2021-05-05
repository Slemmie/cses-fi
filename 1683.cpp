#include <bits/stdc++.h>

int n, m;

class StronglyConnectedComponents {
	
public:
	
	int size;
	std::vector <std::vector <int>> g, h;
	std::vector <int> topo, col;
	std::vector <bool> vis;
	
	StronglyConnectedComponents(int _size) :
	size(_size),
	g(_size),
	h(_size),
	col(_size, -1),
	vis(_size, false)
	{ }
	
	inline void add(int u, int v) { g[u].push_back(v); h[v].push_back(u); }	
	inline void read_ed(int du, int dv) {
		int u, v;
		std::cin >> u >> v;
		u += du, v += dv;
		add(u, v);
	}
	
	void sort(int node) {
		vis[node] = true;
		for (int x : g[node])
			if (!vis[x])
				sort(x);
		topo.push_back(node);
	}
	
	void dfs(int node, int c) {
		col[node] = c;
		for (int x : h[node])
			if (col[x] == -1)
				dfs(x, c);
	}
	
	void init() {
		for (int i = 0; i < n; i++)
			if (!vis[i])
				sort(i);
		std::reverse(topo.begin(), topo.end());
		for (int x : topo)
			if (col[x] == -1)
				dfs(x, x);
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	StronglyConnectedComponents scc(n);
	for (int i = 0; i < m; i++)
		scc.read_ed(-1, -1);
	scc.init();
	int k = 1;
	std::vector <int> ans(n, 0);
	for (int i = 0; i < n; i++)
		if (!ans[scc.col[i]])
			ans[scc.col[i]] = k++;
	std::cout << k - 1 << "\n";
	for (int i = 0; i < n; i++)
		std::cout << ans[scc.col[i]] << " \n"[i == n - 1];
	
}
