#include <bits/stdc++.h>

class StronglyConnectedComponents {
	
public:
	
	int size;
	std::vector <std::vector <int>> g, h;
	std::vector <int> topo, col;
	std::vector <bool> vis;
	std::vector <int> cols;
	
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
		for (int i = 0; i < size; i++)
			if (!vis[i])
				sort(i);
		std::reverse(topo.begin(), topo.end());
		for (int x : topo)
			if (col[x] == -1)
				dfs(x, x), cols.push_back(x);
	}
	
};

struct twosat {
	
	int size;
	StronglyConnectedComponents* scc = nullptr;
	
	twosat(int s) {
		size = s;
		scc = new StronglyConnectedComponents(s + s);
	}
	
	~twosat() {
		delete(scc);
	}
	
	void add(int u, int v) {
		scc->add(u ^ 1, v);
		scc->add(v ^ 1, u);
	}
	
	std::vector <int> vis;
	std::vector <bool> ans;
	
	bool init() {
		vis.resize(size + size, 0);
		ans.resize(size, false);
		scc->init();
		for (int i = 0; i < size + size; i += 2)
			if (scc->col[i] == scc->col[i ^ 1])
				return false;
		std::reverse(scc->cols.begin(), scc->cols.end());
		for (int x : scc->cols)
			if (!vis[x])
				vis[x] = 1,
				vis[scc->col[x ^ 1]] = 2;
		for (int i = 0; i < size; i++)
			if (vis[scc->col[i << 1]] == 1)
				ans[i] = true;
		return true;
	}
	
};


int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	twosat* ts = new twosat(m);
	for (int i = 0; i < n; i++) {
		std::pair <char, int> a, b;
		std::cin >> a.first >> a.second >> b.first >> b.second; a.second--, b.second--;
		ts->add((a.second << 1) + (a.first == '-'), (b.second << 1) + (b.first == '-'));
	}
	if (!ts->init()) {
		std::cout << "IMPOSSIBLE\n";
	} else {
		for (int i = 0; i < m; i++) {
			if (ts->ans[i]) std::cout << "+ ";
			else std::cout << "- ";
		}
		std::cout << "\n";
	}
	delete(ts);
	
}
