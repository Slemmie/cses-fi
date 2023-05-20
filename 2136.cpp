#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, k; std::cin >> n >> k;
	std::vector <int> a(n, 0);
	for (int i = 0; i < n; i++) {
		std::string s; std::cin >> s;
		while (s.size()) {
			a[i] |= (s.back() - '0') << (s.size() - 1);
			s.pop_back();
		}
	}
	int ans = 1 << 30;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = std::min(ans, __builtin_popcount(a[i] ^ a[j]));
		}
	}
	std::cout << ans << "\n";
}
