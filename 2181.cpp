#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

ll dp[1000][1 << 10];
int n, m;

ll f(int h, int mask) {
	if (h == m - 1) {
		for (int i = 0; i < n - 1; i++) {
			if (!((1 << i) & mask) && !((1 << (i + 1)) & mask)) {
				mask |= 1 << i;
				mask |= 1 << (i + 1);
			}
		}
		return mask == (1 << n) - 1;
	}
	if (dp[h][mask] != -1) return dp[h][mask];
	dp[h][mask] = 0;
	std::vector <std::pair <int, int>> nxt = { { mask, 0 } };
	for (int i = 0; i < n; i++) {
		std::vector <std::pair <int, int>> psh;
		for (auto p : nxt) {
			if ((1 << i) & p.first) continue;
			psh.push_back({ p.first | (1 << i), p.second | (1 << i) });
			if (i < n - 1 && !((1 << (i + 1)) & p.first))
				psh.push_back({ p.first | (1 << i) | (1 << (i + 1)), p.second });
		}
		for (auto p : psh) nxt.push_back(p);
	}
	for (auto p : nxt) {
		if (p.first != (1 << n) - 1) continue;
		dp[h][mask] += f(h + 1, p.second);
		if (dp[h][mask] >= mod) dp[h][mask] %= mod;
	}
	return dp[h][mask];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	memset(dp, -1, sizeof(dp));
	std::cin >> n >> m;
	std::cout << f(0, 0) << "\n";
	
}
