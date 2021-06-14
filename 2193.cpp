#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

struct P {
	ll x, y;
	void read() {
		std::cin >> x >> y;
		x += ll(1e9);
		y += ll(1e9);
	}
};
std::vector <P> a;
int n;

ll area() {
	ll r = 0;
	for (int i = 1; i < n; i++) {
		r += (a[i].x + a[i - 1].x) * (a[i].y - a[i - 1].y);
	}
	return llabs(r);
}

ll edge(P p1, P p2) {
	ll x = llabs(p1.x - p2.x);
	ll y = llabs(p1.y - p2.y);
	if (!x && !y) return 0;
	if (!x) return y;
	if (!y) return x;
	ll gcd = std::gcd(x, y);
	x /= gcd;
	y /= gcd;
	return llabs(p1.y - p2.y) / y;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	a.resize(n);
	for (P& p : a) p.read();
	a.emplace_back(a.front());
	n++;
	ll onEdge = 0;
	for (int i = 1; i < n; i++) {
		onEdge += edge(a[i - 1], a[i]);
	}
	std::cout << (area() >> 1LL) - (onEdge >> 1LL) + 1LL << " " << onEdge << "\n";
	
}
