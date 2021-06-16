#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		bool second = true;
		while (n--) {
			int x; std::cin >> x;
			second &= !(x & 1);
		}
		std::cout << (second ? "second\n" : "first\n");
	}
	
}
