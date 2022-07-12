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
const ll LINF = 4e18;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> edge(n, vector(n, LINF)), edge2(n, vector(n, -LINF));
	for(int i = 0; i < m; i++) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		u--; v--;
		edge[u][v] = min(edge[u][v], c);
		edge[v][u] = min(edge[v][u], c);
		edge2[u][v] = max(edge2[u][v], c);
		edge2[v][u] = max(edge2[v][u], c);
	}

	vector<vector<ll>> mx(n, vector<ll>(1 << n, -LINF)), mn(n, vector<ll>(1 << n, LINF));
	mx[0][1] = mn[0][1] = 0;

	ll a = -LINF, b = LINF;
	for(int i = 0; i < (1 << n); i++) {
		for(int u = 0; u < n; u++) {
			if(~i >> u & 1)
				continue;
			for(int v = 0; v < n; v++) {
				if((i >> v & 1) || edge[u][v] == LINF)
					continue;
				ll c = edge[u][v];
				int x = i | (1 << v);
				mx[v][x] = max(mx[v][x], mx[u][i] + c);
				mn[v][x] = min(mn[v][x], mn[u][i] + c);
			}
			for(int v = 0; v < n; v++) {
				if((i >> v & 1) || edge2[u][v] == -LINF)
					continue;
				ll c = edge2[u][v];
				int x = i | (1 << v);
				mx[v][x] = max(mx[v][x], mx[u][i] + c);
				mn[v][x] = min(mn[v][x], mn[u][i] + c);
			}
		}
		a = max(a, mx[n - 1][i]);
		b = min(b, mn[n - 1][i]);
	}
	cout << (a != b) << '\n';
}
