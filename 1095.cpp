#include <bits/stdc++.h>
 
typedef long long ll;
 
ll mod = 1e9 + 7;
 
ll pow(ll a, ll p) {
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
		ll a, b; std::cin >> a >> b;
		std::cout << pow(a, b) << "\n";
	}
	
}
