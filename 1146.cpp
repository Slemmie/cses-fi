#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n; std::cin >> n;
	ll ans = 0;
	for (ll i = 0; i <= 51; i++) {
		ll bit = 1LL << i;
		ll nxt = 1LL << (i + 1LL);
		ans += (n / nxt) * bit;
		if (n % nxt >= bit) ans += (n % nxt) + 1LL - bit;
	}
	std::cout << ans << "\n";
	
}
