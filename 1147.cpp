#include <bits/stdc++.h>

int n, m;
std::vector <std::string> g;
std::vector <std::vector <int>> suf;
std::vector <std::vector <int>> upd;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	g.resize(n);
	for (auto& x : g) {
		std::cin >> x;
	}
	suf.resize(n, std::vector <int> (m + 1, 0));
	for (int i = n - 1; ~i; i--) {
		for (int j = 0; j < m; j++) {
			suf[i][j] = g[i][j] == '.';
			if (i + 1 != n && g[i][j] == '.') {
				suf[i][j] = std::max(suf[i][j], suf[i + 1][j] + 1);
			}
		}
	}
	upd = suf;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		std::vector <int> stck = { 0 };
		for (int j = 1; j <= m; j++) {
			if (suf[i][j] <= upd[i][stck.back()]) {
				while ((int) stck.size() >= 2 && suf[i][j] <= upd[i][stck[(int) stck.size() - 2]]) {
					int dif = j - stck.back();
					ans = std::max(ans, dif * upd[i][stck.back()]);
					stck.pop_back();
				}
				int dif = j - stck.back();
				ans = std::max(ans, dif * upd[i][stck.back()]);
				upd[i][stck.back()] = std::min(upd[i][stck.back()], suf[i][j]);
			} else {
				stck.push_back(j);
			}
		}
	}
	std::cout << ans << "\n";
	
}
