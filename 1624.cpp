#include <bits/stdc++.h>
 
std::vector <std::string> g(8);
std::vector <int> ans;
 
int rec(int d) {
	if (d == 8) return 1;
	int r = 0;
	for (int i = 0; i < 8; i++) {
		if (g[d][i] != '*') {
			bool go = true;
			for (int j = 0; j < d; j++) {
				if (ans[j] == i || ans[j] == i + (d - j) || ans[j] == i - (d - j)) { go = false; break; }
			}
			if (go) { ans.push_back(i); r += rec(d + 1); ans.pop_back(); }
		}
	}
	return r;
}
 
int main() {
	
	for (auto& x : g) std::cin >> x;
	std::cout << rec(0) << "\n";
	
}
