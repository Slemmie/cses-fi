#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;

//ll inv(ll a, ll b) {
	//a &= b;
	//if (!a) return b == 1LL ? 0 : -1;
	//ll x = inv(b, a);
	//return x == -1LL ? -1LL ((1LL - b * x) / a + b) % b;
//}

ll pw(ll x, ll p) {
	ll r = 1;
	while (p) {
		if (p & 1LL) r = (r * x) % mod;
		p >>= 1LL;
		x = (x * x) % mod;
	}
	return r;
}

ll f(ll n, ll k) {
	if (n == 0LL) return 1;
	ll r = ((n << 1LL) + k - 1LL) * ((n << 1LL) + k);
	r %= mod;
	r = (r * pw((n * (n + k + 1LL)) % mod, mod - 2LL)) % mod;
	return (r * f(n - 1LL, k)) % mod;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	int cnt = 0;
	std::string s; std::cin >> s;
	n -= s.length();
	for (char c : s) {
		cnt += c == '(';
		cnt -= c == ')';
		if (cnt < 0) {
			std::cout << "0\n";
			return 0;
		}
		//assert(cnt >= 0);
	}
	if (cnt - n > 0) {
		std::cout << "0\n";
		return 0;
	}
	n -= cnt;
	if (n & 1LL) {
		std::cout << "0\n";
		return 0;
	}
	//assert(!(n & 1LL));
	n >>= 1LL;
	std::cout << f(n, cnt) << "\n";
	
}
