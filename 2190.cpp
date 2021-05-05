#include <bits/stdc++.h>

typedef long long ll;

struct P {
	ll x, y;
};

bool between(P a, P p, P b) {
	return
	p.x <= std::max(a.x, b.x) && p.x >= std::min(a.x, b.x)
	&&
	p.y <= std::max(a.y, b.y) && p.y >= std::min(a.y, b.y)
	;
}

int ori(P p, P a, P b) {
	ll v =
	(a.y - p.y) * (b.x - a.x)
	-
	(a.x - p.x) * (b.y - a.y)
	;
	if (!v) return 0;
	return int(v < 0LL) + 1;
}

bool check(P a, P b, P c, P d) {
	int o1 = ori(a, b, c);
	int o2 = ori(a, b, d);
	int o3 = ori(c, d, a);
	int o4 = ori(c, d, b);
	if (o1 != o2 && o3 != o4) return true;
	return
	(!o1 && between(a, c, b))
	||
	(!o2 && between(a, d, b))
	||
	(!o3 && between(c, a, d))
	||
	(!o4 && between(c, b, d))
	;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		P a, b, c, d;
		std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		std::cout << (check(a, b, c, d) ? "YES\n" : "NO\n");
	}
	
}
