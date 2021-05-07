#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::string s; std::cin >> s;
	int n = s.length();
	std::string ans = "";
	int j = 0;
	for (int i = 0; i < n; i++) {
		std::set <char> st;
		for (; i < n; i++) {
			if (st.size() == size_t(3) && !st.count(s[i])) {
				ans += s[i];
				j = i;
				break;
			}
			st.insert(s[i]);
		}
	}
	std::set <char> st = { 'A', 'C', 'G', 'T' };
	for (int i = j + 1; i < n; i++) st.erase(s[i]);
	assert(st.size());
	ans += *st.begin();
	std::cout << ans << "\n";
	
}
