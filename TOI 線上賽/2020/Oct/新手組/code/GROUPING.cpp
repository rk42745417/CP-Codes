/*
Grouping
100/100
00:13:31
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
/*-----------------------------------------------------------------------------------------------------*/

signed main() { EmiliaMyWife
	int n, num = 1, mx = -1;
	ll x;
	cin >> n >> x;
	for(int c = 1; x; c++) {
		int res = 0;
		for(int i = 0; i < n; i++)
			res += x % 10, x /= 10;
		if(res >= mx)
			mx = res, num = c;
	}
	cout << num << ' ' << mx << '\n';
}
