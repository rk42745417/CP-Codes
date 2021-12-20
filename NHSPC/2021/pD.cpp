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
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
};

const int N = 1e5 + 25;

int pa[N], id[N], cnt[N], r;
vector<pair<int, int>> edge[N], all_edge[N];

void dfs(int u) {
	for(const auto &[v, c] : edge[u]) {
		if(c <= r)
			break;
		if(!pa[v]) {
			pa[v] = pa[u];
			dfs(v);
		}
	}

	for(const auto &[v, c] : all_edge[u]) {
		if(c <= r)
			break;
		if(!pa[v]) {
			pa[v] = pa[u];
			dfs(v);
		}
	}
}
bool get_topo(int n, int k) {
	r = k;

	memset(cnt, 0, sizeof cnt);
	memset(pa, 0, sizeof pa);
	memset(id, 0, sizeof id);

	for(int i = 1; i <= n; i++) {
		for(const auto &[v, c] : edge[i]) {
			if(c <= k)
				break;
			cnt[v]++;
		}
	}

	queue<int> bfs;
	for(int i = 1; i <= n; i++)
		if(!cnt[i])
			bfs.push(i);

	int t = 1;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		id[u] = t++;
		for(const auto &[v, c] : edge[u]) {
			if(c <= k)
				break;
			cnt[v]--;
			if(!cnt[v])
				bfs.push(v);
		}
	}

	for(int i = 1; i <= n; i++)
		if(!id[i])
			return false;

	t = 1;
	for(int i = 1; i <= n; i++)
		if(!pa[i]) {
			pa[i] = t++;
			dfs(i);
		}
	return true;
}

signed main() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int, int>> tot_edge(m);
	vector<int> v;
	for(int i = 0; i < m; i++) {
		int u, rv, c;
		cin >> u >> rv >> c;
		v.push_back(c);
		tot_edge[i] = {c, i, u, rv};
		edge[u].push_back({rv, c});
		all_edge[rv].push_back({u, c});
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 1; i <= n; i++) {
		for(auto &[x, c] : edge[i]) {
			c = lower_bound(v.begin(), v.end(), c) - v.begin();
		}
		for(auto &[x, c] : all_edge[i]) {
			c = lower_bound(v.begin(), v.end(), c) - v.begin();
		}
		sort(edge[i].begin(), edge[i].end(), [&](auto a, auto b) {
				return a.second > b.second;
		});
		sort(all_edge[i].begin(), all_edge[i].end(), [&](auto a, auto b) {
				return a.second > b.second;
		});
	}

	int l = 0, r = v.size();
	while(l < r) {
		int m = l + r >> 1;
		if(get_topo(n, m))
			r = m;
		else
			l = m + 1;
	}

	assert(get_topo(n, l));

	vector<int> ans;
	ans.reserve(m);
	l = v[l];
	for(const auto &[c, i, u, v] : tot_edge) {
		if(c <= l) {
			if(pa[u] == pa[v]) {
				if(id[u] > id[v])
					ans.push_back(i + 1);
			}
			else {
				if(pa[u] > pa[v])
					ans.push_back(i + 1);
			}
		}
	}
	cout << l << ' ' << ans.size() << '\n';
	for(int a : ans)
		cout << a << '\n';
}
