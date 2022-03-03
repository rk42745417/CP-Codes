// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const ll LINF = ll(4e18) + ll(2e15);
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	vector<vector<bool>> ver(n, vector<bool>(m)), hor = ver;
	for(int i = 0; i + 2 < n; i++)
		for(int j = 0; j < m; j++)
			if(arr[i][j] == 'R' && arr[i + 1][j] == 'G' && arr[i + 2][j] == 'W')
				ver[i][j] = ver[i + 1][j] = ver[i + 2][j] = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j + 2 < m; j++)
			if(arr[i][j] == 'R' && arr[i][j + 1] == 'G' && arr[i][j + 2] == 'W')
				hor[i][j] = hor[i][j + 1] = hor[i][j + 2] = true;

	vector<array<int, 3>> dp(n);
	int ans = 0;
	for(int s = 1; s < n + m - 1; s++) {
		fill(dp.begin(), dp.end(), array<int, 3>());
		for(int i = max(0, s - m + 1); i <= min(n - 1, s); i++) {
			int j = s - i;
			if(i)
				dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
			if(arr[i][j] == 'G' && ver[i][j])
				dp[i][1] = (i ? max(dp[i - 1][0], dp[i - 1][1]) : 0) + 1;
			if(arr[i][j] == 'G' && hor[i][j])
				dp[i][2] = (i ? max(dp[i - 1][0], dp[i - 1][2]) : 0) + 1;
		}
		int x = min(n - 1, s);
		ans += max({dp[x][0], dp[x][1], dp[x][2]});
	}
	cout << ans << '\n';
}
