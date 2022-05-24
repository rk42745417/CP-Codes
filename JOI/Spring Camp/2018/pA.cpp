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
struct segtree {
	pair<int, int> arr[N << 1];
	int n, t = 1;
	void init(int _n) { n = _n; }
	void edt(int p, int v) {
		for(arr[p += n] = make_pair(t++, v); p > 1; p >>= 1)
			arr[p >> 1] = max(arr[p], arr[p ^ 1]);
	}
	int que(int l, int r) {
		pair<int, int> res;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = max(res, arr[l++]);
			if(r & 1)
				res = max(res, arr[--r]);
		}
		return res.second;
	}
} tree;
struct fenwicktree {
	int arr[N];
	void edt(int p, int v) {
		for(; p < N; p += p & -p)
			arr[p] += v;
	}
	int que(int p) {
		int res = 0;
		for(; p; p -= p & -p)
			res += arr[p];
		return res;
	}
} bit;
signed main() {
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	vector<vector<int>> edge(n + 1);
	vector<pair<int, int>> que(n - 1);
	for(auto &[a, b] : que) {
		cin >> a >> b;
		edge[a].push_back(b);
	}

	{
		vector<int> v = arr;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int &a : arr)
			a = lower_bound(v.begin(), v.end(), a) - v.begin();
	}

	vector<int> dep(n + 1), in(n + 1), out(n + 1);
	int t = 0;
	function<void(int)> dfs = [&](int u) {
		in[u] = t++;
		for(int v : edge[u]) {
			dep[v] = dep[u] + 1;
			dfs(v);
		}
		out[u] = t++;
	};
	dep[1] = 1;
	dfs(1);

	tree.init(n * 2);
	vector<int> up(n + 1);
	tree.edt(up[1], 1);
	for(const auto &[a, b] : que) {
		vector<pair<int, int>> owo;
		int x = a;
		while(x) {
			int r = tree.que(in[x], out[x]);
			owo.push_back({arr[r], dep[x] - dep[up[r]]});
			swap(up[r], x);
		}
		tree.edt(in[b], b);

		ll ans = 0;
		for(const auto &[v, c] : owo) {
			ans += 1LL * bit.que(v - 1) * c;
			bit.edt(v, c);
		}
		cout << ans << '\n';
		for(const auto &[v, c] : owo)
			bit.edt(v, -c);
	}
}
