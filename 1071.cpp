#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	
	int t; std::cin >> t;
	while (t--) {
		ll y, x; std::cin >> y >> x;
		ll mx = std::max(x, y);
		std::cout << ((mx - 1LL) * (mx - 1LL)) + mx * (x == y) + (mx & 1LL ? (x >= y ? mx * 2LL - y : x) : (y >= x ? mx * 2LL - x : y)) * (x != y) << "\n";
	}
	
}
