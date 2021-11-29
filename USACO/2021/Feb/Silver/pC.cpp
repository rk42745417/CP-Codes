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

signed main() { EmiliaMyWife
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		vector<int> tmp(n, INF);
		for(int j = i; j < n; j++) {
			for(int k = 0; k < n; k++)
				tmp[k] = min(tmp[k], arr[j][k]);
			int prv = -1, w = -1;
			for(int k = 0; k < n; k++) {
				if(tmp[k] == 100)
					w = k;
				if(tmp[k] < 100) {
					prv = k;
					w = -1;
				}
				ans += max(0, w - prv);
			}
		}
	}
	cout << ans << '\n';
}
