/*
Knight
00:07:50
100/100
*/
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = long double;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie();

const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

signed main() { EmiliaMyWife
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> ans(n, vector<int>(m, INF));
	cin >> a >> b;
	ans[a][b] = 0;
	queue<pair<int, int>> bfs;
	auto chk = [&] (int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	bfs.push({a, b});
	while(!bfs.empty()) {
		auto [x, y] = bfs.front();
		bfs.pop();
		for(int i = 0; i < 8; i++)
			if(chk(x + dx[i], y + dy[i]) && ans[x + dx[i]][y + dy[i]] > ans[x][y] + 1)
				ans[x + dx[i]][y + dy[i]] = ans[x][y] + 1, bfs.push({x + dx[i], y + dy[i]});
	}
	cin >> a >> b;
	if(ans[a][b] == INF)
		cout << "-1\n";
	else
		cout << ans[a][b] << '\n';
}
