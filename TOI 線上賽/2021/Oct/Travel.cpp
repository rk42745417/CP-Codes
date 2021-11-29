// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = [] {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<bool> vis(n + 1);
	vector<vector<int>> edge(n + 1), redge(n + 1);
	vector<int> pa(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		redge[v].push_back(u);
	}
	vector<int> st;
	st.reserve(n);
	function<void(int)> dfs = [&](int u) {
		vis[u] = true;
		for(int v : edge[u])
			if(!vis[v])
				dfs(v);
		st.push_back(u);
	};
	function<void(int, int)> dfs2 = [&](int u, int p) {
		pa[u] = p;
		for(int v : redge[u])
			if(!pa[v])
				dfs2(v, p);
	};
	for(int i = 1; i <= n; i++) {
		if(vis[i])
			continue;
		dfs(i);
	}
	reverse(st.begin(), st.end());
	int t = 1;
	for(int u : st)
		if(!pa[u])
			dfs2(u, t++);
	vector<vector<int>> nwedge(t + 1);
	vector<int> cnt(t + 1);
	for(int u = 1; u <= n; u++) {
		for(int v : edge[u]) {
			if(pa[v] != pa[u]) {
				nwedge[pa[u]].push_back(pa[v]);
				cnt[pa[v]]++;
			}
		}
	}
	function<void(int)> dfs3 = [&](int u) {
		vis[u] = true;
		for(int v : nwedge[u]) {
			cnt[v]--;
		}
		for(int v : nwedge[u]) {
			if(!cnt[v] && !vis[v]) {
				dfs3(v);
				return;
			}
		}
	};
	fill(vis.begin(), vis.end(), false);
	dfs3(pa[1]);

	for(int i = 1; i <= n; i++) {
		if(!vis[pa[i]])
			return cout << "No\n", 0;
	}
	cout << "Yes\n";
}
