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

	int lst = publish(arr);

	// let a be count of numbers in the first i-1 numbers that are higher than a[i].
	// let b be count of numbers in the first i-1 mumbers that are lower than a[i]
	// then a + b = i and a - b = lst - cur - 1
	// b = (i + cur - lst - 1) / 2
	for(int i = 1; i < n; i++) {
		for(int j = i; j; j--)
			swap(arr[j - 1], arr[j]);
		int cur = publish(arr);
		int a = (i + lst - cur) / 2;
		int b = (i + cur - lst) / 2;
		for(int j = 1; j <= b; j++)
			swap(arr[j - 1], arr[j]);
		lst -= a;
	}
	answer(arr);
}
