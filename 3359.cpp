#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <std::string> g(n);
	for (auto& x : g) std::cin >> x;
	std::vector <std::pair <int, int>> q = { { 0, 0 } };
	std::string ans;
	for (int _ = 0; _ < n * 2 - 2; _++) {
		std::vector <std::vector <std::pair <int, int>>> mp(26);
		ans += g[q[0].first][q[0].second];
		for (auto [i, j] : q) {
			static constexpr const int di[] = { 1, 0 };
			static constexpr const int dj[] = { 0, 1 };
			for (int d = 0; d < 2; d++) {
				int ii = i + di[d];
				int jj = j + dj[d];
				if (ii >= n || jj >= n) continue;
				mp[g[ii][jj] - 'A'].push_back({ ii, jj });
			}
		}
		for (int c = 0; c < 26; c++) {
			if (mp[c].empty()) continue;
			q = mp[c];
			std::sort(q.begin(), q.end());
			q.erase(std::unique(q.begin(), q.end()), q.end());
			break;
		}
	}
	ans += g[q[0].first][q[0].second];
	std::cout << ans << "\n";
}
