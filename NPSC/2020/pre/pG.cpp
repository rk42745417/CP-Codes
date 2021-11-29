#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using uint = uint32_t;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double EPS = 1e-6;

#define int ll
signed main() { EmiliaMyWife
	int n, q;
	cin >> n >> q;
	map<int, int> seg;
	seg[1] = n;
	while(q--) {
		int k, cur = 0;
		ll ans = 0;
		cin >> k;
		auto it = seg.begin();
		int wk = k;
		ans += it->first - 1;
		if(it->second > it->first)
			seg[it->first + 1] = it->second;
		it = seg.erase(it);
		while(k) {
			int len = it->second - it->first + 1;
			if(len <= k) {
				ans += len * (it->first - 1 - cur);
			}
			else {
				ans += k * (it->first - 1 - cur);
				seg[it->first + k] = it->second;
			}
			//cerr << len << ' ' << k << ' '<< cur << '\n';
			it = seg.erase(it);
			cur += min(len, k);
			k -= min(len, k);
		}
		assert(cur == wk);
		if(wk)
			seg[1] = (wk);
		cout << ans;
		if(q)
			cout << ' ';
		else
			cout << '\n';
	}
}
