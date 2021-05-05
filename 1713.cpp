#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::vector <int> ans(1e6 + 3, 0);
	for (int i = 1; i < 1e6 + 2; i++) for (int j = i; j < 1e6 + 2; j += i) ans[j]++;
	
	int t; std::cin >> t;
	while (t--) {
		int x; std::cin >> x;
		std::cout << ans[x] << "\n";
	}
	
}
