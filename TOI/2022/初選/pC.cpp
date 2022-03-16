// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(4e18) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a;
	vector<vector<pair<int, int>>> edge(n);
	for(int i = 1; i < n; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		assert(d <= 1000);
		u--; v--;
		edge[u].push_back({v, d});
		edge[v].push_back({u, d});
	}
	vector<ll> sum(n), sz(n);
	ll ans = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		sum[u] = arr[u];
		sz[u]++;
		for(const auto &[v, d] : edge[u]) {
			if(v == p)
				continue;
			dfs(v, u);
			ans += abs(sum[v] - sz[v] * k) * d;
			sum[u] += sum[v];
			sz[u] += sz[v];
		}
	};
	dfs(0, 0);
	cout << ans << '\n';

}
