/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"
#define print(x) emilia_mata_tenshi(#x, begin(x), end(x))
template<typename T> void emilia_mata_tenshi(const char *s, T l, T r) {
	cerr << "\e[1;33m" << s << " = [";
	while(l != r) {
		cerr << *l;
		cerr << (++l == r ? ']' : ',');
	}
	cerr << "\e[0m\n";
}

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-7;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static auto Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

const int N = 3e5 + 25;
struct fenwicktree {
	ll arr[N];
	int cnt[N];
	void edt(int p, int v) {
		for(; p < N; p += p & -p)
			arr[p] += v, cnt[p] += v / abs(v);
	}
	ll sum(int p) {
		ll res = 0;
		for(; p; p -= p & -p)
			res += arr[p];
		return res;
	}
	int get(int k) {
		int res = 0, p = 0;
		for(int i = 1 << 19; i; i >>= 1) {
			if(p + i < N && res + cnt[p + i] < k)
				res += cnt[p += i];
		}
		return p + 1;
	}
} bit;
signed main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> sol(n + 1);
	vector<int> s(n), r(n), id(n);
	vector<pair<int, int>> has;
	ll sum = 0, res = 0;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
		has.push_back({s[i], i});
	}
	sort(has.begin(), has.end());
	for(int i = 1; i <= n; i++)
		id[has[i - 1].second] = i;
	set<pair<int, int>> can, can_safe; // cost
	for(int i = 0; i < n; i++) {
		cin >> r[i];
		sol[r[i]].push_back({s[i], i});
		bit.edt(id[i], s[i]);
		can.insert({s[i], i});
	}
	int ng = 0;
	for(int i = 1; i <= n; i++) {
		for(const auto &a : sol[i - 1]) {
			can_safe.insert(a);
			auto it = can.lower_bound(a);
			if(it != can.end())
				can.erase(it);
		}
		if(can_safe.size()) {
			auto it = can_safe.end();
			--it;
			bit.edt(id[it->second], -(it->first));
			can_safe.erase(it);
		}
		else {
			ng++;
		}
		int x = bit.get(ng);
		//cout << x << ' ' << ng << '\n';
		cout << sum - bit.sum(x) << " \n"[i == n];
	}
}
