#include <bits/stdc++.h>

typedef long long ll;

ll dp[20][10][2][2];

ll f(std::string& num, int d, int x, bool lead, bool eq) {
	if (!d) return 1;
	if (x != -1 && dp[d][x][lead][eq] != -1) return dp[d][x][lead][eq];
	int smal = 0;
	int larg = eq ? int(num[(int)num.length() - d] - '0') : 9;
	ll r = 0;
	for (int i = smal; i <= larg; i++) {
		if (i == x && !lead) continue;
		r += f(num, d - 1, i, lead && !i, eq && i == larg);
	}
	if (x == -1) return r;
	return dp[d][x][lead][eq] = r;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	for (int i = 0; i < 20; i++)
	for (int j = 0; j < 10; j++)
	for (int k = 0; k < 2; k++)
	for (int l = 0; l < 2; l++)
	dp[i][j][k][l] = -1;
	ll a, b; std::cin >> a >> b;
	std::string A = std::to_string(a - 1);
	std::string B = std::to_string(b);
	ll tmp = f(B, B.length(), -1, true, true);
	for (int i = 0; i < 20; i++)
	for (int j = 0; j < 10; j++)
	for (int k = 0; k < 2; k++)
	for (int l = 0; l < 2; l++)
	dp[i][j][k][l] = -1;
	std::cout << tmp - f(A, A.length(), -1, true, true) << "\n";
	
}
