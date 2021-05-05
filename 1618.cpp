#include <bits/stdc++.h>
 
int main() {
	
	int n, cnt = 0; std::cin >> n;
	for (int i = 5; n / i; i *= 5) cnt += n / i;
	std::cout << cnt << "\n";
	
}
