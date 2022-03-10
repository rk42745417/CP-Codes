// 15/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const ll LINF = ll(4e18) + ll(2e15);
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 1007;
struct segtree {
	int arr[N << 1], n;
	void init(int _n) { n = _n; }
	void edt(int p, int v) {
		p += n;
		for(arr[p] = max(arr[p], v); p > 1; p >>= 1)
			arr[p >> 1] = max(arr[p], arr[p ^ 1]);;
	}
	int que(int l, int r) {
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = max(res, arr[l++]);
			if(r & 1)
				res = max(res, arr[--r]);
		}
		return res;
	}
} tree[N];

signed main() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> edge(n + 1);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[v].push_back(u);
		edge[u].push_back(v);
	}
	vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
	for(int i = 1; i <= n; i++) {
		dis[i][i] = 0;
		queue<int> bfs;
		bfs.push(i);
		while(!bfs.empty()) {
			int u = bfs.front();
			bfs.pop();
			for(int v : edge[u])
				if(dis[i][v] > dis[i][u] + 1)
					dis[i][v] = dis[i][u] + 1, bfs.push(v);
		}
		tree[i].init(q);
	}

	int id = 0;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int u, t;
			cin >> u >> t;
			for(int i = 1; i <= n; i++)
				tree[i].edt(id, t + dis[i][u]);
			id++;
		}
		else {
			int l, r, t;
			cin >> l >> r >> t;
			int res = 0;
			for(int i = 1; i <= n; i++)
				res += tree[i].que(l - 1, r) <= t;
			cout << res << '\n';
		}
	}
}
