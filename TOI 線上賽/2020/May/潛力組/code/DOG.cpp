/*
DOG
100/100
00:14:56
*/
#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n;
bool check(int x, int y) {
	return (x>=0 && y>=0 && x<n && y<n);
}
bitset<3000> vis[3000];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b;
	cin >> n >> a >> b;
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++)
		for(int j =0 ; j < n; j++)
			cin >> arr[i][j];
	int ans = 0;
	queue<pair<int,int>> bfs;
	bfs.push({a, b});
	vis[a][b] = true;
	while(!bfs.empty()) {
		int x = bfs.front().first, y = bfs.front().second;
		ans++;
		bfs.pop();

		for(int k = 0; k < 4; k++) {
			int r = x+dx[k], w = y+dy[k];
			if(check(r, w) && !vis[r][w] && abs(arr[x][y]-arr[r][w]) <= 2) {
				bfs.push({r, w});
				vis[r][w] = true;
			}
		}
	}
	cout << ans;

	return 0;
}
