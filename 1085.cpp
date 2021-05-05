#include <bits/stdc++.h>

typedef long long ll;

int n, k;
std::vector <ll> a;

bool go(ll mx) {
	ll sum = 0;
	int use = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > mx) return false;
		sum += a[i];
		if (sum > mx) {
			use++;
			sum = a[i];
		}
	}
	return use <= k;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> k;
	a.resize(n);
	for (ll& x : a) std::cin >> x;
	ll l = 1LL, r = ll(1e9) * ll(n);
	ll best = l;
	while (l <= r) {
		ll mid = (l + r) >> 1LL;
		if (go(mid)) {
			best = mid;
			r = mid - 1LL;
		} else {
			l = mid + 1LL;
		}
	}
	std::cout << best << "\n";
	
}
