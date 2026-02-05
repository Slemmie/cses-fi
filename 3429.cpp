#include <bits/stdc++.h>

namespace lib {
	using namespace std;
	typedef long long ll;
	struct Line { ll a, b; ll f(ll x) { return a * x + b; } };
	constexpr const Line LINF { 0, 1LL << 60 };
	struct LCT {
		vector <Line> v; // coord-compression: modify v[x] -> v[conert(x)]
		LCT(int size) { v.resize(size, LINF); }
		void insert(Line line, int l, int r) {
			if (l > r) return;
			int mid = (l + r) >> 1;
			if (line.f(mid) < v[mid].f(mid)) swap(line, v[mid]);
			if (line.f(l) < v[mid].f(l)) insert(line, l, mid - 1);
			else insert(line, mid + 1, r);
		}
		Line query(int x, int l, int r) {
			if (l > r) return LINF;
			int mid = (l + r) >> 1;
			if (x == mid) return v[mid]; // faster on avg. - not necessary
			if (x < mid) return best_of(v[mid], query(x, l, mid - 1), x);
			return best_of(v[mid], query(x, mid + 1, r), x);
		}
		Line best_of(Line a, Line b, ll x) { return a.f(x) < b.f(x) ? a : b; }
	};
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n; std::cin >> n;
	lib::LCT lct(100'005);
	for (int i = 0; i < n; i++) {
		int t; std::cin >> t;
		if (t == 1) {
			int a, b; std::cin >> a >> b;
			lib::Line l = { .a = -a, .b = -b };
			lct.insert(l, 0, 100'004);
		} else {
			int x; std::cin >> x;
			std::cout << -lct.query(x, 0, 100'004).f(x) << (char) 10;
		}
	}
}
