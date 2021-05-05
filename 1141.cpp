#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::set <int> st;
	int ans = 0;
	int l = 0, r = 0;
	for (; r < n; r++) {
		if (st.count(a[r])) {
			while (st.count(a[r])) {
				st.erase(a[l++]);
			}
		}
		st.insert(a[r]);
		ans = std::max(ans, r - l + 1);
	}
	std::cout << ans << "\n";
	
}
