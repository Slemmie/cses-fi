#include <bits/stdc++.h>

typedef long long ll;

struct V {
	ll x, y;
};

bool contains(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	if (y1 > y2) std::swap(y1, y2);
	if (x1 > x2) std::swap(x1, x2);
	return x3 >= x1 && x3 <= x2 && y3 >= y1 && y3 <= y2;
}

int check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	V v1 = { x2 - x1, y2 - y1 };
	V v2 = { x2 - x3, y2 - y3 };
	ll cross_product = v1.x * v2.y - v1.y * v2.x;
	if (!cross_product) {
		if (contains(x1, y1, x2, y2, x3, y3)) return 0;
		return -1;
	}
	return cross_product < 0LL ? -1 : 1;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::vector <V> pol(n);
	for (int i = 0; i < n; i++) std::cin >> pol[i].x >> pol[i].y;
	for (int j = 0; j < m; j++) {
		bool ans = false;
		bool fl = true;
		V v; std::cin >> v.x >> v.y;
		for (int i = 0; i < n; i++) {
			int x1 = pol[i].x, x2 = pol[(i + 1) % n].x;
			int y1 = pol[i].y, y2 = pol[(i + 1) % n].y;
			if (y1 > y2) std::swap(y1, y2), std::swap(x1, x2);
			int now = check(x1, y1, x2, y2, v.x, v.y);
			if (!now) {
				fl = false;
				std::cout << "BOUNDARY\n";
				break;
			}
			ans ^= now == 1 && v.y >= y1 && v.y < y2;
		}
		if (fl) std::cout << (ans ? "INSIDE\n" : "OUTSIDE\n");
	}
	
}
