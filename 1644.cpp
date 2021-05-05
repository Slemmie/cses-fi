#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, a, b; std::cin >> n >> a >> b;
	std::vector <ll> v(n), p(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		p[i] = v[i];
		if (i) p[i] += p[i - 1];
	}
	std::map <ll, int> avail;
	avail[0]++;
	ll ans = -(1LL << 60LL);
	for (int i = a - 1; i < n; i++) {
		if (i - a >= 0) {
			avail[p[i - a]]++;
		}
		if (i - b - 1 >= -1) {
			if (i - b - 1 == -1) {
				auto it = avail.find(0);
				if (!--it->second) avail.erase(it);
			} else {
				auto it = avail.find(p[i - b - 1]);
				if (!--it->second) avail.erase(it);
			}
		}
		ans = std::max(ans, p[i] - avail.begin()->first);
	}
	std::cout << ans << "\n";
	
}
