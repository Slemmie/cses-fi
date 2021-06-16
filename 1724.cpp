#include <bits/stdc++.h>

typedef long long ll;

const long long inf = 1LL << 60LL;

int n, m, p;
std::vector <std::vector <ll>> g;

std::vector <std::vector <ll>> mul(const std::vector <std::vector <ll>>& a, const std::vector <std::vector <ll>>& b) {
	std::vector <std::vector <ll>> r(n, std::vector <ll> (n, inf));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				r[i][j] = std::min(r[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return r;
}

std::vector <std::vector <ll>> pw(std::vector <std::vector <ll>> x) {
	std::vector <std::vector <ll>> r(x);
	while (p) {
		if (p & 1) {
			r = mul(r, x);
		}
		p >>= 1;
		x = mul(x, x);
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m >> p; p--;
	g.resize(n, std::vector <ll> (n, inf));
	for (int i = 0; i < m; i++) {
		int u, v; long long c; std::cin >> u >> v >> c; u--, v--;
		g[u][v] = std::min(g[u][v], c);
	}
	ll ans = pw(g)[0][n - 1];
	std::cout << (ans == inf ? -1LL : ans) << "\n";
	
}
