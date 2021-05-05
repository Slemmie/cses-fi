#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, x; std::cin >> n >> x;
	std::vector <int> a(n);
	for (int& y : a) std::cin >> y;
	int sum = 0, ans = 0, l = 0, r = 0;
	for (; r < n; r++) {
		sum += a[r];
		while (sum > x) sum -= a[l++];
		ans += sum == x;
	}
	std::cout << ans << "\n";
	
}
