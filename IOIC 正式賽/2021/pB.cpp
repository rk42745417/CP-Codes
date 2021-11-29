#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

set<int> has;
struct dat {
	int l, r, len;
	friend bool operator<(const dat &a, const dat &b) { return a.len == b.len ? a.l > b.l : a.len < b.len; }
};
set<dat> len;
set<pair<int, int>>pos;

int insert() {
	auto it = prev(len.end());
	int l = it->l, r = it->r;
	if(l == r - 1)
		return -1;
	int m = l + r >> 1;

	len.erase(it);
	has.insert(m);
	len.insert({l, m, (m - l) / 2});
	len.insert({m, r, (r - m) / 2});
	return m;
}
void remove(int p) {
	auto it = has.lower_bound(p);
	assert(*it == p);
	int l = *prev(it), r = *next(it);

	has.erase(it);
	len.erase({p, r, (r - p) / 2});
	len.erase({l, p, (p - l) / 2});
	len.insert({l, r, (r - l) / 2});
}

signed main() { EmiliaMyWife
	int n, q;
	cin >> n >> q;
	has.insert(0); has.insert(n + 1);
	for(int i = 1, x; i <= n; i++) {
		cin >> x;
		if(x) {
			has.insert(i);
			pos.insert({x, i});
		}
	}
	auto it = next(has.begin());
	while(it != has.end()) {
		len.insert({*prev(it), *it, (*it - *prev(it)) / 2});
		it++;
	}

	while(q--) {
		int t, x;
		cin >> t >> x;
		if(t == 0) {
			int p = insert();
			if(~p)
				pos.insert({x, p});
			cout << p << '\n';
		}
		else {
			auto it = pos.lower_bound(make_pair(x, 0)), it2 = pos.upper_bound(make_pair(x, INF));
			while(it != it2) {
				//cerr << "here\n";
				remove(it->second);
				it = pos.erase(it);
			}
		}
		//cout << "Finished\n";
		//for(auto [l, r, leng] : len) {
			//cout << l << ' ' << leng << ' ' << r << '\n';
		//}
	}
}
