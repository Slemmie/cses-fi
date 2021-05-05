#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

int n, k;

using namespace __gnu_pbds;

tree <int, null_type, std::less <int>, rb_tree_tag, tree_order_statistics_node_update> st;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) st.insert(i);
	int ind = k;
	for (int i = 0; i < n; i++) {
		ind %= st.size();
		int x = *st.find_by_order(ind);
		st.erase(x);
		std::cout << x << " \n"[i == n - 1];
		ind += k;
	}
	
}
