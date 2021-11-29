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
const double EPS  = 1e-7;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static auto Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

const int N = 1e5 + 25;
vector<int> edge[N];
int cnt[N], ans = 0, vis = 0, n;
deque<int> has;
bool has_sol() {
	queue<int> bfs;
	for(int i = 1; i <= n; i++)
		if(cnt[i] == 0)
			bfs.push(i);
	int x = 0;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
	x++;
		for(int v : edge[u]) {
		cnt[v]--;
			if(cnt[v] == 0)
				bfs.push(v);
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j : edge[i])
			cnt[j]++;
	return x == n;
}
void dfs() {
	if(ans > 100)
		return;
	if(has.empty()) {
		if(vis == n)
			ans++;
		return;
	}
	int x = -1;
	while(x != has.front() && ans <= 100) {
		int u = has.front();
		has.pop_front();
		vis++;
		if(x == -1)
			x = u;
		for(int v : edge[u]) {
			cnt[v]--;
			if(cnt[v] == 0) {
				has.push_back(v);
			}
		}
		dfs();
		for(int v : edge[u]) {
			if(cnt[v] == 0)
				has.pop_back();
			cnt[v]++;
		}
		has.push_back(u);
		vis--;
	}
}
signed main() {
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		char c;
		cin >> u >> c >> v;
		if(c == '<')
			edge[u].push_back(v), cnt[v]++;
		else
			edge[v].push_back(u), cnt[u]++;
	}
	for(int i = 1; i <= n; i++)
		if(cnt[i] == 0)
			has.push_back(i);
	if(!has_sol())
		return cout << -1.0 << '\n', 0;
	dfs();
	cout << fixed << setprecision(15);
	if(ans > 100)
		cout << 0.0;
	else
		cout << 100.0 / ans;
	cout << '\n';
}
