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
#include "art.h"
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"
#define print(x) emilia_mata_tenshi(#x, begin(x), end(x))
template<typename T> void emilia_mata_tenshi(const char *s, T l, T r) {
	cerr << "\e[1;33m" << s << " = [";
	while(l != r) {
		cerr << *l;
		cerr << (++l == r ? ']' : ',');
	}
	cerr << "\e[0m\n";
}

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

void solve(int n) {
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		arr[i] = i + 1;
	shuffle(arr.begin(), arr.end(), mt19937(time(0)));
	int x = publish(arr);

	vector<int> res(n);
	int lst = 0;
	for(int i = 0; i + 1 < n; i++) {
		swap(arr[i], arr[n - 1]);
		int y = publish(arr);
		res[i] = y;
		if(y > x)
			swap(arr[i], arr[n - 1]);
		else {
			res[i] = x;
			x = y;
			lst = i;
		}
	}

	vector<int> ans(n);
	ans[n - 1] = arr[n - 1];
	vector<int> cur;
	for(int i = n - 2; ~i; i--)
		cur.push_back(i);

	for(int i = 0; i + 1 < n; i++) {
		int y = res[i];
		if(i < lst) {
			swap(arr[i], arr[n - 1]);
			y = publish(arr);
			swap(arr[i], arr[n - 1]);
		}
		y = (y - x) / 2;
		ans[cur[y]] = arr[i];
		cur.erase(cur.begin() + y);
	}
	answer(ans);
}
