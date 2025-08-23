#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, m; std::cin >> n >> m;
	std::vector <std::string> g(n);
	for (auto& x : g) std::cin >> x;
	bool f = 0;
	for (int I = 0; I < n; I++) {
		int i = I, j = 0;
		while (i >= 0 && j < m) {
			if (f) g[i][j] = g[i][j] == 'A' || g[i][j] == 'B' ? g[i][j] ^ 'A' ^ 'B' : 'A';
			if (!f) g[i][j] = g[i][j] == 'C' || g[i][j] == 'D' ? g[i][j] ^ 'C' ^ 'D' : 'C';
			i--;
			j++;
		}
		f ^= 1;
	}
	for (int J = 1; J < m; J++) {
		int i = n - 1, j = J;
		while (i >= 0 && j < m) {
			if (f) g[i][j] = g[i][j] == 'A' || g[i][j] == 'B' ? g[i][j] ^ 'A' ^ 'B' : 'A';
			if (!f) g[i][j] = g[i][j] == 'C' || g[i][j] == 'D' ? g[i][j] ^ 'C' ^ 'D' : 'C';
			i--;
			j++;
		}
		f ^= 1;
	}
	for (const auto& x : g) std::cout << x << "\n";
}
