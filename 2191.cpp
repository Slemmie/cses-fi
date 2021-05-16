#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::pair <ll, ll>> a(n + 1);
	for (int i = 0; i < n; i++) std::cin >> a[i].first >> a[i].second;
	a.back() = a.front();
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (a[i].first + a[i - 1].first) * (a[i].second - a[i - 1].second);
	if (!ans) std::cout << "0\n";
	else std::cout << ans * (ans < 0LL ? -1LL : 1LL) << "\n";
	
}
