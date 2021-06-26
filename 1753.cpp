#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::string s, t; std::cin >> t >> s;
	int n = s.length();
	s += "$";
	s += t;
	int k = s.length();
	std::vector <int> pre(k, 0);
	for (int i = 1; i < k; i++) {
		int j = pre[i - 1];
		while (j && s[i] != s[j]) {
			j = pre[j - 1];
		}
		j += s[i] == s[j];
		pre[i] = j;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += pre[i] == n;
	}
	std::cout << ans << "\n";
	
}
