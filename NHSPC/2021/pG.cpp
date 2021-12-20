// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios_base::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 2e5 + 25;
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
	int n, root, q;
	cin >> n >> root >> q;
	{
		int a;
		cin >> a;
		q += a;
	}

	vector<pair<int, int>> edges(n - 1);
	vector<vector<int>> edge(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		edges[i] = {u, v};
	}
	vector<int> dep(n + 1), in(n + 1), out(n + 1);
	int t = 1;
	function<void(int, int)> dfs = [&](int u, int p) {
		in[u] = t++;
		for(int v : edge[u]) {
			if(v == p)
				continue;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
		out[u] = t++;
	};
	dep[root] = 1;
	dfs(root, root);

	for(const auto &[u, v] : edges) {
		int x = u;
		if(dep[v] > dep[u])
			x = v;
		bit.edt(in[x], 1), bit.edt(out[x], -1);
	}
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int x, y;
			cin >> x >> y;
			cout << 1LL * x * bit.que(in[y]) << '\n';
		}
		else {
			int x;
			cin >> x;
			auto [u, v] = edges[x - 1];
			if(dep[u] < dep[v])
				swap(u, v);
			bit.edt(in[u], -1);
			bit.edt(out[u], 1);
		}
	}
}
/*
5 1 3 2
1 2
2 3
2 4
5 2
1 5 5
2 2
1 2 3
2 4
1 5 5

*/
