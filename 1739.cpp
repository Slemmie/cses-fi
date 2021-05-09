#include <bits/stdc++.h>

#define lsb(x) (x & (-x))

int tree[1 << 10][1 << 10];
int grid[1 << 10][1 << 10];

void add(int i, int j, int val) {
	for (; i < (1 << 10); i += lsb(i))
		for (int k = j; k < (1 << 10); k += lsb(k))
			tree[i][k] += val;
}

int get(int i, int j) {
	int r = 0;
	for (; i; i -= lsb(i)) for (int k = j; k; k -= lsb(k)) r += tree[i][k];
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	for (int i = 0; i < n; i++) {
		std::string s; std::cin >> s;
		for (int j = 0; j < n; j++) {
			grid[i][j] = s[j] == '*';
			if (grid[i][j]) add(i + 1, j + 1, 1);
		}
	}
	while (q--) {
		int typ; std::cin >> typ;
		if (typ == 1) {
			int i, j; std::cin >> i >> j; i--, j--;
			add(i + 1, j + 1, grid[i][j] ? -1 : 1);
			grid[i][j] ^= 1;
		} else {
			int i1, j1, i2, j2; std::cin >> i1 >> j1 >> i2 >> j2;
			int ans = get(i2, j2) - get(i2, j1 - 1) - get(i1 - 1, j2) + get(i1 - 1, j1 - 1);
			std::cout << ans << "\n";
		}
	}
	
}
