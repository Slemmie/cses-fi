#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::map <int, int> mp;
	long long ans = 0;
	for (int l = 0, r = 0; r < n; r++) {
		mp[a[r]]++;
		while (mp[a[r]] > 1) mp[a[l++]]--;
		ans += r - l + 1;
	}
	std::cout << ans << "\n";
}
