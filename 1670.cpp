#include <bits/stdc++.h>

constexpr long long target =
(1LL << (4 * 8)) |
(2LL << (4 * 7)) |
(3LL << (4 * 6)) |
(4LL << (4 * 5)) |
(5LL << (4 * 4)) |
(6LL << (4 * 3)) |
(7LL << (4 * 2)) |
(8LL << (4 * 1)) |
(9LL << (4 * 0));

constexpr long long all[9] = {
	0b1111LL << (4 * 8),
	0b1111LL << (4 * 7),
	0b1111LL << (4 * 6),
	0b1111LL << (4 * 5),
	0b1111LL << (4 * 4),
	0b1111LL << (4 * 3),
	0b1111LL << (4 * 2),
	0b1111LL << (4 * 1),
	0b1111LL << (4 * 0)
};

#define ta(mask) \
(((mask & all[0]) >> (4 * 1)) | ((mask & all[1]) << (4 * 1)) | (mask & (~0LL ^ (all[0] | all[1]))))
#define tb(mask) \
(((mask & all[1]) >> (4 * 1)) | ((mask & all[2]) << (4 * 1)) | (mask & (~0LL ^ (all[1] | all[2]))))
#define tc(mask) \
(((mask & all[3]) >> (4 * 1)) | ((mask & all[4]) << (4 * 1)) | (mask & (~0LL ^ (all[3] | all[4]))))
#define td(mask) \
(((mask & all[4]) >> (4 * 1)) | ((mask & all[5]) << (4 * 1)) | (mask & (~0LL ^ (all[4] | all[5]))))
#define te(mask) \
(((mask & all[6]) >> (4 * 1)) | ((mask & all[7]) << (4 * 1)) | (mask & (~0LL ^ (all[6] | all[7]))))
#define tf(mask) \
(((mask & all[7]) >> (4 * 1)) | ((mask & all[8]) << (4 * 1)) | (mask & (~0LL ^ (all[7] | all[8]))))

#define tg(mask) \
(((mask & all[0]) >> (4 * 3)) | ((mask & all[3]) << (4 * 3)) | (mask & (~0LL ^ (all[0] | all[3]))))
#define th(mask) \
(((mask & all[1]) >> (4 * 3)) | ((mask & all[4]) << (4 * 3)) | (mask & (~0LL ^ (all[1] | all[4]))))
#define ti(mask) \
(((mask & all[2]) >> (4 * 3)) | ((mask & all[5]) << (4 * 3)) | (mask & (~0LL ^ (all[2] | all[5]))))
#define tj(mask) \
(((mask & all[3]) >> (4 * 3)) | ((mask & all[6]) << (4 * 3)) | (mask & (~0LL ^ (all[3] | all[6]))))
#define tk(mask) \
(((mask & all[4]) >> (4 * 3)) | ((mask & all[7]) << (4 * 3)) | (mask & (~0LL ^ (all[4] | all[7]))))
#define tl(mask) \
(((mask & all[5]) >> (4 * 3)) | ((mask & all[8]) << (4 * 3)) | (mask & (~0LL ^ (all[5] | all[8]))))

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	long long mask = 0;
	for (int i = 0; i < 9; i++) {
		int x; std::cin >> x;
		mask = (mask << 4) | x;
	}
	std::queue <std::pair <int, long long>> q;
	q.push({ 0, mask });
	std::unordered_set <long long> st(1e6);
	while (q.size()) {
		auto p = q.front(); q.pop();
		int w = p.first;
		long long m = p.second;
		if (m == target) {
			std::cout << w << "\n";
			return 0;
		}
		if (st.count(m)) {
			continue;
		}
		st.insert(m);
		q.push({ w + 1, ta(m) });
		q.push({ w + 1, tb(m) });
		q.push({ w + 1, tc(m) });
		q.push({ w + 1, td(m) });
		q.push({ w + 1, te(m) });
		q.push({ w + 1, tf(m) });
		q.push({ w + 1, tg(m) });
		q.push({ w + 1, th(m) });
		q.push({ w + 1, ti(m) });
		q.push({ w + 1, tj(m) });
		q.push({ w + 1, tk(m) });
		q.push({ w + 1, tl(m) });
	}
	assert(false);
	
}
