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

const int N = 2e5 + 25;
vector<int> edge[N];
int max_dep[N], ans[N], arr[N], dep[N];
pair<int, int> cal_dia(int u, int p) {
	pair<int, int> res = {0, u};
	for(int v : edge[u]) {
		if(v == p)
			continue;
		auto r = cal_dia(v, u);
		r.first++;
		res = max(res, r);
	}
	return res;
}
void cal_maxdep(int u, int p) {
	max_dep[u] = 0;
	for(int v : edge[u]) {
		if(v == p)
			continue;
		dep[v] = dep[u] + 1;
		cal_maxdep(v, u);
		max_dep[u] = max(max_dep[u], max_dep[v] + 1);
	}
}

int cnt[N], res = 0;
stack<int, vector<int>> cur;
void add(int x) {
	cur.push(x);
	if(cnt[arr[x]] == 0)
		res++;
	cnt[arr[x]]++;
}
void rem() {
	cnt[arr[cur.top()]]--;
	if(cnt[arr[cur.top()]] == 0)
		res--;
	cur.pop();
}
void cal_ans(int u, int p) {
	int mx = 0, smx = 0;
	for(int v : edge[u]) {
		if(v == p)
			continue;
		if(max_dep[v] + 1 > mx)
			swap(mx, smx), mx = max_dep[v] + 1;
		else
			smx = max(smx, max_dep[v] + 1);
	}

	for(int v : edge[u]) {
		if(v == p || max_dep[v] + 1 != mx)
			continue;
		while(!cur.empty() && dep[cur.top()] >= dep[u] - smx)
			rem();
		add(u);
		cal_ans(v, u);
	}

	for(int v : edge[u]) {
		if(v == p || max_dep[v] + 1 == mx)
			continue;
		while(!cur.empty() && dep[cur.top()] >= dep[u] - mx)
			rem();
		add(u);
		cal_ans(v, u);
	}

	while(!cur.empty() && dep[cur.top()] >= dep[u] - max_dep[u])
		rem();
	ans[u] = max(ans[u], res);
}

signed main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
		cin >> arr[i];

	auto [_, d1] = cal_dia(1, 1);
	auto [__, d2] = cal_dia(d1, d1);
	for(int d : {d1, d2}) {
		dep[d] = 0;
		cal_maxdep(d, d);
		cal_ans(d, d);
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}
