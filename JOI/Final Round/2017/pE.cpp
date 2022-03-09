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

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a;
	vector<int> ans(m + 1, INF);

	vector<pair<int, int>> cnt(m + 1);
	vector<int> owo(m + 1);
	for(int i = 1; i <= m; i++)
		cnt[i].second = i;
	for(int a : arr)
		cnt[a].first++, owo[a]++;
	sort(cnt.begin(), cnt.end(), greater<>());

	for(int st : {1, 2}) {
		vector<map<int, int>> adj(m + 1);
		for(int i = st; i < n; i += 2) {
			int a = arr[i - 1], b = arr[i];
			if(a != b) {
				adj[a][b]++;
				adj[b][a]++;
			}
		}

		for(int i = 1; i <= m; i++) {
			int res = 0;
			for(const auto &[c, j] : cnt) {
				if(j == i)
					continue;
				res = max(res, c - adj[i][j]);
				if(adj[i][j] == 0)
					break;
			}
			ans[i] = min(ans[i], n - (res + owo[i]));
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
}
