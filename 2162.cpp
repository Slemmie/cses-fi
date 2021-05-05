#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::set <int> st;
	for (int i = 1; i <= n; i++) st.insert(i);
	std::vector <int> ans;
	bool add = true;
	while (st.size()) {
		if (st.size() == 1) {
			ans.push_back(*st.begin());
			break;
		}
		std::vector <int> rem;
		auto it = st.begin();
		if (add) it++;
		add = false;
		while (true) {
			ans.push_back(*it);
			rem.push_back(*it);
			it++;
			if (it == st.end()) {
				add = true;
				break;
			}
			it++;
			if (it == st.end()) break;
		}
		for (int x : rem) st.erase(x);
	}
	for (int x : ans) std::cout << x << " ";
	std::cout << "\n";
	
}
