// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EMiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EMiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	vector<vector<int>> edge(n + 1);
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	vector<int> tim(n + 1);
	int t = 1;
	function<void(int, int)> dfs = [&](int u, int p) {
		tim[u] = t++;
		for(int v : edge[u])
			if(v != p)
				dfs(v, u);
	};
	for(int i = 1; i <= n; i++)
		if(!tim[i])
			dfs(i, i);
	vector<pair<int, int>> owo, ans;
	for(int i = 1; i <= n; i++)
		if(edge[i].size() == 1)
			owo.push_back({tim[i], i});
	sort(owo.begin(), owo.end());
	for(int i = 0; i < owo.size() / 2; i++)
		ans.push_back({owo[i].second, owo[i + owo.size() / 2].second});
	if(owo.size() & 1)
		ans.push_back({owo[owo.size() / 2].second, owo.back().second});

	cout << ans.size() << '\n';
	for(const auto &[a, b] : ans)
		cout << a << ' ' << b << '\n';
}
