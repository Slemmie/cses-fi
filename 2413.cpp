#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
const int N = 1e6 + 3;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::vector <std::vector <ll>> dp(N, std::vector <ll> (2, 0));
	dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i < N - 1; i++) {
		dp[i][0] = dp[i - 1][0] * 2LL + dp[i - 1][1];
		dp[i][1] = dp[i - 1][1] * 4LL + dp[i - 1][0];
		dp[i][0] %= mod;
		dp[i][1] %= mod;
	}
	
	int t; std::cin >> t;
	while (t--) {
		int x; std::cin >> x;
		std::cout << (dp[x - 1][0] + dp[x - 1][1]) % mod << "\n";
	}
	
}
