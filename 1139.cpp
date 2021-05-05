#include <bits/stdc++.h>
 
std::vector <std::set <int>*> sub;
std::vector <std::vector <int>> g;
std::vector <int> c;
int n;
std::vector <int> clr;
std::vector <int> ans;
 
std::set <int>* merge(std::set <std::set<int>*>& st, int node) {
	if (st.empty()) {
		clr.push_back(node);
		return new std::set <int>;
	}
	std::set <int>* r = *prev(st.end());
	st.erase(prev(st.end()));
	for (auto& s : st)
		for (int x : *s)
			r->insert(x);
	return r;
}
 
void dfs(int node = 0, int par = -1) {
	std::set <std::set <int>*> tmp;
	for (int x : g[node]) if (x != par) dfs(x, node), tmp.insert(sub[x]);
	sub[node] = merge(tmp, node);
	sub[node]->insert(c[node]);
	ans[node] = sub[node]->size();
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	g.resize(n);
	sub.resize(n, nullptr);
	c.resize(n);
	ans.resize(n);
	for (int& x : c) std::cin >> x;
	for (int i = 0; i < n - 1; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs();
	for (int x : ans) std::cout << x << " ";
	std::cout << "\n";
	for (int x : clr) delete(sub[x]);
	
}
