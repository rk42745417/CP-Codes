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
const double EPS  = 1e-7;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static int Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

const int N = 1e5 + 25, LGN = 18;
vector<int> tmp_edge[N], edge[N];
int dep[N], arr[N], anc[LGN][N], in[N], out[N], t = 1;
ll pen[N];
struct fenwicktree {
	int arr[N << 1];
	void edt(int p, int v) {
		for(; p < (N << 1); p += p & -p)
			arr[p] += v;
	}
	int que(int p) {
		int res = 0;
		for(; p; p -= p & -p)
			res += arr[p];
		return res;
	}
} bit;
void build(int u, int lst) {
	if(arr[u]) {
		edge[lst].push_back(u);
		lst = u;
	}
	for(int v : tmp_edge[u])
		build(v, lst);
}
void dfs(int u) {
	in[u] = t++;
	for(int v : edge[u]) {
		dep[v] = dep[u] + 1;
		anc[0][v] = u;
		dfs(v);
	}
	out[u] = t++;
}
void binary_build(int n) {
	for(int i = 1; i < LGN; i++)
		for(int j = 1; j <= n; j++)
			anc[i][j] = anc[i - 1][anc[i - 1][j]];
}

int find_first(int u) {
	if(bit.que(in[u]) == 0)
		return 0;
	for(int i = LGN - 1; ~i; i--) {
		int p = anc[i][u];
		if(p && bit.que(in[p]) == bit.que(in[u]))
			u = p;
	}
	return u;
}
void add(int u) {
	bit.edt(in[u], 1);
	bit.edt(out[u], -1);
}
void rem(int u) {
	bit.edt(in[u], -1);
	bit.edt(out[u], 1);
}

ll res = 0;
ll cur[N];
void edt(int p, ll v) {
	res -= cur[p];
	cur[p] = v;
	res += cur[p];
}

signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 2, p; i <= n; i++)
		cin >> p, tmp_edge[p].push_back(i);

	vector<pair<int, int>> owo;
	for(int i = 0; i < m; i++) {
		int u, d, w;
		cin >> u >> d >> w;
		arr[u] = w;
		owo.push_back({d, u});
	}
	build(1, 1);

	dep[1] = 1;
	dfs(1);
	binary_build(n);
	sort(owo.begin(), owo.end(), [&](auto a, auto b) { return a.first == b.first ? dep[a.second] > dep[b.second] : a.first < b.first; });
	for(const auto &[d, u] : owo) {
		int p = u;
		ll cur_pen = arr[u];
		while(true) {
			p = find_first(p);
			if(!p)
				break;
			if(arr[p] - pen[p] - cur_pen <= 0) {
				rem(p);
				edt(p, 0);
				cur_pen += pen[p] - arr[p];
			}
			else {
				pen[p] += cur_pen;
				edt(p, arr[p] - pen[p]);
				break;
			}
		}
		edt(u, arr[u]);
		add(u);
	}
	cout << res << '\n';
}
