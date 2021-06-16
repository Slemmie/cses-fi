#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		int n, ans = 0; std::cin >> n;
		while (n--) {
			int x; std::cin >> x;
			ans ^= x;
		}
		std::cout << (ans ? "first\n" : "second\n");
	}
	
}
