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
const ll LINF = 4e18;
const double EPS = 1e-8;

signed main() { EmiliaMyWife
	const string PROBLEM = "vacationgold";
	freopen((PROBLEM + ".in").c_str(), "r", stdin);
	freopen((PROBLEM + ".out").c_str(), "w", stdout);

	int n, m, r, q;
	cin >> n >> m >> r >> q;
	vector<int> is(n + 1);
	vector<vector<pair<int, int>>> edge(n + 1), redge(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edge[u].push_back({v, c});
		redge[v].push_back({u, c});
	}
	for(int i = 1, x; i <= r; i++) {
		cin >> x;
		is[x] = i;
	}
	vector<vector<ll>> dis(r + 1, vector<ll>(r + 1, LINF));
	for(int i = 1; i <= n; i++) {
		if(!is[i])
			continue;
		dis[is[i]][is[i]] = 0;
		for(const auto &[j, c] : edge[i]) {
			if(is[j])
				dis[is[i]][is[j]] = min(dis[is[i]][is[j]], ll(c));
			else {
				for(const auto &[k, d] : edge[j])
					if(is[k])
						dis[is[i]][is[k]] = min(dis[is[i]][is[k]], ll(c) + d);
			}
		}
	}
	for(int k = 1; k <= r; k++)
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= r; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	int valid = 0;
	ll ans = 0;
	map<pair<int, int>, ll> has;
	while(q--) {
		int u, v;
		cin >> u >> v;
		ll res = LINF;
		if(has.count({u, v}))
			res = has[{u, v}];
		else {
			if(is[u] && is[v])
				res = dis[is[u]][is[v]];
			else if(is[u]) {
				for(const auto &[x, c] : redge[v])
					res = min(res, dis[is[u]][is[x]] + c);
			}
			else if(is[v]) {
				for(const auto &[x, c] : edge[u])
					res = min(res, c + dis[is[x]][is[v]]);
			}
			else {
				for(const auto &[x, c] : edge[u])
					for(const auto &[y, d] : redge[v])
						res = min(res, c + dis[is[x]][is[y]] + d);
			}
			has[{u, v}] = res;
		}
		if(res != LINF)
			valid++, ans += res;
	}
	cout << valid << '\n' << ans << '\n';
}
