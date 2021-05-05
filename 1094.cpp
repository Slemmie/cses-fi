#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	
	int n; std::cin >> n;
	int prv = 0;
	ll ans = 0;
	while (n--) {
		int p; std::cin >> p;
		ans += std::max(0, prv - p);
		prv = std::max(prv, p);
	}
	std::cout << ans << "\n";
	
}
