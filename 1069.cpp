#include <bits/stdc++.h>
 
int main() {
	
	std::string s; std::cin >> s;
	int ans = 0, now = 0;
	char prv = '$';
	for (const char& c : s) {
		now = (c == prv) * now + 1;
		ans = std::max(ans, now);
		prv = c;
	}
	std::cout << ans << "\n";
	
}
