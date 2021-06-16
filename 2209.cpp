#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

ll pw(ll x, ll p) {
	ll r = 1;
	while (p) {
		if (p & 1LL) r = (r * x) % mod;
		p >>= 1LL;
		x = (x * x) % mod;
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n, m; std::cin >> n >> m;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll x = pw(m, std::gcd(i, n));
		x *= pw(n, mod - 2LL);
		ans += x % mod;
	}
	std::cout << ans % mod << "\n";
	
}
