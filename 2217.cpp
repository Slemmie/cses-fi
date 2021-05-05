#include <bits/stdc++.h>

int n, m;
std::vector <int> a, pos, adds;

void check(int p) {
	if (p == n + 1) return;
	adds[p] = pos[p - 1] > pos[p];
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> m;
	a.resize(n);
	pos.resize(n + 1, 1 << 30);
	adds.resize(n + 1, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		adds[a[i]] = pos[a[i] - 1] > i;
		ans += pos[a[i] - 1] > i;
		pos[a[i]] = i;
	}
	while (m--) {
		int i, j; std::cin >> i >> j; i--, j--;
		std::swap(a[i], a[j]);
		pos[a[i]] = i;
		pos[a[j]] = j;
		
		ans -= adds[a[i]];
		if (a[i] + 1 != a[j]) ans -= adds[a[i] + 1];
		ans -= adds[a[j]];
		if (a[j] + 1 != a[i]) ans -= adds[a[j] + 1];
		
		check(a[i]);
		check(a[j]);
		check(a[i] + 1);
		check(a[j] + 1);
		
		ans += adds[a[i]];
		if (a[i] + 1 != a[j]) ans += adds[a[i] + 1];
		ans += adds[a[j]];
		if (a[j] + 1 != a[i]) ans += adds[a[j] + 1];
		
		std::cout << ans << "\n";
	}
	
}
