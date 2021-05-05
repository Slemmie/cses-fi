#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, k; std::cin >> n >> k;
	std::map <int, std::vector <int>> mp;
	std::map <int, int> t;
	t[0] += k;
	for (int i = 0; i < n; i++) {
		int l, r; std::cin >> l >> r;
		mp[r].push_back(l);
	}
	for (auto& p : mp) std::sort(p.second.begin(), p.second.end());
	int ans = 0;
	for (auto p : mp) {
		while (p.second.size()) {
			int s = p.second.back();
			p.second.pop_back();
			auto it = t.upper_bound(s);
			if (it == t.begin()) continue;
			it--;
			if (it->first <= s) {
				ans++;
				it->second--;
				t[p.first]++;
				if (!it->second) t.erase(it);
			}
		}
	}
	std::cout << ans << "\n";
	
}
