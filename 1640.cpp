#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, x; std::cin >> n >> x;
	std::set <int> st;
	std::vector <int> a;
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		if (st.count(x - p)) {
			for (int j = 0; j < (int)a.size(); j++) {
				if (a[j] + p == x) {
					std::cout << j + 1 << " " << i + 1 << "\n";
				}
			}
			return 0;
		}
		st.insert(p);
		a.push_back(p);
	}
	std::cout << "IMPOSSIBLE\n";
	
}
