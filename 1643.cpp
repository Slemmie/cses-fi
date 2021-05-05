#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	ll mx = -1e18;;
	std::vector <ll> a(n);
	for (ll& x : a) {
		std::cin >> x;
		mx = std::max(mx, x);
	}
	ll he = -1e18, s = 0;
	for (int i = 0; i < n; i++) {
		s = s + a[i];
		he = std::max(he, s);
		s = std::max(0LL, s);
	}
	std::cout << he << "\n";
	
}
