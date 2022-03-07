// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(4e18) + ll(2e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> dis(n + 1, INF);
	vector<pair<int, int>> edges(m);
	vector<vector<pair<int, int>>> edge(n + 1);
	for(int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
		edges[i] = {u, v};
	}
	
	queue<int> bfs;
	bfs.push(1);
	dis[1] = 0;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		for(const auto &[v, _] : edge[u])
			if(dis[v] > dis[u] + 1)
				dis[v] = dis[u] + 1, bfs.push(v);
	}

	vector<int> cnt(n + 1);
	for(int i = 2; i <= n; i++) {
		for(const auto &[v, _] : edge[i])
			if(dis[v] == dis[i] - 1)
				cnt[i]++;
	}

	vector<bool> has(n + 1), dele(m);
	int res = 0;
	while(q--) {
		int x;
		cin >> x;
		x--;
		dele[x] = true;
		auto [u, v] = edges[x];

		if(!has[v] && !has[u] && abs(dis[u] - dis[v]) == 1) {
			if(dis[u] > dis[v])
				swap(u, v);

			cnt[v]--;
			queue<int> que;
			if(cnt[v] == 0)
				que.push(v);

			while(!que.empty()) {
				int u = que.front();
				que.pop();
				has[u] = true;
				res++;

				for(const auto &[v, i] : edge[u]) {
					if(!dele[i] && dis[v] == dis[u] + 1) {
						cnt[v]--;
						if(cnt[v] == 0)
							que.push(v);
					}
				}
			}
		}

		cout << res << '\n';
	}
}
