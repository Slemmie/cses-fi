#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n, k; std::cin >> n >> k;
	std::vector <ll> a(k);
	for (ll& x: a) std::cin >> x;
	ll ans = 0;
	for (ll i = 0; i < (1LL << k); i++) {
		std::vector <ll> v;
		for (ll j = 0; j < k; j++) {
			if (i & (1LL << j)) {
				v.push_back(a[j]);
			}
		}
		ll p = 1;
		for (ll j = 0; j < (ll)v.size(); j++) {
			if (p > n / v[j]) {
				p = n + 1LL;
				break;
			}
			p *= v[j];
		}
		if ((ll)v.size() & 1LL) ans += n / p;
		else ans -= n / p;
	}
	std::cout << ans + n << "\n";
	
}
