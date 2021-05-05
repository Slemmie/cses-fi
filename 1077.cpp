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
	long long sumL = 0, sumR = 0;
	for (int i = 0; i < n; i++) {
		int del = i < k ? 0 : a[i - k];
		int add = a[i];
		int remlr = -1;
		if (r.find(del) != r.end()) remlr = 1;
		else remlr = 0;
		int inslr = -1;
		if (r.begin()->first <= add) inslr = 1;
		else inslr = 0;
		if (remlr == 1) rem(r, del), sumR -= (long long)del;
		else rem(l, del), sumL -= (long long)del;
		if (inslr == 1) r[add]++, sumR += (long long)add;
		else l[add]++, sumL += (long long)add;
		if (inslr == 0 && remlr == 1) {
			r[l.rbegin()->first]++; sumR += (long long)l.rbegin()->first;
			sumL -= (long long)l.rbegin()->first;
			rem(l, l.rbegin()->first);
		} else if (inslr == 1 && remlr == 0) {
			l[r.begin()->first]++; sumL += (long long)r.begin()->first;
			sumR -= (long long)r.begin()->first;
			rem(r, r.begin()->first);
		}
		long long med = (long long)l.rbegin()->first;
		long long ans = med * (long long)((k + 1) >> 1) - sumL + sumR - med * (long long)(k - ((k + 1) >> 1));
		if (i >= k - 1) std::cout << ans << " \n"[i == n - 1];
	}
	
}
