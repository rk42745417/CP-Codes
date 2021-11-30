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
const double EPS = 1e-8;
const ll LINF = ll(2e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> edge(n + 1);
	vector<bool> has(m), vise(m);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
	}

	vector<vector<int>> ans;
	ans.reserve(n);
	vector<int> cur;
	cur.reserve(n);
	vector<bool> vis(n + 1);
	function<int(int)> dfs = [&](int u) {
		while(!edge[u].empty()) {
			vis[u] = true;
			while(!edge[u].empty() && has[edge[u].back().second])
				edge[u].pop_back();
			int x = edge[u].size();
			x--;
			while(~x && (vise[edge[u][x].second] || has[edge[u][x].second])) {
				x--;
			}
			if(x == -1)
				return 0;

			auto [v, id] = edge[u][x];
			vise[id] = true;
			if(vis[v]) {
				cur.push_back(u);
				has[id] = true;
				vise[id] = false;
				vis[u] = false;
				return v;
			}
			else {
				int d = dfs(v);
				if(d) {
					cur.push_back(u);
					has[id] = true;
					vise[id] = false;
					vis[u] = false;
					if(u == d) {
						ans.push_back(cur);
						cur.clear();
						continue;
					}
					return d;
				}
			}
		}
		return 0;
	};
	for(int i = 1; i <= n; i++)
		dfs(i);
	for(const auto &a : ans) {
		for(int i = 0; i < a.size(); i++)
			cout << a[i] << " \n"[i + 1 == a.size()];
	}
}
