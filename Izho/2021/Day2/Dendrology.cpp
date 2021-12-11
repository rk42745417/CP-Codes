// 66/100
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

const int N = 1e5 + 25;
map<int, int> has[N];
ll res[N];
int arr[N], n;
vector<int> edge[N];

inline ll cal(ll a, ll b) {
	if(a > b)
		return 0;
	return (b - a + 1) * (b - a + 2) / 2;
}

void merge(int a, int b) {
	if(has[a].size() < has[b].size()) {
		swap(has[a], has[b]);
		swap(res[a], res[b]);
	}
	for(const auto &[l, r] : has[b]) {
		int x = l, y = r;
		int w = 0, g = 0;

		auto it = has[a].lower_bound(l);
		if(it != has[a].begin()) {
			--it;
			auto [c, d] = *it;
			w = d + 1;
			if(d == l - 1) {
				res[a] -= cal(c, d);
				has[a].erase(it);
				x = c;
			}
		}
		else
			w = 1;

		it = has[a].lower_bound(r + 1);
		if(it != has[a].end()) {
			auto [c, d] = *it;
			g = c - 1;
			if(c == r + 1) {
				res[a] -= cal(c, d);
				has[a].erase(it);
				y = d;
			}
		}
		else
			g = n;

		res[a] -= cal(w, g);
		res[a] += cal(w, x - 1);
		res[a] += cal(y + 1, g);

		has[a][x] = y;
		res[a] += cal(x, y);
	}
}

ll dfs(int u, int p) {
	ll cur = 0;
	has[u][arr[u]] = arr[u];

	res[u] = 1;
	res[u] += cal(1, arr[u] - 1);
	res[u] += cal(arr[u] + 1, n);

	for(int v : edge[u]) {
		if(v == p)
			continue;
		cur += dfs(v, u);
		cur += cal(1, n) - res[v];
		merge(u, v);
	}
	return cur;
}

signed main() {
	int q;
	cin >> n >> q;
	assert(q == 0);
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	cout << cal(1, n) + dfs(1, 1) << '\n';
}
