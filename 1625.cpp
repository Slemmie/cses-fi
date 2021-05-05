#include <bits/stdc++.h>
 
std::string s;
std::unordered_map <char, std::pair <int, int>> dirs;
int vis[7][7];
 
int rec(int x = 0, int y = 0, int d = 0, char prv = '$') {
	if (d == 48 || vis[6][0] || x < 0 || y < 0 || x > 6 || y > 6 || (prv == 'L' && (!x || vis[y][x - 1]) && y > 0 && y < 6 && !vis[y - 1][x] && !vis[y + 1][x]) || (prv == 'R' && (x == 6 || vis[y][x + 1]) && y > 0 && y < 6 && !vis[y - 1][x] && !vis[y + 1][x]) || (prv == 'U' && (!y || vis[y - 1][x]) && x > 0 && x < 6 && !vis[y][x - 1] && !vis[y][x + 1]) || (prv == 'D' && (y == 6 || vis[y + 1][x]) && x > 0 && x < 6 && !vis[y][x - 1] && !vis[y][x + 1])) return d == 48;
	if (s[d] != '?') {
		x += dirs[s[d]].first;
		y += dirs[s[d]].second;
		if (x < 0 || x > 6 || y < 0 || y > 6 || vis[y][x]) return 0;
		vis[y][x] = true;
		int r = rec(x, y, d + 1, s[d]);
		vis[y][x] = false;
		return r;
	}
	int r = 0;
	for (const auto& p : dirs) {
		auto dir = p.second;
		int nx = x + dir.first, ny = y + dir.second;
		if (nx < 0 || nx > 6 || ny < 0 || ny > 6 || vis[ny][nx]) continue;
		vis[ny][nx] = true;
		r += rec(nx, ny, d + 1, p.first);
		vis[ny][nx] = false;
	}
	return r;
}
 
int main() {
	
	std::cin >> s;
	dirs['D'] = {0, 1}; dirs['U'] = {0, -1}; dirs['L'] = {-1, 0}; dirs['R'] = {1, 0};
	vis[0][0] = true;
	std::cout << rec() << "\n";
	
}
