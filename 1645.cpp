#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <std::pair <int, int>> a = {{ 0, 0, }};
	for (int i = 0; i < n; i++) {
		int p; std::cin >> p;
		while (!a.empty() && a.back().first >= p) a.pop_back();
		std::cout << a.back().second << " \n"[i == n - 1];
		a.push_back({ p, i + 1 });
	}
	
}
