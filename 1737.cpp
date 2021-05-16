#include <bits/stdc++.h>

typedef long long ll;

struct Set {
	int index;
	ll value;
	Set(int _index, ll _value) :
	index(_index), value(_value)
	{ }
};

struct Get {
	int left, right;
	Get(int _left, int _right) :
	left(_left), right(_right)
	{ }
};

struct Copy {
	int index;
	Copy(int _index) :
	index(_index)
	{ }
};

struct Operation {
	int type;
	int number;
	Set set = Set(0, 0);
	Get get = Get(0, 0);
	Copy copy = Copy(0);
	Operation(int _type, int _number) :
	type(_type), number(_number)
	{ }
	Operation(int _type, int _number, Set _set) :
	type(_type), number(_number),
	set(_set)
	{ }
	Operation(int _type, int _number, Get _get) :
	type(_type), number(_number),
	get(_get)
	{ }
	Operation(int _type, int _number, Copy _copy) :
	type(_type), number(_number),
	copy(_copy)
	{ }
};

struct Seg {
	
	int size;
	
	std::vector <ll> v;
	
	Seg(int _size) {
		size = 1;
		while (size < _size) size <<= 1;
		v.resize(size << 1);
	}
	
	void make(const std::vector <ll>& a) {
		make(a, 0, 0, size);
	}
	
	void make(const std::vector <ll>& a, int now, int l, int r) {
		if (!(r - l - 1)) {
			if (l < (int)a.size()) v[now] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		make(a, (now << 1) | 1, l, mid);
		make(a, (now << 1) + 2, mid, r);
		v[now] = v[(now << 1) | 1] + v[(now << 1) + 2];
	}
	
	ll set(int ind, ll val) {
		return set(ind, val, 0, 0, size);
	}
	
	ll set(int ind, ll val, int now, int l, int r) {
		if (!(r - l - 1)) {
			ll ret = v[now];
			v[now] = val;
			return ret;
		}
		int mid = (l + r) >> 1;
		ll ret = 0;
		if (ind < mid) ret = set(ind, val, (now << 1) | 1, l, mid);
		else ret = set(ind, val, (now << 1) + 2, mid, r);
		v[now] = v[(now << 1) | 1] + v[(now << 1) + 2];
		return ret;
	}
	
	ll get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
	
	ll get(int tl, int tr, int now, int l, int r) {
		if (l >= tr || r <= tl) return 0;
		if (l >= tl && r <= tr) return v[now];
		int mid = (l + r) >> 1;
		return get(tl, tr, (now << 1) | 1, l, mid) + get(tl, tr, (now << 1) + 2, mid, r);
	}
	
};

int n, q;
std::vector <std::vector <Operation>> g(1);
std::vector <ll> ans;

void dfs(int node, Seg& seg) {
	std::vector <std::pair <int, ll>> revert;
	for (Operation& o : g[node]) {
		switch (o.type) {
			case 1: {
				revert.emplace_back(o.set.index, seg.set(o.set.index, o.set.value));
				break; }
			case 2: {
				ans[o.number] = seg.get(o.get.left, o.get.right + 1);
				break; }
			case 3: {
				dfs(o.copy.index, seg);
				break; }
			default: assert(false);
		};
	}
	for (int i = (int)revert.size() - 1; i >= 0; i--)
		seg.set(revert[i].first, revert[i].second);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::cin >> n >> q;
	ans.resize(q, 0);
	std::vector <ll> v(n);
	Seg seg(n);
	for (ll& x : v) std::cin >> x;
	seg.make(v);
	for (int i = 0; i < q; i++) {
		int type; std::cin >> type;
		switch (type) {
		case 1: {
			int k, a, x; std::cin >> k >> a >> x; k--; a--;
			assert(k < (int)g.size());
			g[k].push_back(Operation(type, i, Set(a, x)));
			break; }
		case 2: {
			int k, a, b; std::cin >> k >> a >> b; k--, a--, b--;
			assert(k < (int)g.size());
			g[k].push_back(Operation(type, i, Get(a, b)));
			break; }
		case 3: {
			int k; std::cin >> k; k--;
			assert(k < (int)g.size());
			g[k].push_back(Operation(type, i, Copy(g.size())));
			g.resize(g.size() + size_t(1));
			break; }
		default: assert(false);
		};
	}
	dfs(0, seg);
	for (ll x : ans) if (x) std::cout << x << "\n";
	
}
