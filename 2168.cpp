#include <bits/stdc++.h>

struct P {
	
	std::pair <int, int> s;
	int i;
	int ans1, ans2;
	
};

bool cmp0(const P& a, const P& b) {
	return a.i < b.i;
}

bool cmp1(const P& a, const P& b) {
	if (a.s.first == b.s.first) return a.s.second < b.s.second;
	return a.s.first > b.s.first;
}

bool cmp2(const P& a, const P& b) {
	if (a.s.first == b.s.first) return a.s.second > b.s.second;
	return a.s.first < b.s.first;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n; std::cin >> n;
	std::vector <P> a(n);
	for (int i = 0; i < n; i++) a[i].i = i;
	for (auto& p : a) std::cin >> p.s.first >> p.s.second;
	int mn = 1 << 30;
	std::sort(a.begin(), a.end(), cmp1);
	for (auto& p : a) {
		p.ans1 = mn <= p.s.second;
		mn = std::min(mn, p.s.second);
	}
	int mx = 0;
	std::sort(a.begin(), a.end(), cmp2);
	for (auto& p : a) {
		p.ans2 = mx >= p.s.second;
		mx = std::max(mx, p.s.second);
	}
	std::sort(a.begin(), a.end(), cmp0);
	for (auto p : a) std::cout << p.ans1 << " ";
	std::cout << "\n";
	for (auto p : a) std::cout << p.ans2 << " ";
	std::cout << "\n";
	
}
