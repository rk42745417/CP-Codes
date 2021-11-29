// ?/100
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("avx2")
//#pragma GCC optimize("unroll-loops")

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const double EPS = 1e-9;

struct dat {
	int u, lst;
	bool has;
	friend bool operator<(const dat &a, const dat &b) { return a.u < b.u; }
};
const int N = 1001;
ll dis[N][N * 2][2], tot[N * 2], col[N * 2], pri[N * 2];
int cnt[N * 2];
vector<pair<int, int>> edge[N];

signed main() { EMT
	int n, m;
	cin >> n >> m;
	for(int i = 0, a, b, c, d; i < m; i++) {
		cin >> a >> b >> c >> d;
		edge[a].push_back({b, i});
		edge[b].push_back({a, i});
		pri[i] = d;
		col[i] = c;
	}
	memset(dis, 0x3f, sizeof dis);
	dis[1][0][0] = 0;
	priority_queue<pair<ll, dat>, vector<pair<ll, dat>>, greater<pair<ll, dat>>> pq;
	pq.push({0, {1, 0, 0}});
	ll ans = LINF;

	while(!pq.empty()) {
		const auto [c, u] = pq.top();
		//cerr << "here " << c << ' ' << u.u << ' ' << u.lst << ' ' << u.has << '\n';
		pq.pop();
		if(c > dis[u.u][u.lst][u.has])
			continue;

		if(u.u == n)
			ans = min(ans, c);
		
		for(const auto &[v, id] : edge[u.u])
			cnt[col[id]]++, tot[col[id]] += pri[id];
		if(u.has)
			cnt[col[u.lst]]--, tot[col[u.lst]] -= pri[u.lst];

		for(const auto &[v, id] : edge[u.u]) {
			ll w = 0, has = 0;
			if(cnt[col[id]] > 1)
				w = pri[id], has = 1;

			if(dis[v][id][has] > c + w) {
				dis[v][id][has] = c + w;
				pq.push({dis[v][id][has], {v, id, has}});
			}

			has = 0;
			w = max<ll>(0, tot[col[id]] - pri[id]);
			if(dis[v][id][0] > c + w) {
				dis[v][id][0] = c + w;
				pq.push({dis[v][id][0], {v, id, 0}});
			}
		}
		for(const auto &[v, id] : edge[u.u])
			cnt[col[id]] = 0, tot[col[id]] = 0;
	}
	if(ans > 1e16)
		cout << "-1\n";
	else
		cout << ans << '\n';
}
