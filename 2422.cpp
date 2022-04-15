#include <bits/stdc++.h>

long long get(long long mid, long long n) {
	long long res = 0;
	for (long long i = 1; i <= n; i++) {
		res += std::min(n, mid / i);
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	long long n; std::cin >> n;
	long long l = 1, r = n * n, best = 1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		long long lesseq = get(mid, n);
		if (lesseq <= n * n / 2) {
			best = mid + 1;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	std::cout << best << "\n";
	
}
