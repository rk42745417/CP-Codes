// 0/110
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(4e18) + ll(2e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	vector<vector<int>> edge(2 * n);
	
	vector<pair<int, int>> cord(n);
	vector<int> type(n), v;
	for(int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		cord[i] = {x, y};
		v.push_back(x);
		v.push_back(y);
		char c;
		cin >> c;
		type[i] = c == '\\';
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<vector<pair<int, int>> has(v.size());

	for(auto &[a, b] : cord) {
		a = lower_bound(v.begin(), v.end(), a) - v.begin();
		b = lower_bound(v.begin(), v.end(), b) - v.begin();
	}
	
	for(int i = 0; i < n; i++)
		has[cord[i].first].push_back({cord[i].second, i});
	for(auto &a : has) {
		sort(a.begin(), a.end());
		for(int i = 0; i < a.size(); i++) {
			if(i)
				edge[a[i].second].push_back(a[i - 1].second + n);
			if(i + 1 < a.size())
				edge[a[i].second + n].push_back(a[i - 1].second);
		}
		has.clear();
	}

	for(int i = 0; i < n; i++)
		has[cord[i].second].push_back({cord[i].first, i});
	for(auto &a : has) {
		sort(a.begin(), a.end());
		for(int i = 0; i < a.size(); i++) {
			if(i)
				edge[a[i].second + n * (type[a[i].second] == 1)].push_back(a[i - 1].second + n * (type[a[i - 1].second] == 0));
			if(i)
				edge[a[i].second + n * (type[a[i].second] == 0)].push_back(a[i + 1].second + n * (type[a[i + 1].second] == 1));
		}
	}

	int t = 1;
	vector<int> is(n * 2);
	vector<array<int, 4>> nd(n);
	vector<bool> vis(n * 2);
	for(int i = 0; i < n * 2; i++) {
		if(vis[i])
			continue;
		bool ok = 0;
		vector<int> pat;
		function<void(int, int, int)> dfs = [&](int u, int p, int x) {
			pat.push_back(u);
			for(int v : edge[u]) {
				if(v == p)
					continue;
				if(v == x)
					ok = true;
				if(!vis[v])
					dfs(v, u, x);
			}
		};
		dfs(i, i, i);
		for(int a : pat)
			ok &= edge[a].size() == 2;
		if(pat.size() % 8)
			return cout << "-1\n", 0;
		if(!ok)
			continue;
		for(int a : pat)
			is[a] = t;
		for(int j = 0; j < 4; j++)
			nd[t][j] = pat.size() / 4;
		t++;
	}

	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		if(is[i] && is[i + n]) {
			for(int j = 0; j < 4; j++) {
				if(nd[is[i]][j]) {
					ans[i] = j;
					nd[is[i]][j] -= 2;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(is[i] && is[i + n])
			continue;
		if(is[i] || is[i + n]) {

		}
	}
}
