// 30/100
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
	vector<ll> cost(m);
	vector<int> con(m);
	vector<bool> tree(m);
	vector<vector<pair<int, int>>> edge(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
		cost[i] = c;
		con[i] = u ^ v;
	}

	vector<int> pa(n + 1, -1);
	vector<ll> dis(n + 1, LINF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dis[1] = 0;
	pq.push({0, 1});
	while(!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if(d > dis[u])
			continue;
		if(~pa[u])
			tree[pa[u]] = true;
		for(const auto &[v, i] : edge[u]) {
			ll c = cost[i];
			if(dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				pa[v] = i;
				pq.push({dis[v], v});
			}
		}
	}

	auto solve = [&](int u, int v, int id) {
		int x = u;
		vector<bool> vis(n + 1);
		while(x) {
			vis[x] = true;
			if(x == 1)
				break;
			x = con[pa[x]] ^ x;
		}
		function<ll(int, ll)> dfs = [&](int u, ll x) {
			if(vis[u])
				return ll(-1);
			vis[u] = true;
			if(u == v)
				return x;
			for(const auto &[v, i] : edge[u]) {
				ll r = dfs(v, x + cost[i]);
				if(~r)
					return r;
			}
			return ll(-1);
		};
		auto r = dfs(n, 0);
		if((~r) && r + cost[id] + dis[u] > dis[n])
			return true;
		return false;
	};

	bool ans = false;
	for(int u = 1; u <= n; u++)
		for(const auto &[v, i] : edge[u])
			if(!tree[i])
				ans |= solve(u, v, i);
	cout << ans << '\n';
}
