#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	
	ll n; std::cin >> n;
	while (n != 1LL) {
		std::cout << n << " ";
		if (n & 1LL) n = n * 3LL + 1;
		else n >>= 1LL;
	}
	std::cout << "1\n";
	
}
