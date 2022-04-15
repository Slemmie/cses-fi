#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n; n -= 2;
	std::vector <int> a(n);
	std::set <int> st;
	for (int i = 0; i < n + 2; i++) {
		st.insert(i);
	}
	for (int& x : a) {
		std::cin >> x; x--;
		st.erase(x);
	}
	int r2 = a.back();
	st.clear();
	for (int i = 0; i < n + 2; i++) {
		st.insert(i);
	}
	st.erase(r2);
	std::vector <std::pair <int, int>> ans;
	std::map <int, int> mp;
	for (int x : a) {
		mp[x]++;
		st.erase(x);
	}
	mp[r2]++;
	for (int x : a) {
		auto it = st.begin();
		ans.emplace_back(*it, x);
		mp[x]--;
		if (!mp[x]) {
			mp.erase(x);
			st.insert(x);
		}
		st.erase(it);
	}
	ans.emplace_back(r2, *st.begin());
	for (auto p : ans) {
		std::cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
	
}
