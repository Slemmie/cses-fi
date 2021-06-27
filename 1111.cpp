#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int b = 69;

int pw(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) r = (long long)r * x % mod;
		p >>= 1;
		x = (long long)x * x % mod;
	}
	return r;
}

int n;
std::vector <int> pre, suf;
std::vector <int> pwpw;

bool match(int l1, int r1, int l2, int r2) {
	if (l1 > l2) std::swap(l1, l2), std::swap(r1, r2);
	int valpre = (pre[r1] - (l1 ? pre[l1 - 1] : 0) + mod) % mod;
	int valsuf = (suf[l2] - (r2 + 1 < n ? suf[r2 + 1] : 0) + mod) % mod;
	valpre = (long long)valpre * pwpw[l1] % mod;
	valsuf = (long long)valsuf * pwpw[n - r2 - 1] % mod;
	return valpre == valsuf;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::string s; std::cin >> s;
	n = s.length();
	pwpw.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		pwpw[i] = pw(pw(b, i), mod - 2);
	}
	pre.resize(n);
	suf.resize(n);
	pre[0] = s[0] - 'a' + 1;
	suf[n - 1] = s[n - 1] - 'a' + 1;
	for (int i = 1; i < n; i++) {
		pre[i] = ((long long)(s[i] - 'a' + 1) * pw(b, i) + pre[i - 1]) % mod;
	}
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = ((long long)(s[i] - 'a' + 1) * pw(b, n - i - 1) + suf[i + 1]) % mod;
	}
	int best = 0;
	std::pair <int, int> ans = { 0, 0 };
	int best2 = -1;
	std::pair <int, int> ans2 = { -1, -1 };
	std::vector <int> order(n - 1);
	for (int i = 0; i < n - 1; i++) {
		order[i] = ((n - 1) >> 1) + (((1 - ((i & 1) << 1)) * (i + 1)) >> 1);
	}
	for (int x = 0; x < n - 1; x++) {
		int i = order[x];
		int l = 0, r = std::min(i, n - i - 1);
		int opt = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (match(i - mid, i, i, i + mid)) {
				opt = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
			if (r <= best) break;
		}
		if (s[i] == s[i + 1]) {
			l = 0, r = std::min(i, n - (i + 1) - 1);
			int opt1 = 0;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (match(i - mid, i, i + 1, i + 1 + mid)) {
					opt1 = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
				if (r <= best2) break;
			}
			if (opt1 > best2) {
				best2 = opt1;
				ans2 = { i - opt1, i + 1 + opt1 };
			}
		}
		if (opt > best) {
			best = opt;
			ans = { i - opt, i + opt };
		}
	}
	if (best2 >= best) std::swap(ans, ans2);
	for (int i = ans.first; i <= ans.second; i++) {
		std::cout << s[i];
	}
	std::cout << "\n";
	
}
