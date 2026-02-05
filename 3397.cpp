#include <bits/stdc++.h>

typedef long long ll;

ll fac[21];

void test() {
	int t; std::cin	>> t;
	if (t == 1) {
		int n; ll k; std::cin >> n >> k;
		std::vector <int> ans(n, -1);
		std::vector <int> remain;
		for (int i = 0; i < n; i++) remain.push_back(i);
		for (int i = 0; i < n; i++) {
			for (int j = (int) remain.size() - 1; j >= 0; j--) {
				if (fac[n - i - 1] * j < k) {
					ans[i] = remain[j];
					remain.erase(remain.begin() + j);
					k -= fac[n - i - 1] * j;
					break;
				}
			}
		}
		for (int x : ans) std::cout << x + 1 << " ";
		std::cout << (char) 10;
	} else {
		int n; std::cin >> n;
		std::vector <int> a(n);
		for (int& x : a) std::cin >> x, x--;
		ll ans = 1;
		std::vector <int> remain;
		for (int i = 0; i < n; i++) remain.push_back(i);
		for (int i = 0; i < n; i++) {
			for (int j = (int) remain.size() - 1; j >= 0; j--) {
				if (a[i] == remain[j]) {
					ans += fac[n - i - 1] * j;
					remain.erase(remain.begin() + j);
					break;
				}
			}
		}
		std::cout << ans << (char) 10;
	}
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	fac[0] = 1;
	for (int i = 1; i < 21; i++) fac[i] = fac[i - 1] * i;
	int t; std::cin >> t; while (t--) test();
}
