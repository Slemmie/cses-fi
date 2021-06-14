#include <bits/stdc++.h>

typedef long long ll;

ll ab(ll x) {
	if (x < 0LL) x = -x;
	return x;
}

struct P {
	ll x, y;
	void read() {
		std::cin >> y >> x;
	}
};

bool sortX(const P& p1, const P& p2) {
	return p1.x < p2.x;
}

bool sortY(const P& p1, const P& p2) {
	return p1.y < p2.y;
}

ll dist(const P& p1, const P& p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

ll brute(const std::vector <P>& p) {
	int n = p.size();
	ll r = ll(8e18);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll dst = dist(p[i], p[j]);
			if (dst < r) {
				r = dst;
			}
		}
	}
	return r;
}

ll strip(std::vector <P>& p, ll d) {
	int n = p.size();
	std::sort(p.begin(), p.end(), sortY);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && p[j].y - p[i].y < d && j <= i + 7; j++) {
			assert(j <= i + 7);
			ll dst = dist(p[i], p[j]);
			if (dst < d) {
				d = dst;
			}
		}
	}
	return d;
}

P p[int(2e5)];
ll rec(int l, int r) {
	if ((r - l + 1) <= 3) {
		std::vector <P> x;
		for (int i = l; i <= r; i++) x.push_back(p[i]);
		return brute(x);
	}
	int mid = (l + r) >> 1;
	P pmid = p[mid];
	ll left = rec(l, mid);
	ll right = rec(mid + 1, r);
	ll d = std::min(left, right);
	std::vector <P> strp;
	for (int i = l; i <= r; i++) {
		if (ab(p[i].x - pmid.x) < d) {
			strp.push_back(p[i]);
		}
	}
	return std::min(d, strip(strp, d));
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	for (int i = 0; i < n; i++) p[i].read();
	for (P& x : p) x.read();
	std::sort(p, p + n, sortX);
	std::cout << rec(0, n - 1) << "\n";
	
}
