#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t, n; std::cin >> t >> n;
	std::multiset <int> st;
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		st.insert(x);
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int val;
		ans += val = *st.begin() + *next(st.begin());
		st.erase(st.begin());
		st.erase(st.begin());
		st.insert(val);
	}
	std::cout << ans << "\n";
	
}
