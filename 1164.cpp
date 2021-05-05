#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::pair <int, int>> a;
	for (int i = 1; i < n + 1; i++) {
		int u, v; std::cin >> u >> v;
		a.push_back({ u, i });
		a.push_back({ v + 1, -i });
	}
	std::sort(a.begin(), a.end());
	int cnt = 0;
	std::vector <int> ans(n + 1, 0), v;
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i].second > 0) {
			if (!v.empty()) {
				ans[a[i].second] = v[v.size() - 1];
				v.pop_back();
			} else {
				cnt++;
				ans[a[i].second] = cnt;
			}
		} else {
			v.push_back(ans[-a[i].second]);
		}
	}
	std::cout << cnt << "\n";
	for (int i = 1; i < (int)ans.size(); i++) {
		std::cout << ans[i] << " \n"[i == (int)ans.size() - 1];
	}
	
}
