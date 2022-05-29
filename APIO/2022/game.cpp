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

const int N = 3e4 + 25, K = 1000;
bool ok[K][N];
vector<int> edge[N];
int mn[K];
int n, k;
void update(int a, int u) {
	ok[a][u] = true;
	mn[a] = min(mn[a], u);
}
void init(int n, int k) {
	assert(k <= 1000);
	::n = n;
	::k = k;
	for(int i = 0; i < k; i++) {
		mn[i] = INF;
		for(int j = i + 1; j < k; j++)
			update(i, j);
	}
}
int add_teleporter(int u, int v) {
	if(u == v)
		return u < k;
	for(int i = 0; i < k; i++) {
		if((u != i && !ok[i][u]) || ok[i][v])
			continue;
		queue<int> bfs;
		bfs.push(v);
		update(i, v);
		while(!bfs.empty()) {
			int x = bfs.front();
			bfs.pop();
			for(int y : edge[x])
				if(!ok[i][y]) {
					update(i, y);
					bfs.push(y);
				}
		}
	}
	for(int i = 0; i < k; i++)
		if(mn[i] <= i)
			return true;
	edge[u].push_back(v);
	return false;
}
