#include <bits/stdc++.h>

int bin[20][1'000'002];

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	for (int b = 0; b < 20; b++) for (int i = 0; i < 1'000'002; i++) bin[b][i] = 1'000'001;
	int n, q; std::cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int l, r; std::cin >> l >> r;
		bin[0][l] = std::min(bin[0][l], r);
	}
	for (int i = 1'000'000; i >= 0; i--) bin[0][i] = std::min(bin[0][i], bin[0][i + 1]);
	for (int b = 1; b < 20; b++) for (int i = 0; i <= 1'000'000; i++) bin[b][i] = bin[b - 1][bin[b - 1][i]];
	while (q--) {
		int l, r, ans = 0; std::cin >> l >> r;
		while (l <= r) {
			int hit = 0;
			for (int b = 0; b < 20; b++) if (bin[b][l] > r) { hit = b; break; }
			if (!hit) break;
			ans += 1 << --hit;
			l = bin[hit][l];
		}
		std::cout << ans << (char) 10;
	}
}
