#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

ll inv(ll x) {
	if (x == 1LL) return 1;
	return (mod - ((mod / x) * inv(mod % x)) % mod + mod) % mod;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n; std::cin >> n;
	ll ans = 0;
	for (ll i = 1; i * i <= n; i++) ans = (ans + ((n / i) * i)) % mod;
	ll sq = sqrt(n);
	for (ll i = sqrt(n); i; i--) {
		ll r = n / i, sum = ((((r % mod) * ((r + 1LL) % mod)) % mod) * inv(2)) % mod;
		sum %= mod;
		sum -= ((((sq % mod) * ((sq + 1LL) % mod)) % mod) * inv(2)) % mod;
		sum += mod;
		sum %= mod;
		sum *= i;
		sum %= mod;
		ans += sum;
		ans %= mod;
		sq = r;
	}
	std::cout << ans << "\n";
	
}
