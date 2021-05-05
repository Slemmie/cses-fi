#include <bits/stdc++.h>

struct Edge {
	
	int u, v;
	
	bool heavy;
	
};

std::vector <Edge> e;

struct Node {
	
	int val;
	
	int col;
	
	int sub = 1, dep = -1;
	
	int par = -1;
	
	bool par_heav = false;
	
	std::vector <int> e;
	
};

std::vector <Node> g;

struct Seg {
	
	int size;
	
	std::vector <int> v;
	
	void init(int _size) {
		size = 1;
		while (size < _size) size <<= 1;
		v.resize(size << 1, 0);
	}
	
	void set(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) set(ind, val, now * 2 + 1, l, mid);
		else set(ind, val, now * 2 + 2, mid, r);
		v[now] = std::max(v[now * 2 + 1], v[now * 2 + 2]);
	}
	
	void set(int ind, int val) {
		set(ind, val, 0, 0, size);
	}
	
	int get(int tl, int tr, int now, int l, int r) {
		if (r <= tl || l >= tr) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return std::max(get(tl, tr, now * 2 + 1, l, mid), get(tl, tr, now * 2 + 2, mid, r));
	}
	
	int get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
};

struct HP {
	
	std::vector <int> v;
	
	Seg seg;
	
	void init() {
		seg.init(v.size());
		for (size_t i = 0; i < v.size(); i++)
			seg.set(g[v[i]].dep - g[v[0]].dep, g[v[i]].val);
	}
	
};

std::vector <HP> hp;

void dfs(int node = 0, int par = 0) {
	g[node].dep = g[par].dep + 1;
	if (node) g[node].par = par;
	for (int x : g[node].e) {
		int v = node ^ e[x].u ^ e[x].v;
		if (v == par) continue;
		dfs(v, node);
		g[node].sub += g[v].sub;
	}			
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	e.resize(n - 1);
	g.resize(n);
	for (auto& x : g) std::cin >> x.val;
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].e.push_back(i);
		g[v].e.push_back(i);
		e[i].u = u;
		e[i].v = v;
	}
	dfs();
	std::vector <bool> start(n, true);
	for (auto& ed : e) {
		if (g[ed.u].dep > g[ed.v].dep) std::swap(ed.u, ed.v);
		ed.heavy = g[ed.v].sub << 1 >= g[ed.u].sub;
		g[ed.v].par_heav = ed.heavy;
		start[ed.u] = start[ed.u] & !ed.heavy;
	}
	for (int i = 0, c = 0; i < n; i++) {
		if (!start[i]) continue;
		hp.push_back(HP());
		int node = i;
		while (true) {
			g[node].col = c;
			hp.back().v.push_back(node);
			if (!node || !g[node].par_heav) break;
			node = g[node].par;
		}
		std::reverse(hp.back().v.begin(), hp.back().v.end());
		hp.back().init();
		c++;
	}
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int node, val; std::cin >> node >> val; node--;
			hp[g[node].col].seg.set(g[node].dep - g[hp[g[node].col].v[0]].dep, val);
		} else {
			int u, v; std::cin >> u >> v; u--, v--;
			int ans = 0;
			while (g[u].col != g[v].col) {
				if (g[hp[g[u].col].v[0]].dep < g[hp[g[v].col].v[0]].dep) {
					ans = std::max(ans, hp[g[v].col].seg.get(0, g[v].dep - g[hp[g[v].col].v[0]].dep + 1));
					v = g[hp[g[v].col].v[0]].par;
				} else {
					ans = std::max(ans, hp[g[u].col].seg.get(0, g[u].dep - g[hp[g[u].col].v[0]].dep + 1));
					u = g[hp[g[u].col].v[0]].par;
				}
			}
			if (g[u].dep > g[v].dep) std::swap(u, v);
			ans = std::max(ans, hp[g[u].col].seg.get(g[u].dep - g[hp[g[u].col].v[0]].dep, g[v].dep - g[hp[g[u].col].v[0]].dep + 1));
			std::cout << ans << " ";
		}
	}
	std::cout << "\n";
	
}
