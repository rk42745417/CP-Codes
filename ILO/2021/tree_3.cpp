// 17/100 (subtask 3)
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	vector<pair<ll, int>> eve;
	{
		vector<ll> tmp(n + 1);
		for(int i = 1; i <= n; i++)
			cin >> tmp[i];
		
		vector<vector<int>> edge(n + 1);
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		vector<int> order;
		order.reserve(n);
		function<void(int, int)> dfs = [&](int u, int p) {
			order.push_back(u);
			for(int v : edge[u])
				if(v != p)
					dfs(v, u);
		};
		for(int i = 1; i <= n; i++) {
			if(edge[i].size() == 1) {
				dfs(i, i);
				break;
			}
		}

		eve.reserve(n);
		for(int i = 1; i <= n; i++)
			eve.push_back({tmp[order[i - 1]], i});
	}
	sort(eve.begin(), eve.end());

	int it = 0;
	ll cur = -1, ans = 0;
	set<int> a, b;
	ll suma = 0, sumb = 0;
	while(it < n) {
		cur = eve[it].first;
		while(it < n && eve[it].first == cur) {
			if(a.empty() || eve[it].second <= *a.rbegin())
				a.insert(eve[it].second), suma += eve[it].second;
			else
				b.insert(eve[it].second), sumb += eve[it].second;
			it++;

			while(a.size() < (it + 1) / 2) {
				int x = *b.begin();
				a.insert(x);
				b.erase(x);
				suma += x;
				sumb -= x;
			}
			while(a.size() > (it + 1) / 2) {
				int x = *prev(a.end());
				b.insert(x);
				a.erase(x);
				sumb += x;
				suma -= x;
			}
		}
		
		ll x = *a.rbegin();
		ll dis = a.size() * x - suma;
		dis += sumb - b.size() * x;
		ans = max(ans, ll(n) * it - dis - cur);
	}
	cout << ans << '\n';
}
