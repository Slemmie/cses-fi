#include <bits/stdc++.h>

typedef long long ll;

ll pw(ll b, ll e, ll m) {
	ll r = 1;
	for (; e; e >>= 1) {
		if (e & 1) r = (__int128_t) r * b % m;
		b = (__int128_t) b * b % m;
	}
	return r;
}

bool is(ll n) {
	for (ll p : { 2, 3, 5, 7, 11, 13 }) if (n % p == 0) return n == p;
	ll d = n - 1, s = 0;
	while (~d & 1) { d >>= 1; s++; }
	auto wit = [&] (ll v) {
		ll x = pw(v, d, n);
		if (x == 1 || x == n - 1) return false;
		for (ll r = 1; r < s; r++) {
			x = (__int128_t) x * x % n;
			if (x == n - 1) return false;
		}
		return true;
	};

	for (ll x : { 2, 3, 5, 7, 11, 13 }) if (wit(x)) return false;
	return true;
}

int main() {
	int t; std::cin >> t;
	while (t--) {
		ll n; std::cin >> n;
		while (!is(++n));
		std::cout << n << (char) 10;
	}
}
