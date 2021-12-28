// 28/100 (subtask 1, 2)
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	vector<pair<ll, int>> eve(n);
	vector<ll> dis_sum(n);
	for(ll i = 0, x; i < n; i++)
		cin >> x, eve[i] = {x, i};
	sort(eve.begin(), eve.end());

	vector<vector<int>> edge(n);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[u - 1].push_back(v - 1);
		edge[v - 1].push_back(u - 1);
	}

	ll ans = 0, cur = -1;
	int it = 0;
	function<void(int, int, int)> dfs = [&](int u, int p, int d) {
		dis_sum[u] += d;
		for(int v : edge[u])
			if(v != p)
				dfs(v, u, d + 1);
	};

	while(it < n) {
		cur = eve[it].first;
		while(it < n && eve[it].first == cur)
			dfs(eve[it].second, eve[it].second, 0), it++;
		for(int i = 0; i < n; i++) {
			ans = max(ans, ll(n) * it - dis_sum[i] - cur);
		}
	}
	cout << ans << '\n';
}
