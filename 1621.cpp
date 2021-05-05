#include <bits/stdc++.h>
 
int main() {
	
	int n; std::cin >> n;
	std::set <int> st;
	while (n--) {
		int p; std::cin >> p;
		st.insert(p);
	}
	std::cout << st.size() << "\n";
	
}
