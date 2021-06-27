#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::string s; std::cin >> s;
	int n = s.length();
	s += s;
	int ans = 0, i = 0;
	while (i < n) {
		ans = i;
		int j = i + 1, k = i;
		while (j < (n << 1) && s[j] >= s[k]) {
			k += s[j] == s[k];
			k = s[j] > s[k] ? i : k;
			j++;
		}
		while (i <= k) {
			i += j - k;
		}
	}
	for (int j = ans; j < ans + n; j++) {
		std::cout << s[j];
	}
	std::cout << "\n";
	
}
