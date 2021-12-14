// 100/100
/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*--------------------------------------------------------------------------------------*/

struct dat {
	int v, c;
	ll p;
	bool operator<(const dat &b) { return c < b.c; }
};

signed main() { EmiliaMyWife
	int n, m;
	cin >> n >> m;
	vector<vector<dat>> edge(n + 1), nwedge(n + 1);
	set<pair<int, int>> has;
	vector<ll> dis(n + 1, LINF), sum(m + 1);
	for(int i = 0, a, b, c, d; i < m; i++) {
		cin >> a >> b >> c >> d;
		edge[a].push_back({b, c, d});
		edge[b].push_back({a, c, d});
	}
	for(int i = 1; i <= n; i++) {
		for(const auto &[v, c, p] : edge[i])
			sum[c] += p;
		for(const auto &[v, c, p] : edge[i])
			nwedge[i].push_back({v, c, sum[c] - p});
		for(const auto &[v, c, p] : edge[i])
			sum[c] -= p;
		sort(nwedge[i].begin(), nwedge[i].end());
	}
	dis[1] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, 1});
	while(!pq.empty()) {
		const auto [d, u] = pq.top();
		pq.pop();
		if(d > dis[u])
			continue;
		for(const auto &[v, c, p] : edge[u]) {
			if(dis[v] > dis[u] + p) {
				dis[v] = dis[u] + p;
				pq.push({dis[v], v});
			}
			if(has.count(make_pair(v, c)))
				continue;
			has.insert({v, c});
			int it = lower_bound(nwedge[v].begin(), nwedge[v].end(), (dat){-1, c, -1}) - nwedge[v].begin();
			while(it < nwedge[v].size() && nwedge[v][it].c == c) {
				if(dis[nwedge[v][it].v] > dis[u] + nwedge[v][it].p) {
					dis[nwedge[v][it].v] = dis[u] + nwedge[v][it].p;
					pq.push({dis[nwedge[v][it].v], nwedge[v][it].v});
				}
				it++;
			}
		}
		for(const auto &[v, c, p] : nwedge[u]) {
			if(dis[v] > dis[u] + p) {
				dis[v] = dis[u] + p;
				pq.push({dis[v], v});
			}
		}
	}
	if(dis[n] != LINF)
		cout << dis[n] << '\n';
	else
		cout << "-1\n";
}
