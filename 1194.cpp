#include <bits/stdc++.h>

struct P {
	int x, y;
};

struct D {
	P p = { -1, -1 };
	char c = '$';
};

bool operator == (const P& a, const P& b) {
	return a.x == b.x && a.y == b.y;
}

bool operator != (const P& a, const P& b) {
	return !(a == b);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <P> M;
	P s;
	std::vector <std::string> g(n);
	std::vector <std::vector <int>> gi(n, std::vector <int> (m, 1 << 30));
	std::queue <std::pair <P, int>> q;
	for (int i = 0; i < n; i++) {
		std::cin >> g[i];
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'M') M.push_back({ i, j }), q.push({ { i, j }, 1 });
			else if (g[i][j] == 'A') s = { i, j };
			else if (g[i][j] == '#') gi[i][j] = 1;
		}
	}
	while (q.size()) {
		auto now = q.front(); q.pop();
		int i = now.first.x, j = now.first.y, w = now.second;
		if (i < 0 || j < 0 || i >= n || j >= m) continue;
		if (gi[i][j] != 1 << 30) continue;
		gi[i][j] = w;
		q.push({ { i - 1, j }, w + 1 });
		q.push({ { i, j - 1 }, w + 1 });
		q.push({ { i + 1, j }, w + 1 });
		q.push({ { i, j + 1 }, w + 1 });
	}
	std::vector <std::vector <D>> par(n, std::vector <D> (m));
	std::queue <std::pair <P, std::pair <D, int>>> Q;
	Q.push({ s, { D(), 1 } });
	while (Q.size()) {
		auto now = Q.front(); Q.pop();
		int i = now.first.x, j = now.first.y, w = now.second.second;
		if (i < 0 || j < 0 || i >= n || j >= m) continue;
		if (gi[i][j] <= w) continue;
		if (par[i][j].c != '$') continue;
		par[i][j] = now.second.first;
		if (!i || !j || i == n - 1 || j == m - 1) {
			std::cout << "YES\n";
			std::string ans = "";
			P p = now.first;
			while (p != s) {
				ans += par[p.x][p.y].c;
				p = par[p.x][p.y].p;
			}
			std::reverse(ans.begin(), ans.end());
			std::cout << ans.length() << "\n";
			std::cout << ans << "\n";
			return 0;
		}
		Q.push({ { i - 1, j }, { { { i, j }, 'U' }, w + 1 } });
		Q.push({ { i, j - 1 }, { { { i, j }, 'L' }, w + 1 } });
		Q.push({ { i + 1, j }, { { { i, j }, 'D' }, w + 1 } });
		Q.push({ { i, j + 1 }, { { { i, j }, 'R' }, w + 1 } });
	}
	std::cout << "NO\n";
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	std::cout << (gi[i][j] == (1 << 30) ? 0 : gi[i][j]) << " \n"[j == m - 1];
	
}
