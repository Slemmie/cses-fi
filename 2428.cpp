#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, k; std::cin >> n >> k;
	long long ans = 0;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::map <int, int> mp;
	int l = 0;
	for (int i = 0; i < n; i++) {
		if ((int)mp.size() == k && mp.find(a[i]) == mp.end()) {
			while ((int)mp.size() == k) {
				auto it = mp.find(a[l]);
				assert(it != mp.end());
				it->second--;
				if (!it->second) mp.erase(it);
				l++;
			}
		}
		mp[a[i]]++;
		long long sz = i - l + 1LL;
		ans += sz;
	}
	std::cout << ans << "\n";
	
}
