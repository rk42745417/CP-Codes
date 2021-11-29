#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using uint = uint32_t;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double EPS = 1e-6;

vector<pair<int, int>> d[4];
string arr[1000];
int vis[1000][1000][4];
int n, m;
bool ok(int x, int y) { return x>=0 && x<n && y>=0 && y<m; }
vector<vector<int>> ans;

bool solve(int x, int y, int dir) {
	if(!ok(x, y))
		return 0;
	if(vis[x][y][dir])
		return vis[x][y][dir] > 0;
	for(const auto &[a, b] : d[dir]) {
		if(!ok(x + a, y + b) || arr[x + a][y + b] == 'o') {
			vis[x][y][dir] = -1;
			return 0;
		}
	}
	vis[x][y][dir] = 1;
	solve(x, y + 1, dir);
	solve(x, y - 1, dir);
	solve(x, y, (dir + 1) % 4);
	solve(x, y, (dir - 1 + 4) % 4);
	if(!solve(x + 1, y, dir)) {
		ans.push_back({x, y, dir});
		return 1;
	}
	return 1;
}

signed main() { EmiliaMyWife
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	pair<int, int> center;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(arr[i][j] == 'X')
				center = {i, j};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(arr[i][j] == 'x' || arr[i][j] == 'X')
				d[0].push_back({i - center.first, j - center.second});
    for(int i = 1; i < 4; i++)
        for(const auto &[a, b] : d[i - 1])
            d[i].push_back({-b, a});
	solve(center.first, center.second, 0);
	sort(ans.begin(), ans.end());
	for(const auto &x : ans)
		cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
}
