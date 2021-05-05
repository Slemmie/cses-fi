#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <ll> a(n);
	for (ll& x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	
	ll cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		cnt += a[i];
		if (cnt >= a.back()) break;
	}
	if (cnt < a.back()) {
		std::cout << a.back() * 2 << "\n";
	} else {
		ll ans = 0;
		for (ll x : a) ans += x;
		std::cout << ans << "\n";
	}
	
}
