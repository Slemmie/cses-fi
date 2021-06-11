#include <bits/stdc++.h>

typedef long long ll;

constexpr ll max = 1e6 + 1;

ll pref[max];
ll mobi[max];

void least() {
	for (int i = 2; i < max; i++) {
		if (!pref[i]) {
			for (int j = i; j < max; j += i) {
				if (!pref[j]) {
					pref[j] = i;
				}
			}
		}
	}
}

void mobius() {
	for (int i = 1; i < max; i++) {
		if (i == 1) {
			mobi[i] = 1;
		} else {
			if (pref[i / pref[i]] == pref[i]) mobi[i] = 0;
			else mobi[i] = -mobi[i / pref[i]];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	ll n; std::cin >> n;
	ll c[max];
	memset(pref, 0, sizeof(mobi));
	memset(mobi, 0, sizeof(pref));
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) {
		ll x; std::cin >> x;
		c[x]++;
	}
	least();
	mobius();
	ll ans = 0;
	for (int i = 1; i < max; i++) {
		if (!mobi[i]) continue;
		ll d = 0;
		for (int j = i; j < max; j += i) {
			d += c[j];
		}
		ans += ((d * (d - 1LL)) >> 1) * mobi[i];
	}
	std::cout << ans << "\n";
	
}
