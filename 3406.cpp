#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::vector <ll> v;
	for (ll i = 1, j = 0; j < 1'000'000'000'005; i++) v.push_back(j += i);
	int t; std::cin >> t;
	while (t--) {
		ll n; std::cin >> n;
		ll ans = 3;
		for (int i = 0, j = (int) v.size() - 1; i < (int) v.size(); i++) {
			if (v[i] == n) { ans = 1; break; }
			while (j >= i && v[i] + v[j] > n) j--;
			if (v[i] + v[j] == n) { ans = 2; }
		}
		std::cout << ans << (char) 10;
	}
}
