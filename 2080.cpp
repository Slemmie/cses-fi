#include <bits/stdc++.h>

typedef long long ll;

int n, k, mxd, dep[200001], sub[200001];
bool vis[200001];
std::vector <int> g[200001];
ll ans = 0;

int get_size(int node, int par = -1) {
	sub[node] = 1;
	for (int x : g[node]) if (!vis[x] && x != par) sub[node] += get_size(x, node);
	return sub[node];
}

int cen(int size, int node, int par = -1) {
	for (int x : g[node]) if (!vis[x] && x != par && sub[x] >= size) return cen(size, x, node);
	return node;
}

void dfs(int node, int par, bool which, int d = 1) {
	if (d > k) return;
	mxd = std::max(mxd, d);
	if (which) dep[d]++;
	else ans += dep[k - d];
	for (int x : g[node]) if (!vis[x] && x != par) dfs(x, node, which, d + 1);
}

void calc(int node = 0) {
	int c = cen(get_size(node) >> 1, node);
	vis[c] = true;
	mxd = 0;
	for (int x : g[c]) if (!vis[x]) {
		dfs(x, c, false);
		dfs(x, c, true);
	}
	std::fill(dep + 1, dep + mxd + 1, 0);
	for (int x : g[c]) if (!vis[x]) calc(x);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	memset(vis, false, sizeof(vis));
	dep[0] = 1;
	std::cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	calc();
	std::cout << ans << "\n";
	
}
