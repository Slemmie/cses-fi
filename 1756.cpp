#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	
	int n, m; std::cin >> n >> m;
	while (m--) {
		int u, v; std::cin >> u >> v;
		std::cout << std::min(u, v) << " " << std::max(u, v) << "\n";
	}
	
}
