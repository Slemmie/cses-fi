#include <bits/stdc++.h>
 
int main() {
	
	std::string s; std::cin >> s;
	std::sort(s.begin(), s.end());
	std::vector <std::string> ans;
	do {
		ans.emplace_back(s);
	} while (std::next_permutation(s.begin(), s.end()));
	std::cout << ans.size() << "\n";
	for (const auto& x : ans) std::cout << x + "\n";
	
}
