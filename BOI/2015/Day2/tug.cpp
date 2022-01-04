// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-6;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 60000;
struct disjoint_set {
	int pa[N], sz[N], has[N];
	void init() {
		for(int i = 0; i < N; i++)
			pa[i] = i, sz[i] = 1;
	}
	int fnd(int x) { return pa[x] == x ? pa[x] : pa[x] = fnd(pa[x]); }
	bool uni(int a, int b) {
		if((a = fnd(a)) == (b = fnd(b))) {
			if(has[a])
				return false;
			has[a] = true;
			return true;
		}
		if(sz[a] > sz[b])
			swap(a, b);
		pa[a] = b;
		sz[b] += sz[a];
		has[b] |= has[a];
		return true;
	}
} dsu;

const int T = 7 * 30000;
bitset<T * 2 + 1> dp;
signed main() {
	int n, k;
	cin >> n >> k;

	vector<vector<pair<int, int>>> edge(n * 2);
	vector<int> deg(n * 2);
	dsu.init();

	for(int i = 0; i < n * 2; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		l = l - 1;
		r = r - 1 + n;
		edge[l].push_back({r, c});
		edge[r].push_back({l, c});
		deg[l]++;
		deg[r]++;
		if(!dsu.uni(l, r))
			return cout << "NO\n", 0;
	}

	vector<bool> vis(n * 2);
	queue<int> bfs;
	int cur = 0;
	for(int i = 0; i < n * 2; i++)
		if(deg[i] == 1)
			bfs.push(i), vis[i] = true;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		for(const auto &[v, c] : edge[u]) {
			if(vis[v])
				continue;
			if(u >= n)
				cur -= c;
			else
				cur += c;

			deg[v]--;
			if(deg[v] == 1)
				bfs.push(v), vis[v] = true;
		}
	}

	vector<int> ord;
	function<void(int)> dfs = [&](int u) {
		vis[u] = true;
		ord.push_back(u);
		for(const auto &[v, c] : edge[u]) {
			if(!vis[v])
				dfs(v);
		}
	};
	vector<int> has;
	for(int i = 0; i < n * 2; i++) {
		if(vis[i])
			continue;
		ord.clear();
		dfs(i);
		int cur = 0;
		if(ord.size() > 2) {
			for(int i = 0; i < ord.size(); i++) {
				int u = ord[i], v = ord[(i + 1) % ord.size()];
				for(const auto &[x, c] : edge[u]) {
					if(x == v) {
						if(u < n)
							cur += c;
						else
							cur -= c;
					}
				}
			}
		}
		else {
			bool ok = 0;
			for(const auto &[x, c] : edge[ord[0]]) {
				if(x == ord[1]) {
					if(ok)
						cur += c;
					else
						cur -= c;
					ok = !ok;
				}
			}
		}
		has.push_back(abs(cur));
	}
	
	dp[T + abs(cur)] = true;
	sort(has.begin(), has.end(), greater<int>());
	for(int a : has) {
		dp = (dp << a) | (dp >> a);
	}

	for(int i = 0; i <= k; i++)
		if(i + T < 2 * T + 1 && dp[i + T])
			return cout << "YES\n", 0;
	cout << "NO\n";
}
