#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
int n;
ll x;
std::vector <ll> a, dp;
 
ll f(ll now) {
	if (now >= x) return now == x;
	if (dp[now] != -1) return dp[now];
	dp[now] = 0;
	for (ll y : a) dp[now] += f(now + y), dp[now] %= mod;
	return dp[now];
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> x;
	a.resize(n);
	dp.resize(x, -1);
	for (ll& y : a) std::cin >> y;
	std::cout << f(0) << "\n";
	
}
