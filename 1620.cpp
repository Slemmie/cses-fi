#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n, t; std::cin >> n >> t;
	std::vector <ll> a(n);
	for (ll& x : a) std::cin >> x;
	ll l = 0, r = 1LL << 60LL;
	while (l < r) {
		bool ok = false;
		ll sum = 0;
		for (ll x : a) {
			sum += (l + r) / 2LL / x;
			if (sum >= t) {
				ok = true;
				break;
			}
		}
		if (ok) r = (l + r) / 2LL;
		else l = (l + r) / 2LL + 1LL;
	}
	std::cout << l << "\n";
	
}
