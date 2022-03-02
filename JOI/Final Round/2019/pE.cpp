// 4/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(4e15) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n + 1);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	vector<int> col(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> col[i];
	vector<vector<int>> has(n + 1);
	vector<bool> owo(m + 1);
	function<void(int, int, int)> dfs = [&](int u, int p, int d) {
		for(int v : edge[u])
			if(v != p)
				dfs(v, u, d + 1);
		has[d].push_back(col[u]);
	};
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= n; j++)
			has[j].clear();
		for(int j = 0; j <= m; j++)
			owo[j] = false;
		dfs(i, i, 0);
		int res = 0;
		for(int j = 1; j <= n; j++)
			if(has[j].size() == 1 && !owo[has[j][0]])
				res++, owo[has[j][0]] = true;
		cout << res << '\n';
	}
}
