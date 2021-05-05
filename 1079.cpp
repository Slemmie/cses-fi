include <bits/stdc++.h>
 
typedef long long ll;
const ll mod = 1e9 + 7;
 
ll pow(ll x, ll p) {
	ll r = 1;
	p %= mod;
	while (p) {
		if (p & 1LL) r = (r * x) % mod;
		p >>= 1LL;
		x = (x * x) % mod;
	}
	return r;
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <ll> p1(1e6 + 5), p2(1e6 + 5);
	ll cnt = 1;
	for (int i = 0; i < 1e6 + 5; i++) {
		p1[i] = cnt;
		p2[i] = pow(cnt, ll(1e9 + 5));
		cnt = (cnt * (i + 1LL)) % mod;
	}
	while (n--) {
		ll a, b; std::cin >> a >> b;
		ll tmp = (p1[a] * p2[b]) % mod;
		ll ans = (tmp * p2[a - b]) % mod;
		std::cout << ans << "\n";
	}
	
}
