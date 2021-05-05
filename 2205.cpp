#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::string> a = { "0", "1" };
	for (int i = 2; i <= n; i++) {
		if (i & 1) {
			int tmp = (int)a.size() - 1 - ((1 << (i - 1)) - 1);
			int ptr = tmp;
			std::vector <std::string> add;
			std::vector <std::string> addd;
			for (; ptr < (int)a.size(); ptr++) {
				add.push_back("0" + a[ptr]);
				addd.push_back("1" + a[ptr]);
			}
			std::reverse(add.begin(), add.end());
			for (const auto& x : add) a.push_back(x);
			for (const auto& x : addd) a.push_back(x);
		} else {
			int tmp = (int)a.size() - 1 - ((1 << (i - 1)) - 1);
			int ptr = tmp;
			std::vector <std::string> add;
			std::vector <std::string> addd;
			for (; ptr < (int)a.size(); ptr++) {
				add.push_back("0" + a[ptr]);
				addd.push_back("1" + a[ptr]);
			}
			for (const auto& x : add) a.push_back(x);
			std::reverse(addd.begin(), addd.end());
			for (const auto& x : addd) a.push_back(x);
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		std::cout << a[(int)a.size() - 1 - i] << "\n";
	}
	
}
