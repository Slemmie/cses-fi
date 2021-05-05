#include <bits/stdc++.h>

int g[8][8];

int dx[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 1, -1, 2, 2, -2, -2 };

bool ok(int x, int y) {
	return x > -1 && y > -1 && x < 8 && y < 8 && !g[x][y];
}

int cnt(int x, int y) {
	int r = 0;
	for (int i = 0; i < 8; i++) r += ok(x + dx[i], y + dy[i]);
	return r;
}

void dfs(int x, int y, int d = 1) {
	g[x][y] = d;
	if (d == 64) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				std::cout << g[i][j] << " \n"[j == 7];
		exit(0);
	}
	std::vector <std::pair <int, int>> m;
	for (int i = 0; i < 8; i++)
		if (ok(x + dx[i], y + dy[i]))
			m.push_back({ cnt(x + dx[i], y + dy[i]), i });
	std::sort(m.begin(), m.end());
	for (auto p : m) dfs(x + dx[p.second], y + dy[p.second], d + 1);
	g[x][y] = 0;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) g[i][j] = 0;
	int u, v; std::cin >> u >> v; dfs(v - 1, u - 1);
	
}
