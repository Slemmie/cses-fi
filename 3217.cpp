#include <bits/stdc++.h>

constexpr const int di[] = { -2, -2, -1, 1, 2, 2, -1, 1 };
constexpr const int dj[] = { -1, 1, -2, -2, -1, 1, 2, 2 };

int main() {
	int n; std::cin >> n;
	std::vector <std::vector <int>> g(n, std::vector <int> (n, -1));
	std::queue <std::pair <std::pair <int, int>, int>> q;
	q.push({ { 0, 0 }, 0 });
	while (q.size()) {
		auto [p, d] = q.front();
		q.pop();
		auto [i, j] = p;
		if (g[i][j] != -1) continue;
		g[i][j] = d;
		for (int k = 0; k < 8; k++) {
			int ii = i + di[k];
			int jj = j + dj[k];
			if (ii >= 0 && ii < n && jj >= 0 && jj < n) q.push({ { ii, jj }, d + 1 });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << g[i][j] << " \n"[j + 1 == n];
		}
	}
}
