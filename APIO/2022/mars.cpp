// 14/100
#include "mars.h"
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

inline int id(int a, int b, int n) {
	return a * n + b;
}
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string solve(string s, int n) {
	//debug(s);
	vector<vector<bool>> vis(n, vector<bool>(n));
	int ans = 0;
	function<void(int, int)> dfs = [&](int x, int y) {
		vis[x][y] = true;
		for(int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= n || s[id(a, b, n)] == '0' || vis[a][b])
				continue;
			dfs(a, b);
		}
	};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(s[id(i, j, n)] == '1' && !vis[i][j])
				dfs(i, j), ans++;
	//debug(ans);
	string res;
	for(int i = 0; i < 100; i++) {
		if(i < 30)
			res += '0' | (ans >> i & 1);
		else
			res += '0';
	}
	return res;
}
std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n) {
	assert(n <= 4);
	string ans = string(100, '0');
	if(k == 0) {
		for(int x = 0; x < 3; x++)
			for(int y = 0; y < 3; y++)
				ans[id(i + x, j + y, n * 2 + 1)] = a[x][y][0];
		if(n == 1)
			return solve(ans, n * 2 + 1);
		return ans;
	}
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				ans[i] |= a[j][k][i];
	if(k == n - 1)
		return solve(ans, n * 2 + 1);
	return ans;
}
