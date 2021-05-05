#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	
	int n; std::cin >> n;
	ll need = (ll)n * ((ll)n + 1LL) / 2LL;
	if (need & 1LL) { std::cout << "NO\n"; return 0; }
	std::cout << "YES\n";
	need /= 2LL;
	std::vector <int> ans;
	ll a = 0, b = 0, c = n;
	while (true) {
		ans.push_back(c);
		a += c--, b = need - a;
		if (!b) break;
		if (b <= c) { ans.push_back(b); break; }
	}
	std::cout << ans.size() << "\n";
	for (int x : ans) std::cout << x << " ";
	std::cout << "\n" << n - (int)ans.size() << "\n";
	for (int i = c; i; i--) if (i != b) std::cout << i << " ";
	std::cout << "\n";
	
}
