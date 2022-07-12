// 7/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 4e18;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> edge(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edge[u].push_back({v, c});
		edge[v].push_back({u, c});
	}
	vector<bool> vis(n + 1);
	ll mx = -LINF, mn = LINF;
	function<void(int, ll)> dfs = [&](int u, ll c) {
		vis[u] = true;
		if(u == n) {
			mx = max(mx, c);
			mn = min(mn, c);
			vis[u] = false;
			return;
		}
		for(const auto &[v, d] : edge[u])
			if(!vis[v])
				dfs(v, c + d);
		vis[u] = false;
	};
	dfs(1, 0);
	cout << (mx != mn) << '\n';
}
