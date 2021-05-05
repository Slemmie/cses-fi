#include <bits/stdc++.h>
 
int main() {
	
	int n; std::cin >> n;
	if (n == 1) { std::cout << "1\n"; return 0; }
	else if (n == 4) { std::cout << "2 4 1 3\n"; return 0; }
	else if (n < 4) { std::cout << "NO SOLUTION\n"; return 0; }
	int l = 1, h = ((n + 1) >> 1) + 1;
	for (int i = 0; i < n; i++) {
		if (i & 1) std::cout << h++ << " ";
		else std::cout << l++ << " ";
	}
	std::cout << "\n";
	
}
