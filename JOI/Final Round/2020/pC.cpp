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
const ll LINF = ll(4e18) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 207;
ll dp[N][N][N][2];

signed main() {
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
				for(int w = 0; w < 2; w++)
					dp[i][j][k][w] = LINF;

	int n, l;
	cin >> n >> l;
	vector<int> arr(n), ti(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++)
		cin >> ti[i];

	dp[1][0][ti[0] >= arr[0]][0] = arr[0];
	dp[0][1][ti.back() >= l - arr.back()][1] = l - arr.back();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j + i < n; j++) {
			for(int k = 0; k <= n; k++) {
				if(dp[i][j][k][0] != LINF) {
					ll cur = dp[i][j][k][0] + (arr[i] - arr[i - 1]);
					dp[i + 1][j][k + (cur <= ti[i])][0] = min(dp[i + 1][j][k + (cur <= ti[i])][0], cur);

					cur = dp[i][j][k][0] + arr[i - 1] + (l - arr[n - j - 1]);
					dp[i][j + 1][k + (cur <= ti[n - j - 1])][1] = min(dp[i][j + 1][k + (cur <= ti[n - j - 1])][1], cur);
				}
				if(dp[i][j][k][1] != LINF) {
					ll cur = dp[i][j][k][1] + (l - arr[n - j]) + arr[i];
					dp[i + 1][j][k + (cur <= ti[i])][0] = min(dp[i + 1][j][k + (cur <= ti[i])][0], cur);

					cur = dp[i][j][k][1] + (arr[n - j] - arr[n - j - 1]);
					dp[i][j + 1][k + (cur <= ti[n - j - 1])][1] = min(dp[i][j + 1][k + (cur <= ti[n - j - 1])][1], cur);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for(int k = 0; k < N; k++)
				for(int w = 0; w < 2; w++)
					if(dp[i][j][k][w] < LINF)
						ans = max(ans, k);
	cout << ans << '\n';

}
