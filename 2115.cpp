#include <bits/stdc++.h>

void fft(std::vector <std::complex <double>>& input) {
	const int size = input.size();
	
	static std::vector <std::complex <double>> roots(size, 1);
	for (static int i = 2; i < size; i <<= 1) {
		static constexpr double pi = std::acos(-1.0);
		std::complex <double> angle = std::polar(1.0, pi / (double) i);
		roots.resize(i << 1);
		for (int j = i; j < (i << 1); j++) {
			roots[j] = roots[j >> 1] * ((j & 1) ? angle : 1.0);
		}
	}
	
	const int leading = 31 - __builtin_clz(size);
	
	std::vector <int> reverse(size, 0);
	for (int i = 0; i < size; i++) {
		reverse[i] = (reverse[i >> 1] | ((i & 1) << leading)) >> 1;
	}
	
	for (int i = 0; i < size; i++) {
		if (i < reverse[i]) {
			std::swap(input[i], input[reverse[i]]);
		}
	}
	
	for (int i = 1; i < size; i <<= 1) {
		for (int j = 0; j < size; j += (i << 1)) {
			for (int k = 0; k < i; k++) {
				std::complex <double> delta = roots[i + k] * input[i + j + k];
				input[i + j + k] = input[j + k] - delta;
				input[j + k] += delta;
			}
		}
	}
}

std::vector <long long> mult(const std::vector <int>& u, const std::vector <int>& v) {
	int leading = 32 - __builtin_clz(u.size() + v.size() - 1);
	int size = 1 << leading;
	std::vector <std::complex <double>> a(size), b(size);
	for (int i = 0; i < (int) u.size(); i++) {
		a[i].real(u[i]);
	}
	for (int i = 0; i < (int) v.size(); i++) {
		a[i].imag(v[i]);
	}
	fft(a);
	for (int i = 0; i < size; i++) {
		a[i] *= a[i];
	}
	for (int i = 0; i < size; i++) {
		b[i] = a[-i & (size - 1)] - std::conj(a[i]);
	}
	fft(b);
	std::vector <long long> res(u.size() + v.size() - 1);
	for (int i = 0; i < (int) res.size(); i++) {
		res[i] = std::round(b[i].imag() / (size << 2));
	}
	return res;
}

std::string s;
int n;

std::vector <long long> ans;

void f(int l, int r) {
	if (l > r) {
		return;
	}
	int m = r - l + 1;
	if (m < 20) {
		for (int i = l; i <= r; i++) {
			int one = 0;
			for (int j = i; j <= r; j++) {
				one += s[j] == '1';
				ans[one]++;
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	int mid1 = mid + 1;
	f(l, mid);
	f(mid1, r);
	std::vector <int> vl(1, 0);
	for (int i = mid; i >= l; i--) {
		if (s[i] == '1') {
			vl.resize(vl.size() + 1, 0);
		}
		vl.back()++;
	}
	std::vector <int> vr(1, 0);
	for (int i = mid1; i <= r; i++) {
		if (s[i] == '1') {
			vr.resize(vr.size() + 1, 0);
		}
		vr.back()++;
	}
	auto v = mult(vl, vr);
	for (int i = 0; i < (int) v.size(); i++) {
		ans[i] += v[i];
	}
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> s;
	n = s.size();
	ans.resize(n + 1, 0);
	f(0, n - 1);
	for (int i = 0; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
	}
	
}
