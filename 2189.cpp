#include <bits/stdc++.h>

typedef long long ll;

struct V {
	
	ll x, y;
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		ll x1, y1, x2, y2, x3, y3; std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		V v1 = { x2 - x1, y2 - y1 };
		V v2 = { x2 - x3, y2 - y3 };
		ll cross_product = v1.x * v2.y - v1.y * v2.x;
		if (!cross_product) std::cout << "TOUCH\n";
		else std::cout << (cross_product < 0LL ? "LEFT\n" : "RIGHT\n");
	}
	
}
