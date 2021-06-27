#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int b = 69;

int pw(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) r = (long long)x * r % mod;
		p >>= 1;
		x = (long long)x * x % mod;
	}
	return r;
}

int prefix(const std::vector <int>& v, int l, int r) {
	return (v[r] - (l - 1 >= 0 ? v[l - 1] : 0) + mod) % mod;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::string s; std::cin >> s;
	int n = s.length();
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = ((long long)(s[i] - 'a' + 1) * pw(b, i) + (i ? v[i - 1] : 0)) % mod;
	}
	std::vector <int> p(n + 1, 1);
	long long ex = 1;
	for (int i = 0; i <= n; i++) {
		p[i] = ex;
		ex = ex * b % mod;
	}
	for (int i = 1; i <= n; i++) {
		bool ok = true;
		int pref = i;
		while (pref <= (n >> 1)) {
			ok &= int((long long)prefix(v, 0, pref - 1) * p[pref] % mod) == prefix(v, pref, pref + pref - 1);
			pref <<= 1;
		}
		int suf = n % pref;
		if (suf) ok &= int((long long)prefix(v, 0, suf - 1) * p[n - suf] % mod) == prefix(v, n - suf, n - 1);
		if (ok) std::cout << i << " ";
	}
	std::cout << "\n";
	
}
