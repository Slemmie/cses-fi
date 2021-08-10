#include <bits/stdc++.h>

const int mod = 1e9 + 7, b = 69;

struct Seg {
	
	int size;
	
	std::vector <int> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) size <<= 1;
		v.resize(size << 1, 0);
	}
	
	void set(int ind, int val) {
		set(ind, val, 0, 0, size);
	}
	
	void set(int ind, int val, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) set(ind, val, now * 2 + 1, l, mid);
		else set(ind, val, now * 2 + 2, mid, r);
		v[now] = (v[now * 2 + 1] + v[now * 2 + 2]) % mod;
	}
	
	int get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
	int get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return (get(tl, tr, now * 2 + 1, l, mid) + get(tl, tr, now * 2 + 2, mid, r)) % mod;
	}
	
};

int pw(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) r = (long long)r * x % mod;
		p >>= 1;
		x = (long long)x * x % mod;
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, q; std::cin >> n >> q;
	std::string s; std::cin >> s;
	Seg pre(n), suf(n);
	std::vector <int> p(n, 1), pp(n, 1);
	for (int i = 0; i < n; i++) {
		p[i] = (i ? (long long)p[i - 1] * b % mod : 1LL);
		pp[i] = pw(p[i], mod - 2);
	}
	for (int i = 0; i < n; i++) {
		pre.set(i, (long long)(s[i] - 'a' + 1) * p[i] % mod);
		suf.set(i, (long long)(s[i] - 'a' + 1) * p[n - i - 1] % mod);
	}
	while (q--) {
		int type; std::cin >> type;
		if (type == 1) {
			int k; char x; std::cin >> k >> x; k--;
			int v = x - 'a' + 1;
			pre.set(k, (long long)v * p[k] % mod);
			suf.set(k, (long long)v * p[n - k - 1] % mod);
		} else {
			int l, r; std::cin >> l >> r; l--;
			bool yes = (long long)pre.get(l, r) * pp[l] % mod == (long long)suf.get(l, r) * pp[n - r] % mod;
			std::cout << (yes ? "YES\n" : "NO\n");
		}
	}
	
}
