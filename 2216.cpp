#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, ans = 0; std::cin >> n;
	std::vector <bool> a(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		ans += !a[p - 1];
		a[p] = 1;
	}
	std::cout << ans << "\n";
	
}
