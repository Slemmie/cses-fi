#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <int> seq = { 0 };
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		int ins = std::lower_bound(seq.begin(), seq.end(), p) - seq.begin();
		if (ins == (int)seq.size()) seq.push_back(p);
		seq[ins] = p;
	}
	std::cout<< (int)seq.size() - 1 << "\n";
	
}
