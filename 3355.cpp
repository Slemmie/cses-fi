#include <bits/stdc++.h>

constexpr const int mxn = 10'000'001;

bool can[mxn];
std::pair <int, int> mp[mxn];

int main() {
	for (int i = 0; i * i < mxn; i++)
		for (int j = i; i * i + j * j < mxn; j++)
			can[i * i + j * j] = true,
			mp[i * i + j * j] = { i, j };
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		bool done = false;
		for (int i = 0; !done && i * i <= n; i++) {
			for (int j = i, ss; (ss = i * i + j * j) <= n; j++) {
				int m = n - ss;
				if (!can[m]) continue;
				auto cd = mp[m];
				std::cout << i << " " << j << " " << cd.first << " " << cd.second << (char) 10;
				done = true;
				break;
			}
		}
	}
}
