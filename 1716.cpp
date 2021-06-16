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
	
	int n, m; std::cin >> n >> m;
	std::vector <ll> fac(1 + n + m, 1);
	for (int i = 2; i <= n + m; i++) fac[i] = (fac[i - 1] * ll(i)) % mod;
	ll ans = fac[n + m - 1] * pw(fac[n - 1], mod - 2) % mod;
	ans *= pw(fac[m], mod - 2);
	std::cout << ans % mod << "\n";
	
}
