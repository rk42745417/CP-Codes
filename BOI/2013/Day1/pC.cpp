// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<ll> c(n + 1);
	vector<int> cnt(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	vector<vector<pair<int, int>>> edge(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
		cnt[u]++;
		cnt[v]++;
	}
	vector<int> has;
	has.reserve(n);
	vector<bool> vis(n + 1), vis_edge(m);
	vector<ll> ans(m, LINF);
	bool ok = 1;
	function<int(int)> dfs = [&](int u) {
		has.push_back(u);
		vis[u] = true;
		int res = 0;
		for(const auto &[v, id] : edge[u]) {
			if(!vis_edge[id])
				vis_edge[id] = true, res++;
			if(!vis[v])
				res += dfs(v);
		}
		return res;
	};
	function<void(int, int)> solve_tree = [&](int u, int p) {
		for(const auto &[v, id] : edge[u]) {
			if(v == p)
				continue;
			solve_tree(v, u);
			ans[id] = c[v];
			c[v] -= ans[id];
			c[u] -= ans[id];
			ans[id] *= 2;
		}
		if(u == p && c[u] != 0)
			ok = 0;
	};
	function<void(int, int, vector<int>&)> find_cir = [&](int u, int p, vector<int> &tra) {
		tra.push_back(u);
		for(const auto &[v, id] : edge[u]) {
			if(v == tra.back() || v == tra.front() || v == p || ans[id] != LINF)
				continue;
			find_cir(v, u, tra);
		}
	};
	for(int i = 1; i <= n && ok; i++) {
		has.clear();
		if(vis[i])
			continue;
		int edge_cnt = dfs(i);
		if(edge_cnt == 0)
			continue;
		if(has.size() < edge_cnt) {
			ok = 0;
			break;
		}
		if(has.size() == edge_cnt + 1) {
			solve_tree(i, i);
			continue;
		}

		queue<int> bfs;
		for(int x : has)
			if(cnt[x] == 1)
				bfs.push(x);
		while(!bfs.empty()) {
			int u = bfs.front();
			bfs.pop(); 
			for(const auto &[v, id] : edge[u]) {
				if(ans[id] != LINF)
					continue;
				cnt[v]--;
				cnt[u]--;
				ans[id] = c[u] * 2;
				c[v] -= c[u];
				c[u] = 0;
				if(cnt[v] == 1)
					bfs.push(v);
			}
		}
		vector<int> cir;
		for(int x : has) {
			if(cnt[x] == 2) {
				find_cir(x, x, cir);
				break;
			}
		}
		if(cir.size() % 2 == 0) {
			ok = 0;
			break;
		}
		ll g = 0;
		for(int i = 0; i < cir.size(); i++) {
			if(i & 1)
				g -= c[cir[i]];
			else
				g += c[cir[i]];
		}
		if(g % 2) {
			ok = 0;
			break;
		}
		for(const auto &[v, id] : edge[cir[0]]) {
			if(v == cir.back()) {
				ans[id] = g;
				c[cir[0]] -= g / 2;
				c[v] -= g / 2;
			}
		}
		for(int i = 0; i + 1 < cir.size(); i++) {
			for(const auto &[v, id] : edge[cir[i]]) {
				if(v == cir[i + 1]) {
					ans[id] = c[cir[i]] * 2;
					c[cir[i + 1]] -= c[cir[i]];
					c[cir[i]] = 0;
				}
			}
		}
		for(int x : cir)
			ok &= c[x] == 0;
	}
	if(ok) {
		for(int a : ans)
			cout << a << '\n';
	}
	else
		cout << "0\n";
}
