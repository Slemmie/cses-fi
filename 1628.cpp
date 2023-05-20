#include <bits/stdc++.h>

std::vector <long long> get(std::vector <int> a) {
	int n = a.size();
	std::vector <long long> res;
	for (int mask = 1; mask < (1 << n); mask++) {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i] * (mask >> i & 1);
		}
		res.push_back(sum);
	}
	std::sort(res.begin(), res.end());
	return res;
}

int main() {
	int n, k; std::cin >> n >> k;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	auto s1 = get(std::vector <int> (a.begin(), a.begin() + n / 2));
	auto s2 = get(std::vector <int> (a.begin() + n / 2, a.end()));
	long long ans = 0;
	for (int i = 0, j = (int) s2.size() - 1; i < (int) s1.size() && j >= 0; i++) {
		while (j >= 0 && s1[i] + s2[j] > (long long) k) {
			j--;
		}
		if (j < 0) {
			break;
		}
		int weight = 1;
		while (i + 1 < (int) s1.size() && s1[i] == s1[i + 1]) {
			i++;
			weight++;
		}
		while (j >= 0 && s1[i] + s2[j] == (long long) k) {
			ans += weight;
			j--;
		}
	}
	for (int x : s1) {
		ans += x == k;
	}
	for (int x : s2) {
		ans += x == k;
	}
	std::cout << ans << "\n";
}
