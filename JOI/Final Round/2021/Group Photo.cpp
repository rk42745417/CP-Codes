// 100/100
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"
#define print(x) emilia_mata_tenshi(#x, begin(x), end(x))
template<typename T> void emilia_mata_tenshi(const char *s, T l, T r) {
	cerr << "\e[1;33m" << s << " = [";
	while(l != r) {
		cerr << *l;
		cerr << (++l == r ? ']' : ',');
	}
	cerr << "\e[0m\n";
}

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-7;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static auto Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

signed main() {
	int n;
	cin >> n;
	vector<vector<int>> sum(n + 1, vector<int>(n + 1)), cost = sum;
	vector<int> arr(n + 1), pos(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i][arr[i]]++;
		pos[arr[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	auto que = [&](int x1, int y1, int x2, int y2) {
		if(x1 > x2 || y1 > y2)
			return 0;
		return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	};
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			cost[i][j] = cost[i][j - 1];
			cost[i][j] += que(1, i, pos[j] - 1, n);
			cost[i][j] -= que(pos[j] + 1, i, n, j);
		}
	}
	vector<int> dp(n + 1, INF);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++)
			dp[i] = min(dp[i], dp[j - 1] + cost[j][i]);
	}
	cout << dp[n] << '\n';
}
