// 100/100
/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*--------------------------------------------------------------------------------------*/

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
signed main() { EmiliaMyWife
	int r, c;
	cin >> r >> c;
	vector<vector<int>> arr(r + 2, vector<int>(c + 2, -1));
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			cin >> arr[i][j];
	int ans = 0;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++) {
			int cnt = 0;
			for(int k = 0; k < 8; k++)
				if(arr[i + dx[k]][j + dy[k]] == arr[i][j])
					cnt++;
			ans += !cnt;
		}
	cout << ans << '\n';
}
