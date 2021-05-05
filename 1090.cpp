#include <bits/stdc++.h>
 
int main() {
	
	int n, x; std::cin >> n >> x;
	std::vector <int> a(n);
	for (int& p : a) std::cin >> p;
	std::sort(a.begin(), a.end());
	int ans = 0;
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i] + a[j] <= x) i++, j--, ans++;
		else j--, ans++;
	}
	std::cout << ans + (i == j) << "\n";
	
}
