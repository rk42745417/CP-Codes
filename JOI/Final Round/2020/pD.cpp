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
const ll LINF = ll(4e18) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 207, M = 5e4 + 25;
struct dat {
	int v, c, i;
};
vector<dat> edge[N], redge[N];
bool is[M];
int n;
int len[M], cost[M];
ll dis[N][N];
pair<int, int> edges[M];

ll dijk(int s, int t, int id) {
	vector<ll> dis(n + 1, LINF);
	vector<bool> vis(n + 1);
	dis[s] = 0;
	while(true) {
		int u = -1;
		for(int i = 1; i <= n; i++)
			if(!vis[i] && (u == -1 || dis[u] > dis[i]))
				u = i;
		if(u == -1)
			break;
		vis[u] = true;
		for(const auto &[v, c, i] : edge[u])
			if(i != id && dis[v] > dis[u] + c)
				dis[v] = dis[u] + c;
	}
	return dis[t];
}
ll brute(int id) {
	if(~id)
		edge[edges[id].second].push_back({edges[id].first, len[id], -1});
	ll ret = dijk(1, n, id) + dijk(n, 1, id);
	if(~id)
		edge[edges[id].second].pop_back();
	return ret;
}
void dijk2(int s) {
	vector<ll> dis(n + 1, LINF);
	vector<int> lst(n + 1, -1);
	dis[s] = 0;
	vector<bool> vis(n + 1);
	while(true) {
		int u = -1;
		for(int i = 1; i <= n; i++)
			if(!vis[i] && (u == -1 || dis[u] > dis[i]))
				u = i;
		if(u == -1 || dis[u] == LINF)
			break;
		if(~lst[u])
			is[lst[u]] = true;
		vis[u] = true;
		for(const auto &[v, c, id] : edge[u])
			if(dis[v] > dis[u] + c)
				dis[v] = dis[u] + c, lst[v] = id;
	}
}
signed main() {
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		edge[u].push_back({v, c, i});
		redge[v].push_back({u, c, i});
		cost[i] = d;
		len[i] = c;
		edges[i] = {u, v};
	}

	dijk2(1);
	dijk2(n);
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(i != j)
				dis[i][j] = LINF;
	for(int i = 0; i < m; i++)
		dis[edges[i].first][edges[i].second] = min<ll>(dis[edges[i].first][edges[i].second], len[i]);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	ll ans = dis[1][n] + dis[n][1];
	for(int i = 0; i < m; i++) {
		const auto &[u, v] = edges[i];
		if(is[i])
			ans = min(ans, brute(i) + cost[i]);
		else
			ans = min(ans, min(dis[1][n], dis[1][v] + dis[u][n] + len[i]) + min(dis[n][1], dis[n][v] + dis[u][1] + len[i])  + cost[i]);
	}
	if(ans > 2e9)
		cout << "-1\n";
	else
		cout << ans << '\n';
}
