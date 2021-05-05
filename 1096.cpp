#include <bits/stdc++.h>
 
typedef long long ll;
const ll mod = 1e9 + 7;
 
std::vector <ll> p1 = { 0, 0, 0, 0, 0, 1 }, p2 = { 1, 1, 1, 1, 1, 1 };
 
std::vector <ll> mul(std::vector <ll> p3, std::vector <ll> p4) {
	ll n = 6;
	std::vector <ll> r(n * 2 + 1);
	for (ll i = 0; i <= n; i++)
		for (ll j = 0; j <= n; j++)
			r[i + j] = (r[i + j] + p3[i] * p4[j]) % mod;
	for (ll i = n * 2; i > n; i--)
		for (ll j = 0; j < n; j++)
			r[i - j - 1] = (r[i - j - 1] + r[i] * p2[j]) % mod;
	return std::vector <ll> (r.begin(), r.begin() + n + 1);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n; std::cin >> n; n += 6;
	std::vector <ll> p3(7, 0), p4(p3); p3[0] = 1, p4[1] = 1;
	while (n) {
		if (n & 1LL) p3 = mul(p3, p4);
		p4 = mul(p4, p4), n >>= 1LL;
	}
	ll ans = 0;
	for (ll i = 0; i < 6; i++) ans = (ans + p3[i + 1] * p1[i]) % mod;
	std::cout << ans << "\n";
	
}
