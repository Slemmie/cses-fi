#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	
	int k; std::cin >> k;
	for (int i = 1LL; i <= (ll)k; i++) {
		std::cout << ((i * i * (i * i - 1LL)) >> 1LL) - (((i - 2LL) * 2LL) * (2LL * (i - 4LL) + 6LL)) << "\n";
	}
	
}
