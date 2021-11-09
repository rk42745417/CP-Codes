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
}();

signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> edge(n + 1);
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		vector<int> arr(n + 1);
		for(int i = 1; i <= n; i++) {
			cin >> arr[i];
			if(arr[i] == -1)
				return 0;
		}
		int ans = 0;
		vector<int> dis(n + 1, INF);
		function<void(int, int, int)> dfs = [&](int u, int p, int c) {
			for(int v : edge[u]) {
				if(v == p)
					continue;
				dfs(v, u, c);
				dis[u] = min(dis[u], dis[v] + 1);
				if(arr[v] == c)
					dis[u] = 1;
			}
		};
		function<void(int, int, int, int)> dfs2 = [&](int u, int p, int c, int d) {
			//cout << c << ' ' << d << ' ' << dis[u] << '\n';
			if(arr[u] == c)
				ans = max(ans, min(dis[u], d));
			if(arr[u] == c)
				d = 0;
			multiset<int> has;
			has.insert(d);
			for(int v : edge[u]) {
				if(v == p)
					continue;
				if(arr[v] == c)
					has.insert(1);
				else
					has.insert(dis[v] + 1);
			}
			for(int v : edge[u]) {
				if(v == p)
					continue;
				if(arr[v] == c)
					has.erase(has.lower_bound(1));
				else
					has.erase(has.lower_bound(dis[v] + 1));
				dfs2(v, u, c, *has.begin() + 1);
				if(arr[v] == c)
					has.insert(1);
				else
					has.insert(dis[v] + 1);
			}
		};
		dfs(1, 1, 1);
		dfs2(1, 1, 1, INF);
		fill(dis.begin(), dis.end(), INF);
		dfs(1, 1, 0);
		dfs2(1, 1, 0, INF);
		if(ans >= n)
			cout << "-1\n";
		else {
			cout << ans << '\n';
			for(int i = 1; i <= n; i++)
				cout << arr[i] << " \n"[i == n];
		}
	}
}
