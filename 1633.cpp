#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
std::vector <ll> dp;
 
ll f(ll now, ll targ) {
	if (now >= targ) return now == targ;
	if (dp[now] != -1) return dp[now];
	ll r = 0;
	for (ll i = 1; i <= 6; i++) r += f(now + i, targ);
	r %= mod;
	dp[now] = r;
	return r;
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n; std::cin >> n;
	dp.resize(n, -1);
	std::cout << f(0, n) << "\n";
	
}
