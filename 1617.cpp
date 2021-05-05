#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll MOD = 1e9 + 7;
 
int main() {
	
	ll n, ans = 1LL, two = 2LL; std::cin >> n;
	while (n) {
		if (n & 1LL) ans = (ans * two) % MOD;
		two = (two * two) % MOD;
		n >>= 1LL;
	}
	std::cout << ans << "\n";
	
}
