#include <bits/stdc++.h>
 
int main() {
	
	int t; std::cin >> t;
	while (t--) {
		int a, b; std::cin >> a >> b;
		if (a < b) std::swap(a, b);
		std::cout << (b * 2 >= a && !((a + b) % 3) ? "YES\n": "NO\n");
	}
	
}
