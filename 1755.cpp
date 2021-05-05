#include <bits/stdc++.h>
 
int main() {
	
	std::string s; std::cin >> s;
	std::vector <int> has(26, 0);
	for (const char& c : s) has[c - 'A']++;
	bool bad = false;
	for (const int& x : has) if (x & 1) {
		if (bad) { std::cout << "NO SOLUTION\n"; return 0; }
		bad = true;
	}
	std::string ans = "";
	char mid = '$';
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < (has[i] >> 1); j++) ans += i + 'A';
		if (has[i] & 1) mid = i + 'A';
	}
	std::cout << ans;
	if (mid != '$') std::cout << mid;
	std::reverse(ans.begin(), ans.end());
	std::cout << ans << "\n";
	
}
