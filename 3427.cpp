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
	int n, m; std::cin >> n >> m;
	lib::LCT lct(m + 1);
	for (int i = 0; i < n; i++) {
		int y1, y2; std::cin >> y1 >> y2;
		assert((y2 - y1) % m == 0);
		lib::Line l = { -(y2 - y1) / m, -y1 };
		lct.insert(l, 0, m);
	}
	for (int i = 0; i <= m; i++) {
		std::cout << -lct.query(i, 0, m).f(i) << (i == m ? (char) 10 : ' ');
	}
}
