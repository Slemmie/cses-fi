#include <bits/stdc++.h>

void rem(std::map <int, int>& mp, int vl) {
	auto it = mp.find(vl);
	assert(it != mp.end());
	it->second--;
	if (!it->second) mp.erase(it);
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int n, k; std::cin >> n >> k;
	std::vector <int> a(n);
	for (int& x : a) std::cin >> x;
	std::map <int, int> l, r;
	for (int i = 0; i < ((k + 1) >> 1); i++) l[0]++;
	for (int i = 0; i < k - ((k + 1) >> 1); i++) r[0]++;
	for (int i = 0; i < n; i++) {
		int del = i < k ? 0 : a[i - k];
		int add = a[i];
		int remlr = -1;
		if (r.find(del) != r.end()) remlr = 1;
		else remlr = 0;
		int inslr = -1;
		if (r.begin()->first <= add) inslr = 1;
		else inslr = 0;
		if (remlr == 1) rem(r, del);
		else rem(l, del);
		if (inslr == 1) r[add]++;
		else l[add]++;
		if (inslr == 0 && remlr == 1) {
			r[l.rbegin()->first]++;
			rem(l, l.rbegin()->first);
		} else if (inslr == 1 && remlr == 0) {
			l[r.begin()->first]++;
			rem(r, r.begin()->first);
		}
		if (i >= k - 1) std::cout << l.rbegin()->first << " \n"[i == n - 1];
	}
	
}
