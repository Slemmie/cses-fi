#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;

using ordered_set = tree <int, null_type, std::less <int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> pre(n, 0);
	std::vector <int> a(n);
	for (int& x : a) {
		std::cin >> x;
	}
	ordered_set st;
	for (int i = 0; i < n; i++) {
		pre[i] = st.order_of_key(-a[i]);
		st.insert(-a[i]);
	}
	long long ans = 0;
	st.clear();
	for (int i = n - 1; ~i; i--) {
		ans += std::min((int) st.order_of_key(-a[i]), pre[i]);
		st.insert(-a[i]);
	}
	std::cout << ans << "\n";
	
}
