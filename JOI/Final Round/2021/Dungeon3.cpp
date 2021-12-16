// 100/100
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

const int N = 1e6 + 25;
struct fenwicktree {
	ll arr[N];
	int n;
	void init(int _n) { n = _n; }
	void edt(int p, ll v) {
		for(p++; p <= n; p += p & -p)
			arr[p] += v;
	}
	ll que(int p) {
		ll res = 0;
		for(p++; p; p -= p & -p)
			res += arr[p];
		return res;
	}
} slope, intercept;

struct segtree {
	ll arr[N << 1];
	int n;
	void init(vector<ll> &a) {
		n = a.size();
		for(int i = 0; i < n; i++)
			arr[i + n] = a[i];
		for(int i = n - 1; i; i--)
			arr[i] = max(arr[i << 1], arr[i << 1 | 1]);
	}
	ll que(int l, int r) {
		ll res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = max(res, arr[l++]);
			if(r & 1)
				res = max(res, arr[--r]);
		}
		return res;
	}
} tree;

struct segtree2 {
	pair<int, int> arr[N << 1];
	int n;
	void init(vector<int> &a) {
		n = a.size();
		for(int i = 0; i < n; i++)
			arr[i + n] = {a[i], i};
		for(int i = n - 1; i; i--)
			arr[i] = min(arr[i << 1], arr[i << 1 | 1]);
	}
	int que(int l, int r) {
		pair<int, int> res = {INF, 0};
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = min(res, arr[l++]);
			if(r & 1)
				res = min(res, arr[--r]);
		}
		return res.second;
	}
} pos_tree;

struct query {
	int p, u, id, v;
	bool operator<(query b) {
		return p > b.p;
	}
};
signed main() {
	int n, m;
	cin >> n >> m;
	vector<ll> pos(n + 1);
	vector<int> cost(n + 1), r(n, -1);
	vector<vector<int>> is(n);

	for(int i = 1; i <= n; i++)
		cin >> pos[i];
	tree.init(pos);
	for(int i = 1; i <= n; i++)
		pos[i] += pos[i - 1];

	for(int i = 0; i < n; i++)
		cin >> cost[i];
	pos_tree.init(cost);
	
	auto pos_get = [&](ll l, ll r) {
		l = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
		r = lower_bound(pos.begin(), pos.end(), r) - pos.begin();
		return pos_tree.que(l, r);
	};

	vector<query> que(m * 2);
	vector<ll> v = {0, LINF}, ans(m);
	for(int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		a--;
		b--;

		if(tree.que(a + 1, b + 1) > c)
			ans[i] = -1;
		else {
			v.push_back(c);

			int t = pos_get(max(pos[a], pos[b] - c), pos[b]);
			ans[i] += (pos[b] - pos[t]) * cost[t];

			que[i * 2] = {a, c, i, 1};
			que[i * 2 + 1] = {t, c, i, -1};
		}
	}
	sort(que.begin(), que.end());

	stack<int> has;
	has.push(n);
	for(int i = n - 1; ~i; i--) {
		while(!has.empty() && cost[has.top()] >= cost[i]) {
			v.push_back(pos[has.top()] - pos[i]);
			is[i].push_back(has.top());
			has.pop();
		}
		for(int j : is[i])
			v.push_back(pos[r[j]] - pos[i]);
		if(!has.empty()) {
			r[i] = has.top();
			v.push_back(pos[r[i]] - pos[i]);
		}
		has.push(i);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	slope.init(v.size());
	intercept.init(v.size());

	auto edt = [&](ll l, ll r, ll m, ll k) { // [l, r)
		if(l > r)
			return;
		ll x = l;
		assert(*lower_bound(v.begin(), v.end(), l) == l);
		assert(*lower_bound(v.begin(), v.end(), r) == r);
		l = lower_bound(v.begin(), v.end(), l) - v.begin();
		r = lower_bound(v.begin(), v.end(), r) - v.begin();
		slope.edt(l, m);
		intercept.edt(l, k - x * m);
		if(r < v.size()) {
			slope.edt(r, -m);
			intercept.edt(r, -(k - x * m));
		}
	};
	auto get = [&](ll u) {
		int it = lower_bound(v.begin(), v.end(), u) - v.begin();
		assert(v[it] == u);
		return slope.que(it) * u + intercept.que(it);
	};

	for(int i = n - 1, it = 0; ~i; i--) {
		for(int j : is[i]) {
			edt(pos[j] - pos[i], pos[r[j]] - pos[i], -cost[j], 0);
			edt(pos[r[j]] - pos[i], LINF, 0, -cost[j] * (pos[r[j]] - pos[j]));
		}
		edt(0, pos[r[i]] - pos[i], cost[i], 0);
		edt(pos[r[i]] - pos[i], LINF, 0, cost[i] * (pos[r[i]] - pos[i]));

		while(it < que.size() && que[it].p == i) {
			ans[que[it].id] += get(que[it].u) * que[it].v;
			it++;
		}
	}

	for(int i = 0; i < m; i++) {
		if(ans[i] < 0)
			cout << "-1\n";
		else
			cout << ans[i] << '\n';
	}
}
