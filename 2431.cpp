#include <bits/stdc++.h>
 
typedef long long ll;
 
ll rev(ll x) {
	ll r = 0;
	while (x) {
		r = r * 10LL + (x % 10LL);
		x /= 10LL;
	}
	return r;
}
 
void test() {
	
	ll k; std::cin >> k;
	ll cnt1 = 9, cnt2 = 1;
	for (ll i = 1; true; i++) {
		if (i * cnt1 >= k) {
			ll now = (--k) / i + cnt2;
			now = rev(now);
			for (ll j = 0; j < k % i; j++) now /= 10LL;
			std::cout << now % 10LL << "\n";
			return;
		} else k -= i * cnt1;
		cnt1 *= 10LL, cnt2 *= 10LL;
	}
	
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; std::cin >> t;
	while (t--) test();
	
}
