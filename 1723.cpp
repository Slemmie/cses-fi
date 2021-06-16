#include <bits/stdc++.h>

constexpr int mod = 1'000'000'007;
//constexpr int mod = 998'244'353;

template <typename A> A inverse(A a, A b) {
	a %= b;
	if (!a) {
		return b == A(1) ? 0 : -1;
	}
	A c = inverse(b, a);
	return c == A(-1) ? -1LL :
	((1LL - (long long)b * (long long)c) / (long long)a + b) % b;
}

template <typename A = int> struct Mint {
	A value;
	Mint(A _value = 0) : value(_value) { }
	template <typename B = int> Mint(const B& _value) {
		value = (-mod <= _value && value <= mod) ? _value : _value % mod;
		value += value < A(0) ? mod : 0;
	}
	operator A() const { return value; }
	friend bool operator == (const Mint& a, const Mint& b) {
		return a.value == b.value;
	}
	friend bool operator != (const Mint& a, const Mint& b) {
		return !(a == b);
	}
	Mint operator - () const { return Mint(-value); }
	Mint& operator += (const Mint& oth) {
		value += oth.value;
		if (value >= mod) {
			value -= mod;
		}
		return *this;
	}
	Mint& operator -= (const Mint& oth) {
		value -= oth.value;
		if (value < A(0)) {
			value += mod;
		}
		return *this;
	}
	Mint& operator *= (const Mint& oth) {
		value = (long long)value * (long long)oth.value % (long long)mod;
		return *this;
	}
	friend Mint pow(Mint mint, long long p) {
		Mint ret = 1;
		while (p) {
			if (p & 1LL) {
				ret *= mint;
			}
			p >>= 1LL;
			mint *= mint;
		}
		return ret;
	}
	friend Mint inv(const Mint& mint) {
		return inverse(mint.value, mod);
	}
	Mint& operator /= (const Mint& oth) {
		(*this) *= inv(oth);
		return *this;
	}
	friend Mint operator + (Mint a, const Mint& b) {
		return a += b;
	}
	friend Mint operator - (Mint a, const Mint& b) {
		return a -= b;
	}
	friend Mint operator * (Mint a, const Mint& b) {
		return a *= b;
	}
	friend Mint operator / (Mint a, const Mint& b) {
		return a /= b;
	}
};

typedef Mint <int> mi;

int n, m, p;
std::vector <std::vector <mi>> g;

std::vector <std::vector <mi>> mul(const std::vector <std::vector <mi>>& a, const std::vector <std::vector <mi>>& b) {
	std::vector <std::vector <mi>> r(n, std::vector <mi> (n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				r[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return r;
}

std::vector <std::vector <mi>> pw(std::vector <std::vector <mi>> x) {
	std::vector <std::vector <mi>> r(n, std::vector <mi> (n, 0));
	for (int i = 0; i < n; i++) r[i][i] = 1;
	while (p) {
		if (p & 1) {
			r = mul(r, x);
		}
		p >>= 1;
		x = mul(x, x);
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m >> p;
	g.resize(n, std::vector <mi> (n, 0));
	for (int i = 0; i < m; i++) {
		int u, v; std::cin >> u >> v; u--, v--;
		g[u][v] += 1;
	}
	std::cout << pw(g)[0][n - 1] << "\n";
	
}
