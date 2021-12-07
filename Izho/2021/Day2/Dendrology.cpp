// 46/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 1000;
map<int, int> has[N];
ll res[N];
vector<vector<int>> edge;
vector<int> arr;

inline ll cal(ll a, ll b) {
	return (b - a + 1) * (b - a + 2) / 2;
}

void merge(int a, int b) {
	if(has[a].size() < has[b].size()) {
		swap(has[a], has[b]);
		swap(res[a], res[b]);
	}
	for(const auto &[l, r] : has[b]) {
		int x = l, y = r;
		auto it = has[a].lower_bound(l);
		if(it != has[a].begin()) {
			--it;
			auto [c, d] = *it;
			if(d == l - 1) {
				res[a] -= cal(c, d);
				has[a].erase(it);
				x = c;
			}
		}
		it = has[a].lower_bound(r + 1);
		if(it != has[a].end()) {
			auto [c, d] = *it;
			if(c == r + 1) {
				res[a] -= cal(c, d);
				has[a].erase(it);
				y = d;
			}
		}
		has[a][x] = y;
		res[a] += cal(x, y);
	}
}

ll dfs(int u, int p) {
	int r = u;
	ll cur = 0;
	has[u][arr[u]] = arr[u];
	res[u] = 1;
	for(int v : edge[u]) {
		if(v == p)
			continue;
		dfs(v, u);
		if(u == p)
			cur += res[v];
		else
			merge(u, v);
	}
	return cur;
}

void solve(int n) {
	arr.resize(n);
	for(int &a : arr)
		cin >> a;
	edge.resize(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[--u].push_back(--v);
		edge[v].push_back(u);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			has[j].clear(), res[j] = 0;
		ll r = dfs(i, i);
		ans += 1LL * (n + 1) * n / 2;
		//cout << r << " \n"[i == n - 1];
		ans -= r;
	}
	cout << ans << '\n';
}

signed main() {
	int n, q;
	cin >> n >> q;
	assert(q == 0);
	if(n <= 1000) {
		solve(n);
		return 0;
	}
	ll ans = 0;
	arr.resize(n);
	edge.resize(n);
	for(int &a : arr)
		cin >> a;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[--u].push_back(--v);
		edge[v].push_back(u);
	}
	if(edge[0].size() == n - 1) {
		ll g = n;
		ll x = g * (g + 1) * (g + 1) / 2 - g * (g + 1) * (2 * g + 1) / 6;
		ll y = 0;
		if(1 < arr[0])
			y += (arr[0] - 1) * 1LL * arr[0] / 2 - arr[0] + 1;
		if(arr[0] < g)
			y += (g - arr[0] + 1) * (g - arr[0]) / 2 - (g - arr[0]);
		cout << x + y << '\n';
		return 0;
	}

	map<int, int> l, r;
	
	ll lres = 0, rres = cal(1, n);
	r[1] = n;
	auto add = [&](int x) {
		int c = x, d = x;
		auto it = l.lower_bound(x);
		if(it != l.end() && it->first == x + 1) {
			auto [a, b] = *it;
			d = b;
			lres -= cal(a, b);
			it = l.erase(it);
		}
		if(it != l.begin() && prev(it)->second == x - 1) {
			auto [a, b] = *prev(it);
			c = a;
			lres -= cal(a, b);
			l.erase(prev(it));
		}
		l[c] = d;
		lres += cal(c, d);
	};
	auto rem = [&](int x) {
		auto it = prev(r.upper_bound(x));
		auto [a, b] = *it;
		rres -= cal(a, b);
		r.erase(it);

		if(a < x) {
			r[a] = x - 1;
			rres += cal(a, x - 1);
		}
		if(x < b) {
			r[x + 1] = b;
			rres += cal(x + 1, b);
		}
	};
	for(int i = 0; i < n; i++) {
		rem(arr[i]);
		ans += cal(1, n);
		ans -= lres + rres;
		add(arr[i]);
	}
	cout << ans << '\n';
}
