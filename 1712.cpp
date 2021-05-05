#include <bits/stdc++.h>
 
typedef long long ll;
 
ll pow(ll a, ll p, ll mod) {
	ll r = 1;
	while (p) {
		if (p & 1LL) r = (r * a) % mod;
		p >>= 1LL;
		a = (a * a) % mod;
	}
	return r;
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) {
		ll a, b, c; std::cin >> a >> b >> c;
		std::cout << pow(a, pow(b, c, 1e9 + 6), 1e9 + 7) << "\n";
	}
	
}
