#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, k; std::cin >> n >> k;
	std::vector <int> a(n);
	std::cin >> a[0];
	{
		int x, y, z; std::cin >> x >> y >> z;
		for (int i = 1; i < n; i++) {
			a[i] = ((long long) x * a[i - 1] + y) % z;
		}
	}
	long long ans = 0, sum = 0;
	for (int l = 0, r = 0; r < n; l++) {
		while (r - l < k && r < n) sum += a[r++];
		ans ^= sum;
		sum -= a[l];
	}
	std::cout << ans << (char) 10;
}
