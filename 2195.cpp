#include <bits/stdc++.h>

typedef long long ll;

struct P {
	ll x, y;
	P operator - (const P& oth) const {
		return { x - oth.x, y - oth.y };
	}
	ll operator * (const P& oth) const {
		return x * oth.y - y * oth.x;
	}
	bool operator < (const P& oth) const {
		return x == oth.x ? y < oth.y : x < oth.x;
	}
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, size = 0; std::cin >> n;
	std::vector <P> p(n), ans;
	for (P& x : p) std::cin >> x.x >> x.y;
	std::sort(p.begin(), p.end());
	for (int side = 0; side <= 1; side++) {
		for (int i = 0; i < n; i++) {
			while ((int)ans.size() - size >= 2) {
				P p1 = ans[(int)ans.size() - 2];
				P p2 = ans[(int)ans.size() - 1];
				ll cross = (p2 - p1) * (p[i] - p1);
				if (cross <= 0) break;
				ans.pop_back();
			}
			ans.push_back(p[i]);
		}
		ans.pop_back();
		size = ans.size();
		std::reverse(p.begin(), p.end());
	}
	std::cout << ans.size() << "\n";
	for (P x : ans) std::cout << x.x << " " << x.y << "\n";
	
}
