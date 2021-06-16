#include <bits/stdc++.h>

int d[2][4] = { { 1, -1, 0, 0 }, { 0, 0, 1, -1 } };

double dp[101][8][8], ans[8][8];

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ans[i][j] = 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k <= n; k++) {
				for (int I = 0; I < 8; I++) {
					for (int J = 0; J < 8; J++) {
						dp[k][I][J] = 0;
					}
				}
			}
			dp[0][i][j] = 1;
			for (int k = 0; k < n; k++) {
				for (int I = 0; I < 8; I++) {
					for (int J = 0; J < 8; J++) {
						double dir = 0;
						for (int f = 0; f < 4; f++) {
							int a = I + d[0][f];
							int b = J + d[1][f];
							dir += a >= 0 && b >= 0 && a < 8 && b < 8;
						}
						for (int f = 0; f < 4; f++) {
							int a = I + d[0][f];
							int b = J + d[1][f];
							if (a >= 0 && b >= 0 && a < 8 && b < 8) {
								dp[k + 1][a][b] += dp[k][I][J] / dir;
							}
						}
					}
				}
			}
			for (int I = 0; I < 8; I++) {
				for (int J = 0; J < 8; J++) {
					ans[I][J] *= (1 - dp[n][I][J]);
				}
			}
		}
	}
	double put = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			put += ans[i][j];
		}
	}
	put *= 1e6;
	put = llround(put);
	put /= 1e6;
	std::cout << std::fixed << std::setprecision(6) << put << "\n";
	
}
