#include <bits/stdc++.h>
 
int main() {
	
	int n, m, k; std::cin >> n >> m >> k;
	std::vector <int> a(n), b(m);
	for (int& x : a) std::cin >> x;
	for (int& x : b) std::cin >> x;
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	int ans = 0, i = 0, j = 0;
	while (i < n && j < m) {
		if (abs(a[i] - b[j]) <= k) ans++, i++, j++;
		else if (a[i] > b[j]) j++;
		else i++;
	}
	std::cout << ans << "\n";
	
}
