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

const int N = 2e6 + 25;
int arr[N], dp[N], dp2[N], l;
int dfs(const string &s, int n, int cur) {
	if(n == l)
		return arr[cur];
	if(s[n] == '?')
		return dfs(s, n + 1, cur) + dfs(s, n + 1, cur | (1 << n));
	if(s[n] == '1')
		return dfs(s, n + 1, cur | (1 << n));
	return dfs(s, n + 1, cur);
}
int dfs2(const string &s, int n, int cur, int cnt) {
	if(n == l)
		return dp[cur] * (cnt % 2 ? -1 : 1);
	if(s[n] == '?')
		return dfs2(s, n + 1, cur | (1 << n), cnt);
	if(s[n] == '0')
		return dfs2(s, n + 1, cur, cnt);
	return dfs2(s, n + 1, cur | (1 << n), cnt) + dfs2(s, n + 1, cur, cnt + 1);
}
int dfs3(const string &s, int n, int cur, int cnt) {
	if(n == l)
		return dp2[cur] * (cnt % 2 ? -1 : 1);
	if(s[n] == '?')
		return dfs3(s, n + 1, cur, cnt);
	if(s[n] == '1')
		return dfs3(s, n + 1, cur | (1 << n), cnt);
	return dfs3(s, n + 1, cur | (1 << n), cnt + 1) + dfs3(s, n + 1, cur, cnt);
}

signed main() {
	int q;
	cin >> l >> q;
	{
		string s;
		cin >> s;
		for(int i = 0; i < (1 << l); i++)
			arr[i] = dp[i] = dp2[i] = s[i] - '0';
	}
	for(int i = 0; i < l; i++)
		for(int j = 0; j < (1 << l); j++)
			if(j >> i & 1)
				dp[j] += dp[j ^ (1 << i)];
	for(int i = 0; i < l; i++)
		for(int j = 0; j < (1 << l); j++)
			if(j >> i & 1 ^ 1)
				dp2[j] += dp2[j ^ (1 << i)];

	while(q--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int cnt = 0, cnt2 = 0;
		for(char c : s) {
			cnt += c == '?';
			cnt2 += c == '1';
		}
		int cnt3 = l - (cnt + cnt2);
		if(cnt <= min(cnt3, cnt2))
			cout << dfs(s, 0, 0) << '\n';
		else if(cnt2 <= min(cnt, cnt3))
			cout << dfs2(s, 0, 0, 0) << '\n';
		else
			cout << dfs3(s, 0, 0, 0) << '\n';
	}
}
