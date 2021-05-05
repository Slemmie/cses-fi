#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::map <int, int> tick;
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		tick[p]++;
	}
	while (m--) {
		int p; std::cin >> p;
		auto it = tick.upper_bound(p);
		if (it == tick.begin()) std::cout << "-1\n";
		else {
			std::cout << (*--it).first << "\n";
			(*it).second--;
			if (!(*it).second) tick.erase(it);
		}
	}
	
}
