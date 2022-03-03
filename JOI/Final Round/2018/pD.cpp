// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const ll LINF = ll(4e18) + ll(2e15);
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m, s, t, a, b;
	cin >> n >> m >> s >> t >> a >> b;
	vector<vector<pair<int, int>>> edge(n + 1);
	while(m--) {
		int u, v, c;
		cin >> u >> v >> c;
		edge[u].push_back({v, c});
		edge[v].push_back({u, c});
	}
	auto dijk = [&](vector<ll> &dis, int st) {
		dis.resize(n + 1, LINF);
		dis[st] = 0;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({0, st});

		while(!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();
			if(d > dis[u])
				continue;
			for(const auto &[v, c] : edge[u])
				if(dis[v] > dis[u] + c)
					dis[v] = dis[u] + c, pq.push({dis[v], v});
		}
	};
	vector<ll> diss, dist;
	dijk(diss, s);
	dijk(dist, t);
	const ll mn = diss[t];

	vector<array<ll, 4>> ans(n + 1, {LINF, LINF, LINF, LINF});
	ans[a][0] = 0;
	priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
	pq.push({0, a, 0});
	while(!pq.empty()) {
		auto [d, u, w] = pq.top();
		pq.pop();
		if(d > ans[u][w])
			continue;
		for(const auto &[v, c] : edge[u]) {
			if((w == 0 || w == 3) && ans[v][w] > ans[u][w] + c) {
				ans[v][w] = ans[u][w] + c;
				pq.push({ans[v][w], v, w});
			}
			if((w == 1 || w == 2) && ans[v][3] > ans[u][w] + c) {
				ans[v][3] = ans[u][w] + c;
				pq.push({ans[v][3], v, 3});
			}
			if((w == 0 || w == 1) && diss[u] + dist[u] == mn && diss[v] + dist[v] == mn && diss[v] - diss[u] == c) {
				if(ans[v][1] > ans[u][w]) {
					ans[v][1] = ans[u][w];
					pq.push({ans[v][1], v, 1});
				}
			}
			if((w == 0 || w == 2) && diss[u] + dist[u] == mn && diss[v] + dist[v] == mn && diss[u] - diss[v] == c) {
				if(ans[v][2] > ans[u][w]) {
					ans[v][2] = ans[u][w];
					pq.push({ans[v][2], v, 2});
				}
			}
		}
	}
	cout << min({ans[b][0], ans[b][1], ans[b][2], ans[b][3]}) << '\n';
}
