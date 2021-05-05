#include <bits/stdc++.h>
 
typedef long long ll;
 
int n, q;
std::vector <std::vector <int>> g;
std::vector <ll> vals;
 
struct Seg {
	
	int size;
	std::vector <ll> v, w;
	
	Seg(int s) : size(1) {
		while (size < s) size <<= 1;
		v.resize(size << 1, 0);
		w.resize(size << 1, 0);
	}
	
	void update(int tl, int tr, ll val, int now, int l, int r) {
		if (w[now]) {
			v[now] += (r - l) * w[now];
			if (r - l - 1) {
				w[now * 2 + 1] += w[now];
				w[now * 2 + 2] += w[now];
			}
			w[now] = 0;
		}
		if (l >= tr || r <= tl) return;
		if (l >= tl && r <= tr) {
			v[now] += (r - l) * val;
			if (r - l - 1) {
				w[now * 2 + 1] += val;
				w[now * 2 + 2] += val;
			}
			return;
		}
		int mid = (l + r) >> 1;
		update(tl, tr, val, now * 2 + 1, l, mid);
		update(tl, tr, val, now * 2 + 2, mid, r);
		v[now] = v[now * 2 + 1] + v[now * 2 + 2];
	}
	
	void update(int l, int r, ll val) {
		update(l, r, val, 0, 0, size);
	}
	
	ll get(int ind, int now, int l, int r) {
		if (w[now]) {
			v[now] += (r - l) * w[now];
			if (r - l - 1) {
				w[now * 2 + 1] += w[now];
				w[now * 2 + 2] += w[now];
			}
			w[now] = 0;
		}
		if (!(r - l - 1)) return v[now];
		int mid = (l + r) >> 1;
		if (ind < mid) return get(ind, now * 2 + 1, l, mid);
		return get(ind, now * 2 + 2, mid, r);
	}
	
	ll get(int ind) {
		return get(ind, 0, 0, size);
	}
	
};
 
Seg* seg = nullptr;
std::vector <int> L, R;
 
void dfs(int node = 0, ll par = -1) {
	static int ind = 0;
	L[node] = ind++;
	for (int x : g[node]) if (x != par) {
		dfs(x, node);
	}
	R[node] = ind;
	seg->update(L[node], R[node], vals[node]);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> q;
	seg = new Seg(n);
	L.resize(n);
	R.resize(n);
	g.resize(n);
	vals.resize(n);
	for (ll& x : vals) std::cin >> x;
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs();
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int u; ll val; std::cin >> u >> val;
			ll change = val - vals[u - 1];
			vals[u - 1] = val;
			seg->update(L[u - 1], R[u - 1], change);
		} else {
			int u; std::cin >> u;
			std::cout << seg->get(L[u - 1]) << "\n";
		}
	}
	
}
