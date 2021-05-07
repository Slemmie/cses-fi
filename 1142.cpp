#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::set <int> st;
	int n; std::cin >> n;
	st.insert(0);
	st.insert(n + 1);
	std::vector <std::pair <int, int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i].second = i + 1;
		std::cin >> a[i].first;
	}
	std::sort(a.begin(), a.end());
	long long ans = 0;
	for (auto p : a) {
		int h = p.first;
		int i = p.second;
		auto it = st.upper_bound(i);
		int r = *it;
		int l = *(--it);
		ans = std::max(ans, (long long)(r - l - 1) * (long long)h);
		st.insert(i);
	}
	std::cout << ans << "\n";
	
}
