#include <bits/stdc++.h>

struct Edge {
	
	int to;
	long long flow;
	int capacity, hptr;
	
};

int n, m;
std::vector <std::vector <Edge>> g;
std::vector <int> lvl;

bool bfs() {
	for (int& x : lvl) x = -1;
	lvl[0] = 0;
	std::queue <int> q;
	q.push(0);
	while (q.size()) {
		int now = q.front(); q.pop();
		for (auto e : g[now]) {
			if (lvl[e.to] < 0 && e.flow < (long long)e.capacity) {
				lvl[e.to] = lvl[now] + 1;
				q.push(e.to);
			}
		}
	}
	return lvl[n - 1] >= 0;
}

long long send(int node, long long flow_now, std::vector <int>& cur) {
	if (node == n - 1) return flow_now;
	for (; cur[node] != (int)g[node].size(); cur[node]++) {
		auto& e = g[node][cur[node]];
		int v = e.to;
		if (lvl[node] + 1 == lvl[v] && e.flow < (long long)e.capacity) {
			long long put_flow = std::min(flow_now, (long long)e.capacity - e.flow);
			long long final_flow = send(v, put_flow, cur);
			if (final_flow) {
				e.flow += final_flow;
				g[v][e.hptr].flow -= final_flow;
				return final_flow;
			}
		}
	}
	return 0;
}

long long maxflow() {
	if (n == 1) return 0;
	long long ans = 0;
	while (bfs()) {
		std::vector <int> cur(n, 0);
		while (true) {
			long long flow_now = send(0, 1LL << 60LL, cur);
			ans += flow_now;
			if (!flow_now) break;
		}
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	lvl.resize(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		Edge U = { v, 0, 1, (int)g[v].size() };
		Edge V = { u, 0, 1, (int)g[u].size() };
		g[u].emplace_back(U);
		g[v].emplace_back(V);
	}
	std::cout << maxflow() << "\n";
	for (int i = 0; i < n; i++) {
		for (Edge e : g[i]) {
			if (lvl[i] >= 0 && lvl[e.to] < 0 && e.capacity > 0) {
				std::cout << i + 1 << " " << e.to + 1 << "\n";
			}
		}
	}
	
}
