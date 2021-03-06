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

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int k, n, m; std::cin >> k >> n >> m;
	std::vector <int> a(k, 0), b(k, 0);
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x; x--;
		a[x]++;
	}
	for (int i = 0; i < m; i++) {
		int x; std::cin >> x; x--;
		b[x]++;
	}
	auto ans = mult(a, b);
	for (auto x : ans) {
		std::cout << x << " ";
	}
	std::cout << "\n";
	
}
