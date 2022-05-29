// 64.63/100
#include "perm.h"
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
static int Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

vector<int> construct_permutation(long long k) {
	k--;
	int w = 0, g = 0;
	for(int i = 0; i < 60; i++)
		if(k >> i & 1)
			w += i, g++;
	debug(w);
	w += g;
	vector<int> arr;
	for(int i = 0; i < 60; i++) {
		if(k >> i & 1) {
			int r = i;
			for(int j = w - r + 1; j <= w; j++)
				arr.push_back(j);
			w -= r;
		}
	}
	while(w)
		arr.push_back(w--);
	for(int &a : arr)
		a--;
	return arr;
}
