#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::map <int, int> mp;
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		auto it = mp.upper_bound(p);
		if (it != mp.end()) {
			(*it).second--;
			if (!(*it).second) mp.erase(it);
		}
		mp[p]++;
	}
	int ans = 0;
	for (auto p : mp) ans += p.second;
	std::cout << ans << "\n";
	
}
