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
	ll p = n & 1LL;
	n *= n;
	ll ans = pw(2, n);
	ans += 2LL * pw(2, (n + 3LL * p) / 4LL);
	ans += pw(2, (n + p) / 2LL);
	ans *= pw(4, mod - 2LL);
	ans %= mod;
	std::cout << ans << "\n";
	
}
