#include <bits/stdc++.h>

int n, q;
std::vector <int> nex;
std::vector <std::vector <int>> g;

std::vector <int> part, inde;
std::vector <std::vector <int>> cyc;
std::vector <int> roots;

int dfs(int node, std::vector <bool>& vis, std::vector <bool>& rec) {
	if (rec[node]) {
		vis[node] = true;
		cyc.push_back({ });
		return node;
	}
	if (vis[node]) return -1;
	rec[node] = true;
	vis[node] = true;
	int r = dfs(nex[node], vis, rec);
	if (r != -1) {
		roots.push_back(node);
		part[node] = (int)cyc.size() - 1;
		cyc.back().push_back(node);
		if (r == node) r = -1;
	}
	return r;
}

std::vector <std::vector <int>> bin;
std::vector <int> dep;

std::vector <int> cur;
void dfs2(int node, int d = 0) {
	cur.push_back(node);
	dep[node] = d;
	for (int i = 0; i < 20; i++) {
		int bit = 1 << i;
		if (bit < (int)cur.size()) {
			bin[node][i] = cur[(int)cur.size() - 1 - bit];
		} else break;
	}
	for (int x : g[node]) if (part[x] == -1) dfs2(x, d + 1);
	cur.pop_back();
}

int anc(int node, int up) {
	for (int i = 19; i >= 0; i--) {
		int bit = 1 << i;
		if (up & bit) {
			up ^= bit;
			node = bin[node][i];
		}
	}
	return node;
}

int get(int v, int k) {
	if (k > dep[v]) {
		k -= dep[v];
		v = anc(v, dep[v]);
	} else {
		v = anc(v, k);
		return v;
	}
	assert(part[v] != -1);
	int i = part[v];
	assert(inde[v] != -1);
	int j = inde[v];
	j += k;
	j %= (int)cyc[i].size();
	return cyc[i][j];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> q;
	nex.resize(n);
	g.resize(n);
	part.resize(n, -1);
	inde.resize(n, -1);
	bin.resize(n, std::vector <int> (20, -1));
	dep.resize(n, 0);
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p; p--;
		nex[i] = p;
		g[p].push_back(i);
	}
	std::vector <bool> vis(n, false);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			std::vector <bool> rec(n, false);
			auto sz = cyc.size();
			dfs(i, vis, rec);
			if (cyc.size() != sz) std::reverse(cyc.back().begin(), cyc.back().end());
			for (int j = 0; j < (int)cyc.back().size(); j++) {
				inde[cyc.back()[j]] = j;
			}
		}
	}
	for (int x : roots) dfs2(x);
	while (q--) {
		int v, k; std::cin >> v >> k; v--;
		std::cout << get(v, k) + 1 << "\n";
	}
	
}
