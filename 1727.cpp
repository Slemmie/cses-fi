#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, k; std::cin >> n >> k;
	double ans = 0;
	for (int i = 1; i <= k; i++) {
		double plus = 1, minus = 1;
		for (int j = 1; j <= n; j++) {
			plus *= double(i) / double(k);
			minus *= double(i - 1) / double(k);
		}
		ans += double(i) * plus - double(i) * minus;
	}
	ans *= 1e6;
	ans = roundeven(ans);
	ans /= 1e6;
	std::cout << std::fixed << std::setprecision(6) << ans << "\n";
	
}
