#include <bits/stdc++.h>
 
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int x, n; std::cin >> x >> n;
	std::set <int> p;
	p.insert(0);
	p.insert(x);
	std::multiset <int> d;
	d.insert(x);
	for (int i = 0; i < n; i++) {
		int ip; std::cin >> ip;
		auto it = p.upper_bound(ip);
		int r = *it, l = *(--it);
		d.erase(d.find(r - l));
		p.insert(ip);
		d.insert(r - ip);
		d.insert(ip - l);
		std::cout << *(--d.end()) << " \n"[i == n - 1];
	}
	
}
