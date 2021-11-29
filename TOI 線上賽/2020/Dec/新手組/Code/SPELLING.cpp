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
	string a, b;
	cin >> a >> b;
	vector<bool> vis(a.size());
	for(char c : b) {
		int ans = -1;
		for(int i = 0; i < a.size(); i++) {
			if(a[i] != c)
				continue;
			if(vis[i])
				continue;
			vis[i] = true;
			ans = i + 1;
			break;
		}
		if(~ans)
			cout << ans << ' ';
		else
			cout << 'X' << ' ';
	}
}
