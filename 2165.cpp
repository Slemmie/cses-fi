#include <bits/stdc++.h>
 
std::vector <std::pair <int, int>> ans;
 
void f(int start, int end, int n) {
	if (n == 1) { ans.push_back({ start, end }); return; }
	int middle = 6 - start - end;
	f(start, middle, n - 1);
	ans.push_back({ start, end });
	f(middle, end, n - 1);
}
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	f(1, 3, n);
	std::cout << ans.size() << "\n";
	for (const auto& p : ans) std::cout << p.first << " " << p.second << "\n";
	
}
