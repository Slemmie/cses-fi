#include <bits/stdc++.h>
 
int n, q;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> q;
	std::vector <std::vector <int>> preg(n + 1, std::vector <int> (n + 1, 0));
	std::vector <std::string> g(n);
	for (auto& x : g) std::cin >> x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			preg[i][j] = preg[i][j - 1] + (g[i - 1][j - 1] == '*');
		}
	}
	std::vector <std::vector <int>> pre(n + 1, std::vector <int> (n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pre[j][i] = pre[j - 1][i] + preg[j][i];
		}
	}
	while (q--) {
		int y1, x1, y2, x2; std::cin >> y1 >> x1 >> y2 >> x2;
		int ans = pre[y2][x2];
		ans -= pre[y2][x1 - 1];
		ans -= pre[y1 - 1][x2];
		ans += pre[y1 - 1][x1 - 1];
		std::cout << ans << "\n";
	}
	
}
