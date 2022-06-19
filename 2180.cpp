#include <bits/stdc++.h>
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <std::vector <int>> g(2, std::vector <int> (n));
	for (auto& v : g) for (int& x : v) std::cin >> x;
	std::vector <int> have(2, 0);
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		have[0] += g[0][i] - 1;
		have[1] += g[1][i] - 1;
		if (have[0] < 0 && have[1] > 0) {
			int d = std::min(-have[0], have[1]);
			have[0] += d, have[1] -= d, ans += d;
		} else if (have[1] < 0 && have[0] > 0) {
			int d = std::min(have[0], -have[1]);
			have[0] -= d, have[1] += d, ans += d;
		}
		ans += abs(have[0]) + abs(have[1]);
	}
	std::cout << ans << "\n";
}
