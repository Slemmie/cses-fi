#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, x; std::cin >> n >> x;
	std::set <int> st;
	std::vector <int> dp(2e6 + 5, 1 << 30);
	for (int i = 0; i < n; i++) { int p; std::cin >> p; st.insert(p); }
	dp[0] = 0;
	for (int c : st) for (int i = c; i <= x; i++) dp[i] = std::min(dp[i], dp[i - c] + 1);
	std::cout << (dp[x] == 1 << 30 ? -1 : dp[x]) << "\n";
	
}
