#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::pair <int, int>> a(n);
	for (auto& x : a) std::cin >> x.second >> x.first;
	std::sort(a.begin(), a.end());
	int ans = 0;
	int time = -INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i].second >= time) {
			time = a[i].first;
			ans++;
		}
	}
	std::cout << ans << "\n";
	
}
