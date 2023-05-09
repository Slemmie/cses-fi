#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	__float128 ans = 1e-15;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			ans += a[j] > a[i] ? 1 + (__float128) (a[i] - 1) / (2.0 * a[j]) - (__float128) a[i] / a[j] : (__float128) (a[j] - 1) / (2.0 * a[i]);
		}
	}
	std::cout << std::fixed << std::setprecision(6) << (long double) ans << "\n";
}
