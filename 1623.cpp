#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	
	int n; std::cin >> n;
	ll ans = 1e10, sum = 0;
	std::vector <ll> a(n);
	for (ll& x : a) std::cin >> x, sum += x;
	for (int i = 0; i < (1 << n); i++) {
		ll now = 0;
		for (int j = 0; j < n; j++) if ((i >> j) & 1) now += a[j];
		ans = std::min(ans, (ll)abs(now - (ll)abs(sum - now)));
	}
	std::cout << ans << "\n";
	
}
