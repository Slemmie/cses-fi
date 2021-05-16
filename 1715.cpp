#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

ll pow(ll x, ll p) {
	ll r = 1;
	p %= mod;
	while (p) {
		if (p & 1LL) r = (r * x) % mod;
		p >>= 1LL;
		x = (x * x) % mod;
	}
	return r;
}

constexpr int N = 1e6 + 5;

std::vector <ll> p1(N), p2(N);

void prep() {
	ll cnt = 1;
	for (int i = 0; i < N; i++) {
		p1[i] = cnt;
		p2[i] = pow(cnt, mod - 2LL);
		cnt = (cnt * (i + 1LL)) % mod;
	}
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	prep();
	std::string s; std::cin >> s;
	ll n = s.length();
	std::vector <ll> f(26, 0);
	for (char c : s) f[c - 'a']++;
	ll ans = 1;
	for (ll x : f) if (x) {
		ans *= (((p1[n] * p2[x]) % mod) * p2[n - x]) % mod;
		ans %= mod;
		n -= x;
	}
	std::cout << ans << "\n";
	
}
