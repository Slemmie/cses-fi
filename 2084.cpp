#include <bits/stdc++.h>

struct Line {
	
	long long a = 1LL << 30, b = 1LL << 60;
	
	long long f(long long x) {
		return a * x + b;
	}
	
};

struct LCT {
	
	std::vector <Line> v;
	int size;
	
	LCT(int s) {
		size = 1;
		while (size < s) {
			size <<= 1;
		}
		v.resize(size << 1);
	}
	
	void insert(Line line) {
		insert(line, 0, 0, size);
	}
	
	void insert(Line line, int now, int l, int r) {
		int mid = (l + r) >> 1;
		int fl = line.f(l) < v[now].f(l);
		int ml = line.f(mid) < v[now].f(mid);
		if (ml) {
			std::swap(line, v[now]);
		}
		if (r <= l + 1) {
			return;
		}
		if (fl ^ ml) {
			insert(line, now * 2 + 1, l, mid);
		} else {
			insert(line, now * 2 + 2, mid + 1, r);
		}
	}
	
	long long query(int x) {
		return query(x, 0, 0, size);
	}
	
	long long query(int x, int now, int l, int r) {
		if (r <= l + 1) {
			return v[now].f(x);
		}
		int mid = (l + r) >> 1;
		if (x < mid) {
			return std::min(v[now].f(x), query(x, now * 2 + 1, l, mid));
		}
		return std::min(v[now].f(x), query(x, now * 2 + 2, mid + 1, r));
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, beg; std::cin >> n >> beg;
	std::vector <int> s(n), f(s);
	for (int& x : s) {
		std::cin >> x;
	}
	for (int& x : f) {
		std::cin >> x;
	}
	LCT lct(1e6 + 3);
	lct.insert({ s[n - 1], 0 });
	for (int i = n - 2; i >= 0; i--) {
		long long val = lct.query(f[i]);
		lct.insert({ s[i], val });
	}
	std::cout << lct.query(beg) << "\n";
	
}
