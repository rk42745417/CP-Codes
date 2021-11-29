// 100/100
#include<bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

signed main() { EmiliaMyWife
	int n, m;
	cin >> n >> m;
	auto check = [&] (int a, int b) { return a>=0&&a<n&&b>=0&&b<m; };
	vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(4, INF)));
	vector<vector<int>> arr(n, vector<int>(m));
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y;
	cin >> x >> y;
	for(int i = 0, a, b; i < x; i++)
		cin >> a >> b, arr[a][b] = 1;
	for(int i = 0, a, b; i < y; i++)
		cin >> a >> b, arr[a][b] = 2;
	queue<pair<pair<int, int>, int>> bfs;
	bfs.push({{a, b}, 3});
	dis[a][b][3] = 0;
	while(!bfs.empty()) {
		const auto w = bfs.front();
		bfs.pop();
		int health = w.second, x = w.first.first, y = w.first.second;
		for(int i = 0; i < 4; i++) {
			if(!check(x + dx[i], y + dy[i]))
				continue;
			if(arr[x + dx[i]][y + dy[i]] == 1)
				continue;
			int c = health;
			if(arr[x + dx[i]][y + dy[i]] == 2)
				c--;
			if(!c)
				continue;
			if(dis[x + dx[i]][y + dy[i]][c] <= dis[x][y][health] + 1)
				continue;
			dis[x + dx[i]][y + dy[i]][c] = dis[x][y][health] + 1;
			bfs.push({{x + dx[i], y + dy[i]}, c});
		}
	}
	int ans = *min_element(dis[c][d].begin(), dis[c][d].end());
	cout << (ans == INF ? -1 : ans) << '\n';
}
