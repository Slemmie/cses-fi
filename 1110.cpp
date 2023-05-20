#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::string s; std::cin >> s;
	int n = s.size();
	std::vector <int> p(n);
	std::iota(p.begin(), p.end(), 0);
	for (int i = 0; i < n; i++) {
		char m = 'z';
		for (int x : p) {
			m = std::min(m, s[(i + x) % n]);
		}
		std::vector <int> nw;
		for (int x : p) {
			if (s[(i + x) % n] == m) {
				nw.push_back(x);
			}
		}
		p = nw;
		nw.clear();
		for (int j = 0; j < (int) p.size(); j++) {
			if (!j || p[j] - p[j - 1] != i + 1) {
				nw.push_back(p[j]);
			}
		}
		p = nw;
	}
	for (int i = 0; i < n; i++) {
		std::cout << s[(i + p[0]) % n];
	}
	std::cout << "\n";
}
