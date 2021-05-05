#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
 
struct Mat {
	ll mat[2][2];
	Mat(ll a, ll b, ll c, ll d) {
		mat[0][0] = a, mat[1][0] = b, mat[0][1] = c, mat[1][1] = d;
	}
};
 
Mat mul(const Mat& a, const Mat& b) {
	ll u1 = a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0];
	ll u2 = a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1];
	ll d1 = a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0];
	ll d2 = a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1];
	return Mat(u1 % mod, u2 % mod, d1 % mod, d2 % mod);
}
 
Mat pow(Mat mat, ll p) {
	if (p < 2LL) return mat;
	mat = pow(mat, p / 2LL);
	mat = mul(mat, mat);
	if (p & 1LL) return mul(mat, Mat(1, 1, 1, 0));
	return mat;
}
 
int main() {
	
	ll n; std::cin >> n;
	if (n <= 0) { std::cout << "0\n"; return 0; }
	std::cout << pow(Mat(1, 1, 1, 0), n - 1LL).mat[0][0] << "\n";
	
}
