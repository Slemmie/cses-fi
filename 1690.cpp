#include <bits/stdc++.h>

const int mod = 1e9 + 7;
int n, m;
int am[20][20];
int dp[20][1 << 20];

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		am[u][v]++;
	}
	dp[0][1] = 1;
	for (int bit = 0; bit < (1 << n); bit++) {
		for (int i = 0; i < n; i++) {
			if (!(bit & (1 << i))) continue;
			for (int j = 0; j < n; j++) {
				if (!(bit & (1 << j)) && am[i][j]) {
					long long add = (long long)dp[i][bit] * am[i][j];
					add %= mod;
					int& val = dp[j][bit ^ (1 << j)];
					val += add;
					if (val >= mod) val -= mod;
				}
			}
		}
	}
	std::cout << dp[n - 1][(1 << n) - 1] << "\n";
	
}
