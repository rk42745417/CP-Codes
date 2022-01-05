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

const int N = 1e6 + 25;
int cnt[N];

signed main() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	s++;

	vector<vector<pair<int, int>>> edge(n + m + 1);
	vector<int> dis(n + m + 1);
	vector<vector<int>> lca_dp(n + m + 1, vector<int>(n + m + 1, -1));

	for(int i = 1; i <= n + m; i++) {
		int p, c;
		cin >> p >> c;
		edge[p].push_back({i, c + 1});
	}

	function<void(int)> cal_dis = [&](int u) {
		for(const auto &[v, c] : edge[u]) {
			dis[v] = dis[u] + c;
			cal_dis(v);
		}
	};
	cal_dis(0);
	
	vector<int> all_dis(n + 1);
	for(int i = 0; i <= n; i++)
		all_dis[i] = dis[i];
	sort(all_dis.begin(), all_dis.end());
	all_dis.erase(unique(all_dis.begin(), all_dis.end()), all_dis.end());

	vector<bool> ans(n + m + 1);
	vector<int> path_dis;
	path_dis.reserve(n + m + 1);

	function<void(int, int)> add = [&](int u, int p) {
		if(u > n)
			return;
		cnt[dis[u] - dis[p]]++;
		for(const auto &[v, _] : edge[u])
			add(v, p);
	};
	function<void(int, int)> rem = [&](int u, int p) {
		if(u > n)
			return;
		cnt[dis[u] - dis[p]]--;
		for(const auto &[v, _] : edge[u])
			rem(v, p);
	};

	vector<int> di;
	di.reserve(2000);
	auto get_div = [&](int w) {
		di.clear();
		for(int i = 1; i * i <= w; i++) {
			if(w % i == 0) {
				di.push_back(i);
				if(w != i * i)
					di.push_back(w / i);
			}
		}
	};

	function<void(int)> dfs = [&](int u) {
		if(u <= n) {
			path_dis.push_back(dis[u]);
		}
		add(u, u);

		for(const auto &[v, _] : edge[u]) {
			dfs(v);
		}

		if(u > n) {
			if(dis[u] == k)
				ans[u] = true;

			int it = 0;
			for(int a : all_dis) {
				while(it < path_dis.size() && dis[u] - path_dis[it] + s + a > k)
					it++;
				if(it < path_dis.size() && dis[u] - path_dis[it] + s + a == k)
					ans[u] = true;
			}

			int w = k - dis[u];
			assert(w >= 0);
			get_div(w);
			for(int a : di) {
				if(a >= s && cnt[a - s])
					ans[u] = true;
			}
		}

		rem(u, u);
		if(u <= n) {
			path_dis.pop_back();
		}
	};
	dfs(0);

	for(int i = n + 1; i <= n + m; i++)
		cout << (ans[i] ? "YES" : "NO") << '\n';
}
