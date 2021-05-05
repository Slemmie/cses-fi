#include <bits/stdc++.h>

int n;
std::vector <std::vector <int>> dp;

const long long mod = 1e9 + 7;

long long f(int i, int need) {
	if (need < 0) return 0;
	if (need == 0) return 1;
	if (i == n) return 0;
	if (dp[i][need] != -1) return dp[i][need];
	return dp[i][need] = (f(i + 1, need - (i + 1)) + f(i + 1, need)) % mod;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n;
	if ((n * (n + 1)) % 4) {
		std::cout << "0\n";
		return 0;
	}
	dp.resize(n, std::vector <int> (((n * (n + 1)) >> 2) + n, -1));
	long long ans = (long long)f(0, (n * (n + 1)) >> 2);
	ans *= mod + 1LL;
	ans >>= 1;
	std::cout << ans % mod << "\n";
	
}
