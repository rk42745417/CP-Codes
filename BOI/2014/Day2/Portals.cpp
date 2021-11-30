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

const int N = 1001;
int dis[N][N], up[N][N], dw[N][N], le[N][N], ri[N][N], mn[N][N];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

signed main() {
	int n, m;
	cin >> n >> m;
	vector<string> arr(n + 2);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] = '#' + arr[i];
		arr[i].push_back('#');
	}
	arr[0] = arr[n + 1] = string(m + 2, '#');

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(arr[i][j] != '#') {
				if(arr[i][j - 1] == '#')
					le[i][j] = j;
				else
					le[i][j] = le[i][j - 1];
				if(arr[i - 1][j] == '#')
					up[i][j] = i;
				else
					up[i][j] = up[i - 1][j];
			}
		}
	}
	for(int i = n; i; i--) {
		for(int j = m; j; j--) {
			if(arr[i][j] != '#') {
				if(arr[i][j + 1] == '#')
					ri[i][j] = j;
				else
					ri[i][j] = ri[i][j + 1];
				if(arr[i + 1][j] == '#')
					dw[i][j] = i;
				else
					dw[i][j] = dw[i + 1][j];
			}
		}
	}

	{
		memset(mn, 0x3f, sizeof mn);
		queue<pair<int, int>> bfs;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(le[i][j] == j || ri[i][j] == j || up[i][j] == i || dw[i][j] == i)
					mn[i][j] = 0, bfs.push({i, j});
		while(!bfs.empty()) {
			auto [a, b] = bfs.front();
			bfs.pop();
			for(int i = 0; i < 4; i++) {
				int x = a + dx[i], y = b + dy[i];
				if(arr[x][y] != '#' && mn[x][y] > mn[a][b] + 1) {
					mn[x][y] = mn[a][b] + 1;
					bfs.push({x, y});
				}
			}
		}
	}

	memset(dis, 0x3f, sizeof dis);

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> bfs;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(arr[i][j] == 'S') {
				bfs.push({0, i, j});
				dis[i][j] = 0;
			}
		}
	}
	while(!bfs.empty()) {
		auto [d, x, y] = bfs.top();
		bfs.pop();
		if(dis[x][y] > d)
			continue;
		if(arr[x][y] == 'C') {
			cout << d << '\n';
			break;
		}

		int g = dis[x][y] + mn[x][y] + 1;
		if(dis[x][le[x][y]] > g) {
			dis[x][le[x][y]] = g;
			bfs.push({g, x, le[x][y]});
		}
		if(dis[x][ri[x][y]] > g) {
			dis[x][ri[x][y]] = g;
			bfs.push({g, x, ri[x][y]});
		}
		if(dis[up[x][y]][y] > g) {
			dis[up[x][y]][y] = g;
			bfs.push({g, up[x][y], y});
		}
		if(dis[dw[x][y]][y] > g) {
			dis[dw[x][y]][y] = g;
			bfs.push({g, dw[x][y], y});
		}

		for(int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(arr[tx][ty] != '#') {
				if(dis[tx][ty] > dis[x][y] + 1) {
					dis[tx][ty] = dis[x][y] + 1;
					bfs.push({dis[tx][ty], tx, ty});
				}
			}
		}
	}
}
