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
	
	ll n; std::cin >> n;
	if (n & 1LL) {
		std::cout << "0\n";
		return 0;
	}
	std::pair <ll, ll> f = { 1, 1 };
	for (ll i = 1; i <= n; i++) {
		f.first = (f.first * i) % mod;
	}
	for (ll i = 1; i <= (n >> 1LL); i++) {
		f.second = (f.second * i) % mod;
	}
	f.second = (f.second * f.second) % mod;
	f.second = (f.second * ((n >> 1LL) + 1LL)) % mod;
	std::cout << (f.first * pw(f.second, mod - 2LL)) % mod << "\n";
	
}
