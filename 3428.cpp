#include <bits/stdc++.h>

typedef long long ll;

struct Line {
	ll a, b;
	Line(ll _a = 0, ll _b = -(1LL << 61)) : a(_a), b(_b) { }
	ll operator () (ll x) const { return a * x + b; }
};

class LCT {

	struct Node {
		Line line;
		Node* lc = nullptr;
		Node* rc = nullptr;
		static Node* create() {
			sm_pool.emplace_back();
			return &sm_pool.back();
		}
	private:
		static inline std::deque <Node> sm_pool;
	};

public:

	LCT(ll size = 1) : m_size(size), m_root(nullptr) { }

	void insert(Line line, ll l, ll r) {
		m_insert(m_root, 0, m_size - 1, l, r, line);
	}

	ll query(ll x) {
		return m_query(m_root, 0, m_size - 1, x);
	}

private:

	ll m_size;

	Node* m_root;

private:

	void m_insert(Node*& node, ll tl, ll tr, ll l, ll r, Line line) {
		if (tr < l || r < tl || tl > tr || l > r) return;
		if (!node) node = Node::create();
		if (l <= tl && tr <= r) return m_insert_knowingly(node, tl, tr, line);
		ll mid = (tl + tr) / 2;
		m_insert(node->lc, tl, mid, l, r, line);
		m_insert(node->rc, mid + 1, tr, l, r, line);
	}

	void m_insert_knowingly(Node*& node, ll tl, ll tr, Line line) {
		if (!node) node = Node::create();
		if (node->line(tl) < line(tl)) std::swap(node->line, line);
		if (node->line(tr) >= line(tr)) return;
		if (tl == tr) return;
		ll mid = (tl + tr) / 2;
		if (node->line(mid) > line(mid)) m_insert_knowingly(node->rc, mid + 1, tr, line);
		else {
			std::swap(node->line, line);
			m_insert_knowingly(node->lc, tl, mid, line);
		}
	}

	ll m_query(Node*& node, ll tl, ll tr, ll x) {
		if (!node) return -(1LL << 61);
		if (tl == tr) return node->line(x);
		ll res = node->line(x);
		ll mid = (tl + tr) / 2;
		if (x <= mid) res = std::max(res, m_query(node->lc, tl, mid, x));
		else res = std::max(res, m_query(node->rc, mid + 1, tr, x));
		return res;
	}

};

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int n, m; std::cin >> n >> m;
	LCT lct(m + 1);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
		const int s = (y2 - y1) / (x2 - x1);
		Line line(s, y1 - (ll) s * x1);
		lct.insert(line, x1, x2);
	}
	for (int i = 0; i <= m; i++) std::cout << std::max(-1LL, lct.query(i)) << (i == m ? (char) 10 : ' ');
}
