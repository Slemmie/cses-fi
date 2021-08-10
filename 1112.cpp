#include <bits/stdc++.h>

constexpr int mod = 1000000007;
//constexpr int mod = 998244353;

constexpr bool prime_mod = true;

template <typename A> A inverse(A a, A b) {
	a %= b;
	if (!a) {
		return b == A(1) ? 0 : -1;
	}
	A c = inverse(b, a);
	return c == A(-1) ? -1LL :
	((1LL - (long long)b * (long long)c) / (long long)a + b) % b;
}

struct Mint {
	int value;
	explicit operator int() const { return value; }
	Mint(int _value = 0) : value(_value) { }
	template <typename B = int> Mint(const B& _value) {
		long long llvalue = _value;
		value = (-mod <= llvalue && llvalue <= mod) ? llvalue : llvalue % mod;
		value += value < 0 ? mod : 0;
	}
	friend bool operator == (const Mint& a, const Mint& b) {
		return a.value == b.value;
	}
	friend bool operator != (const Mint& a, const Mint& b) {
		return !(a == b);
	}
	friend bool operator < (const Mint& a, const Mint& b) {
		return a.value < b.value;
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
		if (value < 0) {
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
		if (prime_mod) {
			return pow(mint, mod - 2);
		}
		return inverse(mint.value, mod);
	}
	Mint& operator /= (const Mint& oth) {
		(*this) *= inv(oth);
		return *this;
	}
	Mint& operator ++ () {
		return *this += 1;
	}
	Mint& operator -- () {
		return *this -= 1;
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
	friend std::istream& operator >> (std::istream& stream, Mint& a) {
		stream >> a.value;
		return stream;
	}
	friend std::ostream& operator << (std::ostream& stream, const Mint& a) {
		stream << a.value;
		return stream;
	}
};

typedef Mint mi;

mi fac(long long x) {
	if (x < 0LL) {
		return 0;
	}
	static long long ready = 1;
	static std::vector <mi> factorial = { 1, 1 };
	if (x <= ready) {
		return factorial[x];
	}
	long long y = x + (x >> 4LL);
	factorial.resize(y + 1);
	for (long long i = ready + 1; i <= y; i++) {
		factorial[i] = factorial[i - 1] * i;
	}
	ready = y;
	return factorial[x];
}

mi inv_fac(long long x) {
	if (x < 0LL) {
		return 0;
	}
	static long long ready = 1;
	static std::vector <mi> inv_factorial = { 1, 1 };
	if (x <= ready) {
		return inv_factorial[x];
	}
	long long y = x + (x >> 4LL);
	inv_factorial.resize(y + 1);
	inv_factorial[y] = mi(1) / fac(y);
	for (long long i = y - 1; i > ready; i--) {
		inv_factorial[i] = inv_factorial[i + 1] * (i + 1);
	}
	ready = y;
	return inv_factorial[x];
}

mi choose(long long n, long long k) {
	if (k < 0LL || k > n) {
		return 0;
	}
	return fac(n) * inv_fac(k) * inv_fac(n - k);
}

int n, m;
std::string s;
int furth[101][27];
mi dp[101];

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> s;
	m = s.length();
	dp[0] = 1;
	for (int i = 0; i < m; i++) {
		std::string pref = s.substr(0, i);
		for (int j = 0; j < 26; j++) {
			std::string u = pref;
			u += 'A' + j;
			while (u != s.substr(0, u.size())) {
				u = u.substr(1, (int)u.size() - 1);
			}
			furth[i][j] = u.size();
		}
	}
	for (int i = 0; i < n; i++) {
		static mi dp2[101];
		memset(dp2, 0, sizeof(dp2));
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 26; k++) {
				dp2[furth[j][k]] += dp[j];
			}
		}
		dp2[m] = 0;
		for (int j = 0; j < 101; j++) {
			dp[j] = dp2[j];
		}
	}
	mi ans = pow(mi(26), n);
	for (int i = 0; i < m; i++) {
		ans -= dp[i];
	}
	std::cout << ans << "\n";
	
}
