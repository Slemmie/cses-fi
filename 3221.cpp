#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, k; std::cin >> n >> k;
	std::vector <int> a(n);
	std::cin >> a[0];
	{
		int x, y, z; std::cin >> x >> y >> z;
		for (int i = 1; i < n; i++) {
			a[i] = ((long long) x * a[i - 1] + y) % z;
		}
	}
	int ans = 0;
	std::deque <std::pair <int, int>> win;
	auto insert = [&] (int i) {
		while (win.size() && win.back().first >= a[i]) win.pop_back();
		win.emplace_back(a[i], i);
	};
	auto erase = [&] (int i) {
		while (win.size() && win.front().second <= i) win.pop_front();
	};
	for (int l = 0, r = 0; r < n; l++) {
		while (r - l < k && r < n) insert(r++);
		ans ^= win.front().first;
		erase(l);
	}
	std::cout << ans << (char) 10;
}
