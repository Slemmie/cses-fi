#include <bits/stdc++.h>
 
struct Tile {
	int x, y, px, py, d;
	bool operator<(const Tile& other) const {
		return d > other.d;
	}
};
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m, sx, sy; std::cin >> n >> m;
	std::vector <std::string> g(n);
	for (int i = 0; i < n; i++) {
		std::cin >> g[i];
		for (int j = 0; j < m; j++) if (g[i][j] == 'A') sx = j, sy = i;
	}
	std::vector <std::vector <bool>> vis(n, std::vector <bool> (m, false));
	std::vector <std::vector <std::pair <int, int>>> par(n, std::vector <std::pair <int, int>> (m, { -1, - 1 }));
	std::priority_queue <Tile> pq;
	pq.push({ sx, sy, sx, sy, 0 });
	while (pq.size()) {
		auto now = pq.top(); pq.pop();
		if (vis[now.y][now.x] || g[now.y][now.x] == '#') continue;
		vis[now.y][now.x] = true;
		par[now.y][now.x] = { now.px, now.py };
		if (g[now.y][now.x] == 'B') {
			std::cout << "YES\n";
			std::string ans = "";
			int x = now.x, y = now.y;
			while (x != sx || y != sy) {
				if (par[y][x] == std::make_pair(x - 1, y)) ans += 'R', x--;
				if (par[y][x] == std::make_pair(x + 1, y)) ans += 'L', x++;
				if (par[y][x] == std::make_pair(x, y - 1)) ans += 'D', y--;
				if (par[y][x] == std::make_pair(x, y + 1)) ans += 'U', y++;
			}
			std::reverse(ans.begin(), ans.end());
			std::cout << ans.length() << "\n" << ans << "\n";
			return 0;
		}
		if (now.x && g[now.y][now.x - 1] != '#') pq.push({ now.x - 1, now.y, now.x, now.y, now.d + 1 });
		if (now.x < m - 1 && g[now.y][now.x + 1] != '#') pq.push({ now.x + 1, now.y, now.x, now.y, now.d + 1 });
		if (now.y && g[now.y - 1][now.x] != '#') pq.push({ now.x, now.y - 1, now.x, now.y, now.d + 1 });
		if (now.y < n - 1 && g[now.y + 1][now.x] != '#') pq.push({ now.x, now.y + 1, now.x, now.y, now.d + 1 });
	}
	std::cout << "NO\n";
	
}
