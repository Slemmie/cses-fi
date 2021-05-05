#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; ll x; std::cin >> n >> x;
	std::vector <ll> a(n);
	for (ll& i : a) std::cin >> i;
	std::map <ll, int> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) if (mp.find(x - a[i] - a[j]) != mp.end()) {
			if (i == j || i == mp[x - a[i] - a[j]] || j == mp[x - a[i] - a[j]]) continue;
			std::cout << i + 1 << " " << j + 1 << " " << mp[x - a[i] - a[j]] + 1 << "\n";
			return 0;
		}
		mp[a[i]] = i;
	}
	std::cout << "IMPOSSIBLE\n";
	
}
