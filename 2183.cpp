#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <ll> a(n);
	for (ll& x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	ll sum = 1;
	if (a[0] != 1LL) {
		std::cout << "1\n";
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (sum + 1LL >= a[i]) {
			sum += a[i];
		} else {
			std::cout << sum + 1LL << "\n";
			return 0;
		}
	}
	std::cout << sum + 1 << "\n";
	
}
