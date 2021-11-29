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
	int n, k;
	cin >> n >> k;
	k--;
	vector<int> arr(n + 1);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = (arr.back() + 11) / 12 * 12;

	vector<int> w;
	for(int i = 1; i <= n; i++) {
		int x = arr[i] / 12 * 12 - (arr[i - 1] + 11) / 12 * 12;
		w.push_back(x);
	}
	sort(w.begin(), w.end(), greater<int>());
	for(int i = 0; i < k; i++)
		if(w[i] > 0)
			ans -= w[i];
	cout << ans << '\n';
}
