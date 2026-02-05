#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::pair <long long, long long> xx, yy;
	for (int i = 0; i < n; i++) {
		int x, y; std::cin >> x >> y;
		long long add = x + y;
		long long sub = x - y;
		if (!i) xx = { add, add }, yy = { sub, sub };
		xx.first = std::min(xx.first, add);
		xx.second = std::max(xx.second, add);
		yy.first = std::min(yy.first, sub);
		yy.second = std::max(yy.second, sub);
		std::cout << std::max(xx.second - xx.first, yy.second - yy.first) << (char) 10;
	}
}
