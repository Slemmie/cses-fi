#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::string s; std::cin >> s;
	int n = s.length();

	std::vector <int> pre(n, 0);
	for (int i = 1; i < n; i++) {
		int j = pre[i - 1];
		while (j && s[i] != s[j]) {
			j = pre[j - 1];
		}
		j += s[i] == s[j];
		pre[i] = j;
	}

	std::vector <int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; i++) {
		if (i < r) z[i] = std::min(r - i, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r) l = i, r = i + z[i];
	}

	for (int i = 0; i < n; i++) {
		std::cout << z[i] << " \n"[i == n - 1];
	}

	for (int i = 0; i < n; i++) {
		std::cout << pre[i] << " \n"[i == n - 1];
	}
}
