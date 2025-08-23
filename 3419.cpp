#include <bits/stdc++.h>

int main() {
	int n; std::cin >> n;
	std::vector <std::vector <int>> g(n, std::vector <int> (n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::set <int> st;
			for (int ii = 0; ii < i; ii++) st.insert(g[ii][j]);
			for (int jj = 0; jj < j; jj++) st.insert(g[i][jj]);
			while (st.count(g[i][j])) g[i][j]++;
			std::cout << g[i][j] << " \n"[j + 1 == n];
		}
	}
}
