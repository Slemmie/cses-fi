#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n; std::cin >> n;
	std::map <ll, ll> mp = { { 0, 1 } };
	ll ans = 0;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		ll p; std::cin >> p;
		sum += p;
		sum = (sum % n + n) % n;
		if (mp.count(sum)) ans += mp[sum];
		mp[sum]++;
	}
	std::cout << ans << "\n";
	
}
