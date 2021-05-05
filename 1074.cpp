#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	ll ans = 0;
	for (int x : a) ans += abs(x - a[n / 2]);
	std::cout << ans << "\n";
	
}
