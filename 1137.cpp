#include <bits/stdc++.h>
 
typedef long long ll;
 
struct Seg {
	
	int size;
	std::vector <ll> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size * 2, 0);
	}
	
	void set(int ind, ll val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) set(ind, val, now * 2 + 1, l, mid);
		else set(ind, val, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	void set(int ind, ll val) {
		set(ind, val, 0, 0, size);
	}
	
	ll get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return get(tl, tr, now * 2 + 1, l, mid) + get(tl, tr, now * 2 + 2, mid, r);
	}
	ll get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
};
 
struct Node {
	int f, l;
	ll val;
	std::vector <int> nei;
};
 
Seg* seg = nullptr;
std::vector <Node> g;
 
void dfs(int node, int par) {
	static int cnt = 0;
	g[node].f = cnt++;
	for (int x : g[node].nei) if (x != par) dfs(x, node);
	g[node].l = cnt;
	seg->set(g[node].f, g[node].val);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	seg = new Seg(n);
	g.resize(n);
	for (auto& x : g) std::cin >> x.val;
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].nei.push_back(v);
		g[v].nei.push_back(u);
	}
	dfs(0, -1);
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int ind; ll val; std::cin >> ind >> val; ind--;
			seg->set(g[ind].f, val);
		} else {
			int ind; std::cin >> ind; ind--;
			std::cout << seg->get(g[ind].f, g[ind].l) << "\n";
		}
	}
	
}
#include <bits/stdc++.h>
 
typedef long long ll;
 
struct Seg {
	
	int size;
	std::vector <ll> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size * 2, 0);
	}
	
	void set(int ind, ll val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) set(ind, val, now * 2 + 1, l, mid);
		else set(ind, val, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	void set(int ind, ll val) {
		set(ind, val, 0, 0, size);
	}
	
	ll get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return get(tl, tr, now * 2 + 1, l, mid) + get(tl, tr, now * 2 + 2, mid, r);
	}
	ll get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
};
 
struct Node {
	int f, l;
	ll val;
	std::vector <int> nei;
};
 
Seg* seg = nullptr;
std::vector <Node> g;
 
void dfs(int node, int par) {
	static int cnt = 0;
	g[node].f = cnt++;
	for (int x : g[node].nei) if (x != par) dfs(x, node);
	g[node].l = cnt;
	seg->set(g[node].f, g[node].val);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	seg = new Seg(n);
	g.resize(n);
	for (auto& x : g) std::cin >> x.val;
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].nei.push_back(v);
		g[v].nei.push_back(u);
	}
	dfs(0, -1);
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int ind; ll val; std::cin >> ind >> val; ind--;
			seg->set(g[ind].f, val);
		} else {
			int ind; std::cin >> ind; ind--;
			std::cout << seg->get(g[ind].f, g[ind].l) << "\n";
		}
	}
	
}
