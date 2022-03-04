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

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

signed main() {
	int h, w;
	cin >> h >> w;
	auto check = [&](int a, int b) {
		return a >= 0 && a <= h && b >= 0 && b <= w;
	};

	ll a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	vector<vector<int>> dis(h + 1, vector<int>(w + 1, INF));
	for(const auto &[x, y] : arr)
		dis[x][y] = 0;
	queue<pair<int, int>> bfs;
	for(int i = 0; i <= h; i++)
		for(int j = 0; j <= w; j++)
			if(dis[i][j] == 0)
				bfs.push({i, j});
	while(!bfs.empty()) {
		auto [u, v] = bfs.front();
		bfs.pop();
		for(int i = 0; i < 4; i++) {
			int x = u + dx[i], y = v + dy[i];
			if(check(x, y) && dis[x][y] > dis[u][v] + 1)
				dis[x][y] = dis[u][v] + 1, bfs.push({x, y});
		}
	}

	vector<vector<vector<ll>>> ans(h + 1, vector<vector<ll>>(w + 1, vector<ll>(5, LINF)));
	ans[arr[0].first][arr[0].second][0] = 0;
	priority_queue<tuple<ll, int, int, int>, vector<tuple<ll, int, int, int>>, greater<tuple<ll, int, int, int>>> pq;
	pq.push({0, arr[0].first, arr[0].second, 0});
	while(!pq.empty()) {
		auto [d, u, v, w] = pq.top();
		pq.pop();
		if(d > ans[u][v][w])
			continue;
		ll cost = 0;
		if(w == 0) {
			for(int i = 1; i <= 4; i++) {
				if(ans[u][v][i] > ans[u][v][w] + b) {
					ans[u][v][i] = ans[u][v][w] + b;
					pq.push({ans[u][v][i], u, v, i});
				}
			}
			cost = c;
		}
		else {
			if(ans[u][v][0] > ans[u][v][w] + c * dis[u][v]) {
				ans[u][v][0] = ans[u][v][w] + c * dis[u][v];
				pq.push({ans[u][v][0], u, v, 0});
			}
			cost = a;
		}
		for(int i = 0; i < 4; i++) {
			int x = u + dx[i], y = v + dy[i];
			if((w == 0 || i + 1 == w) && check(x, y) && ans[x][y][w] > d + cost) {
				ans[x][y][w] = d + cost;
				pq.push({ans[x][y][w], x, y, w});
			}
		}
	}

	ll ret = LINF;
	for(int i = 0; i <= h; i++)
		for(int j = 0; j <= w; j++)
			for(int k = 0; k < 2; k++)
				ret = min(ret, ans[i][j][k] + c * (abs(i - arr[n - 1].first) + abs(j - arr[n - 1].second)));
	cout << ret << '\n';
}
