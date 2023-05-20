#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) {
		std::cin >> x;
	}
	long double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += (long double) (a[i] - 1 <= a[j] ? a[i] * (a[i] - 1) / 2 : a[j] * ((a[j] + 1) + (a[i] - a[j] - 1) * 2) / 2) / (a[i] * a[j]);
		}
	}
	std::cout << std::fixed << std::setprecision(6) << (double) ans << "\n";
}
