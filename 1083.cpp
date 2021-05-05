#include <bits/stdc++.h>
 
typedef long long ll;
 
int main() {
	
	ll n; std::cin >> n;
	ll sum = 0;
	for (int i = 0; i < (int)n - 1; i++) {
		ll p; std::cin >> p;
		sum += p;
	}
	std::cout << (n * (n + 1LL)) / 2LL - sum << "\n";
	
}
