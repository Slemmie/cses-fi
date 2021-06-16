#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			ans += double(a[j] > a[i] ? ((a[i] *(a[i] - 1)) >> 1) + (a[j] - a[i]) * a[i] : (a[j] * (a[j] - 1)) >> 1) / double(a[i] * a[j]);
		}
	}
	ans *= 1e6;
	ans = llround(ans);
	ans /= 1e6;
	std::cout << std::fixed << std::setprecision(6) << ans << "\n";
	
}
