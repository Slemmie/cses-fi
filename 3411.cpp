#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <int> c[2];
	c[0] = c[1] = std::vector <int> (n);
	for (int i = 0; i < n; i++) std::cin >> c[0][i] >> c[1][i];
	__int128_t ans = 0;
	for (int _ = 0; _ < 2; _++) {
		auto v = c[_];
		std::sort(v.begin(), v.end());
		long long s = 0, cnt = 0;
		for (int x : v) {
			ans += x * cnt++ - s;
			s += x;
		}
	}
	std::string out;
	do {
		out += ans % 10 + '0';
		ans /= 10;
	} while (ans);
	std::reverse(out.begin(), out.end());
	std::cout << out << (char) 10;
}
