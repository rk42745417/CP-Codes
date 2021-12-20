// 0/100
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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n);
	vector<vector<tuple<int, int, ll>> edge(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> cost(k * m);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		ll s = 0;
		for(int j = 0; j < k; j++) {
			cin >> cost[i * k + j];
			s += cost[i * k + j];
		}
		edge[u].push_back({v, i, s});
	}
	vector<vector<ll>> dp(1 << n, vector<vector<ll>>(n, -LINF));
	vector<vector<int>> pre(1 << n, vector<int>(n));
	for(int i = 0; i < n; i++)
		dp[0][i] = arr[i];
	for(int i = 0; i < (1 << n); i++) {
		for(int u = 0; u < n; u++) {
			if(i && (i >> u & 1) == 0)
				continue;
			if(dp[i][u] == -LINF)
				continue;
			for(const auto &[v, id, s] : edge[u]) {
				if(i >> v & 1)
					continue;
				if(dp[i][u] + s + arr[v] >= d && dp[i | (1 << v)][v] > dp[i][u] + s + arr[v]) {
					dp[i | (1 << v][v] = dp[i][u] + s + arr[v];
				}
			}
		}
	}

}
