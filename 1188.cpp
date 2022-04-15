#include <bits/stdc++.h>

struct Node {
	
	int pre = 0, suf = 0, ans = 0, pre_v = -1, suf_v = -1;
	int left = 0, right = 0;
	
	static Node merge(const Node& l, const Node& r) {
		Node res;
		assert((l.pre_v == -1 && l.suf_v == -1) || (l.pre_v != -1 && l.suf_v != -1));
		assert((r.pre_v == -1 && r.suf_v == -1) || (r.pre_v != -1 && r.suf_v != -1));
		if (l.pre_v == -1) {
			return r;
		}
		if (r.pre_v == -1) {
			return l;
		}
		res.ans = std::max(l.ans, r.ans);
		if (l.suf_v == r.pre_v) {
			res.ans = std::max(res.ans, l.suf + r.pre);
		}
		res.pre = l.pre;
		if (l.right - l.left == l.pre && l.pre_v == r.pre_v) {
			res.pre = l.pre + r.pre;
		}
		res.suf = r.suf;
		if (r.right - r.left == r.suf && r.suf_v == l.suf_v) {
			res.suf = r.suf + l.suf;
		}
		res.pre_v = l.pre_v;
		res.suf_v = r.suf_v;
		res.left = l.left;
		res.right = r.right;
		return res;
	}
	
};

struct Seg {
	
	int size;
	std::vector <Node> v;
	
	Seg(int s) {
		size = 1;
		while (size < s) {
			size <<= 1;
		}
		v.resize(size << 1);
	}
	
	void set(int ind, int bit) {
		set(ind, bit, 0, 0, size);
	}
	
	void set(int ind, int bit, int now, int l, int r) {
		if (!(r - l - 1)) {
			v[now] = Node();
			v[now].pre = v[now].suf = v[now].ans = 1;
			v[now].left = l;
			v[now].right = r;
			v[now].pre_v = v[now].suf_v = bit;
			return;
		}
		int mid = (l + r) >> 1;
		if (ind < mid) {
			set(ind, bit, now * 2 + 1, l, mid);
		} else {
			set(ind, bit, now * 2 + 2, mid, r);
		}
		v[now] = Node::merge(v[now * 2 + 1], v[now * 2 + 2]);
	}
	
	int query() {
		return v[0].ans;
	}
	
};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	std::string s; std::cin >> s;
	int m; std::cin >> m;
	Seg seg(s.size());
	for (int i = 0; i < (int) s.size(); i++) {
		seg.set(i, s[i] - '0');
	}
	while (m--) {
		int x; std::cin >> x; x--;
		seg.set(x, (s[x] - '0') ^ 1);
		s[x] = s[x] == '0' ? '1' : '0';
		std::cout << seg.query() << " \n"[!m];
	}
	
}
