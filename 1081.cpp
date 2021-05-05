#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> a(1e6 + 1, 0);
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p; a[p]++;
	}
	for (int i = 1e6; i >= 1; i--) {
		int cnt = 0;
		for (int j = i; j <= 1e6; j += i) {
			cnt += a[j];
		}
		if (cnt > 1) {
			std::cout << i << "\n";
			return 0;
		}
	}
	
}
