#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n, tar; std::cin >> n >> tar;
	std::vector <ll> a(n);
	for (ll& x : a) std::cin >> x;
	ll ans = 0;
	std::map <ll, ll> mp;
	mp[0]++;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		sum += a[i];
		ans += mp[sum - tar];
		mp[sum]++;
	}
	std::cout << ans << "\n";
	
}
