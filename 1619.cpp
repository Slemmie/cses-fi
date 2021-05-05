#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::pair <int, bool>> a;
	for (int i = 0; i < n; i++) {
		int q, w; std::cin >> q >> w;
		a.push_back({ q, 1 });
		a.push_back({ w, 0 });
	}
	std::sort(a.begin(), a.end());
	int ans = 0;
	int now = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		now += a[i].second;
		now -= !a[i].second;
		ans = std::max(ans, now);
	}
	std::cout << ans << "\n";
	
}
