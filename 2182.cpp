#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

ll inv(ll x) {
	if (x == 1LL) return 1;
	return (mod - ((mod / x) * inv(mod % x)) % mod + mod) % mod;
}

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
	std::vector <ll> a(n), k(n);
	for (ll i = 0; i < n; i++) std::cin >> a[i] >> k[i];
	ll m = 1;
	for (ll i = 0; i < n; i++) m = (m * (k[i] + 1LL)) % mod;
	ll sum = 1;
	for (ll i = 0; i < n; i++) {
		ll now = (pw(a[i], k[i] + 1LL) + mod - 1LL) % mod;
		now = (now * inv(a[i] - 1LL)) % mod;
		sum = (sum * now) % mod;
	}
	ll oth = 1;
	bool fl = false;
	for (ll i = 0; i < n; i++) {
		if ((k[i] & 1LL) && !fl) {
			oth = (oth * ((k[i] + 1LL) >> 1LL)) % (mod - 1LL);
			fl = true;
		} else {
			oth = (oth * (k[i] + 1LL)) % (mod - 1LL);
		}
	}
	if (!fl) for (ll i = 0; i < n; i++) k[i] >>= 1LL;
	ll num = 1;
	for (ll i = 0; i < n; i++) {
		num = (num * pw(a[i], k[i])) % mod;
	}
	std::cout << m << " " << sum << " " << pw(num, oth) << "\n";
	
}
