#include <bits/stdc++.h>

int f(int n, int k) {
	if (!(n ^ 1)) return 1;
	if (k <= (n + 1) >> 1) {
		if ((k << 1) > n) return (k << 1) % n;
		return k << 1;
	}
	return (f(n >> 1, k - ((n + 1) >> 1)) << 1) + (n & 1 ? 1 : -1);
}

void test() {
	int n, k; std::cin >> n >> k;
	std::cout << f(n, k) << "\n";
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) test();
	
}
