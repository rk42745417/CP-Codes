// 60/100
#include "game.h"
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

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/********************************** Pragma Optimization **********************/
const int N = 3e5 + 25;
vector<int> edge[N];
int mx[N];
bool ok;
int n, k;
inline void update(int u, int val) {
	mx[u] = max(mx[u], val);
	ok |= u < k && mx[u] >= u;
}
void init(int n, int k) {
	::n = n;
	::k = k;
	for(int i = 0; i < n; i++)
		mx[i] = -INF;
	for(int i = 1; i < k; i++)
		mx[i] = i - 1;
}
int bfs[N], h = 0, t = 0;
int add_teleporter(int u, int v) {
	if(u == v)
		return u < k;

	int r = mx[u];
	if(u < k)
		r = max(u, r);
	if(mx[v] >= r) {
		edge[u].push_back(v);
		return false;
	}

	h = t = 0;
	update(v, r);
	bfs[t++] = v;
	while(h < t) {
		int x = bfs[h++];
		for(int y : edge[x]) {
			if(mx[y] < r) {
				update(y, r);
				bfs[t++] = y;
			}
		}
	}
	edge[u].push_back(v);
	return ok;
}
