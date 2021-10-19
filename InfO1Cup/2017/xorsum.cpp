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
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0;
	for(int a : arr)
		ans ^= a + a;

	for(int i = 0; i < 30; i++) {
		vector<int> owo[2];
		for(int a : arr)
			owo[a >> i & 1].push_back(a);

		int w = 0, u = 1 << i;
		for(int t = 0; t < 2; t++) {
			auto &cur = owo[t], oth = owo[!t];

			int it = cur.size();
			for(int j = 0; j < cur.size(); j++) {
				while(it && cur[it - 1] % u + cur[j] % u >= u)
					it--;
				w += cur.size() - max(it, j + 1);
			}
			//cout << "here " << i << ' ' << w << '\n';

			if(t)
				break;
			it = oth.size();
			for(int j = 0; j < cur.size(); j++) {
				while(it && oth[it - 1] % u + cur[j] % u >= u)
					it--;
				w += it;
			}
			//cout << "owo " << i << ' ' << w << '\n';
		}

		//cout << i << ' ' << w << '\n';
		if(w & 1)
			ans ^= u;

		int it = 0;
		for(auto &x : owo)
			for(int a : x)
				arr[it++] = a;
	}
	cout << ans << '\n';
}
