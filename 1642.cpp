#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; ll x; std::cin >> n >> x;
	std::vector <ll> a(n);
	for (ll& i : a) std::cin >> i;
	std::map <ll, std::pair <int, int>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (mp.find(x - a[i] - a[j]) != mp.end()) {
				auto p = mp[x - a[i] - a[j]];
				if (i == p.first || i == p.second || j == p.first || j == p.second) continue;
				std::cout << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1 << "\n";
				return 0;
			}
		}
		for (int j = i + 1; j < n; j++) mp[a[i] + a[j]] = { i, j };
	}
	std::cout << "IMPOSSIBLE\n";
	
}
