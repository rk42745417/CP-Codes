/*
Fertilizer
100/100
00:25:45
*/
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
	int s, e, a;
	cin >> s >> e >> a;
	a++;
	for(int i = 0; a; i++) {
		if(s >= e)
			return cout << i + 1 << '\n', 0;
		if(i % 10 == 0)
			a--;
		if(i % 10 == 8 || i % 10 == 9)
			continue;
		if(i % 3 == 2)
			s += s / 3;
		else
			s += s / 10;
	}
	cout << "unsalable\n";
}
