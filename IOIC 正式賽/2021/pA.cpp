#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

const int N = 515;
struct DisjointSet {
	int pa[N], sz[N];
	void init() {
		for(int i = 0; i < N; i++)
			pa[i] = i, sz[i] = 1;
	}
	int fnd(int x) { return pa[x] == x ? pa[x] : pa[x] = fnd(pa[x]); }
	void uni(int a, int b) {
		if((a = fnd(a)) == (b = fnd(b)))
			return;
		if(sz[a] > sz[b])
			swap(a, b);
		return sz[b] += sz[a], pa[a] = b, void();
	}
} dsu;

signed main() { EmiliaMyWife
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges(m);
	for(int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		edges[i] = {c, a, b};
	}
	sort(edges.begin(), edges.end());
	int q;
	cin >> q;
	while(q--) {
		int u, v, w, ans = 0;
		cin >> u >> v >> w;
		dsu.init();
		for(const auto &[c, a, b] : edges) {
			if(c >= w)
				break;
			if((dsu.fnd(a) == dsu.fnd(u) && dsu.fnd(b) == dsu.fnd(v)) || (dsu.fnd(b) == dsu.fnd(u) && dsu.fnd(a) == dsu.fnd(v)))
				ans++;
			else
				dsu.uni(a, b);
		}
		reverse(edges.begin(), edges.end());
		dsu.init();
		for(const auto &[c, a, b] : edges) {
			if(c <= w)
				break;
			if((dsu.fnd(a) == dsu.fnd(u) && dsu.fnd(b) == dsu.fnd(v)) || (dsu.fnd(b) == dsu.fnd(u) && dsu.fnd(a) == dsu.fnd(v)))
				ans++;
			else
				dsu.uni(a, b);
		}
		reverse(edges.begin(), edges.end());
		cout << ans << '\n';
	}
}
