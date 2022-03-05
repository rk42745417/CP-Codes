// 70/70
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
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> vis(n, vector<bool>(m));
	vector<string> arr(n);
	for(auto &a : arr)
		cin >> a;

	bool ok = 1;
	set<pair<int, int>> has;
	
	function<void(int, int)> dfs = [&](int x, int y) {
		vis[x][y] = true;
		for(int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= m) {
				ok = false;
				continue;
			}
			if(arr[a][b] == '#')
				has.insert({a, b});
			else if(!vis[a][b])
				dfs(a, b);
		}
	};
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] || arr[i][j] == '#')
				continue;
			ok = true;
			has.clear();
			dfs(i, j);
			if(!ok)
				continue;

			int u = -INF, d = INF, l = INF, r = -INF;
			for(const auto &[x, y] : has) {
				u = max(u, y);
				d = min(d, y);
				l = min(l, x);
				r = max(r, x);
			}
			int a, b;
			if(u - d != r - l || (u - d) % 2)
				continue;
			a = (l + r) / 2, b = (u + d) / 2;

			bool ok = 1;
			for(const auto &[x, y] : has)
				ok &= abs(x - a) + abs(y - b) == r - a;
			if(ok && has.size() == (r - a) * 4)
				ans++;
		}
	}
	cout << ans << '\n';
}
