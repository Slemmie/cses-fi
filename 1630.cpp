#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::pair <ll, ll>> a(n);
	for (auto& x : a) std::cin >> x.first >> x.second;
	std::sort(a.begin(), a.end());
	ll ans = 0;
	ll time = 0;
	for (const auto& x : a) {
		time += x.first;
		ans += x.second - time;
	}
	std::cout << ans << "\n";
	
}
