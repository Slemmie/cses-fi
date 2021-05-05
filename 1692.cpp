#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::string ans(1 << 21, '$');
	std::vector <bool> vis(1 << 21, false);
	std::vector <int> state(1 << 21, 0);
	state[0] = -1;
	int node = 0;
	std::vector <int> points(1 << 21, 0);
	while (true) {
		if (!state[node]) {
			ans[node] = '1';
			state[node] = 1;
			node++;
			points[node] = ((points[node - 1] << 1) + 1) & ((1 << n) - 1);
			state[node] = -1;
		} else if (state[node] != -1) {
			if (node >= n) vis[points[node]] = false;
			node--;
		} else {
			if (node >= n) {
				if (vis[points[node]]) {
					node--;
					continue;
				}
				vis[points[node]] = true;
			}
			if (node == (1 << n) - 1 + n) {
				for (int i = 0; i < node; i++) {
					std::cout << ans[i];
				}
				std::cout << "\n";
				return 0;
			}
			ans[node] = '0';
			state[node] = 0;
			node++;
			points[node] = (points[node - 1] << 1) & ((1 << n) - 1);
			state[node] = -1;
		}
	}
	assert(false);
	
}
