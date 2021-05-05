#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;

tree <int, int, std::less <int>, rb_tree_tag, tree_order_statistics_node_update> t;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		t[i] = x;
	}
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x; x--;
		auto it = t.find_by_order(x);
		std::cout << it->second << " \n"[i == n - 1];
		t.erase(it);
	}
	
}
