#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, q; std::cin >> n >> q;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::vector <std::vector <std::pair <int, int>>> qu(n);
	for (int i = 0; i < q; i++) {
		int l, r; std::cin >> l >> r;
		qu[--l].emplace_back(i, --r);
	}
	std::vector <int> ans(q);
	std::deque <int> act;
	for (int i = n - 1; i >= 0; i--) {
		while (act.size() && a[act.front()] <= a[i]) act.pop_front();
		act.push_front(i);
		for (auto [j, r] : qu[i]) ans[j] = std::upper_bound(act.begin(), act.end(), r) - act.begin();
	}
	for (int x : ans) std::cout << x << "\n";
}
