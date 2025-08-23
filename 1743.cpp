#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::string s; std::cin >> s;
	std::map <char, int> mp;
	for (char c : s) mp[c]++;
	for (auto [c, f] : mp) {
		if (f > (int) (s.size() + 1) / 2) {
			std::cout << "-1\n";
			return 0;
		}
	}
	for (int i = 0; i < (int) s.size(); i++) {
		int left = s.size() - i;
		bool skip = false;
		for (auto& [c, f] : mp) {
			if (f > (left + 0) / 2) {
				skip = true;
				f--;
				s[i] = c;
				break;
			}
		}
		if (skip) continue;
		for (auto& [c, f] : mp) {
			if (f && (i == 0 || c != s[i - 1])) {
				f--;
				s[i] = c;
				break;
			}
		}
	}
	std::cout << s << "\n";
}
