#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, k; std::cin >> n >> k;
	std::vector <int> a(k);
	for (int& x : a) std::cin >> x;
	std::string ans = "L";
	for (int i = 1; i <= n; i++) {
		ans += "L";
		for (int x : a) {
			if (i - x < 0) continue;
			if (ans[i - x] == 'L') {
				ans[i] = 'W';
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i];
	}
	std::cout << "\n";
	
}
