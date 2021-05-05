#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n;
	ll x;
	std::cin >> n >> x;
	std::vector <ll> dp(x + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		ll now; std::cin >> now;
		for (int j = now; j <= x; j++) dp[j] = dp[j] + dp[j - now], dp[j] %= mod;
	}
	std::cout << dp[x] << "\n";
	
}
