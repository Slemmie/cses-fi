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
	std::vector <int> ans;
	for (int i = pre.back(); i; i = pre[i - 1]) {
		ans.push_back(i);
	}
	std::sort(ans.begin(), ans.end());
	for (int x : ans) std::cout << x << " ";
	std::cout << "\n";
	
}
