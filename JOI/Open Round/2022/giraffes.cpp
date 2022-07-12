// 59/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 4e18;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 305;
int dp[N][N][N];

signed main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a, a--;

	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			dp[i][i][j] = arr[i] != j;

	for(int r = 0; r < n; r++) {
		for(int l = r - 1; ~l; l--) {
			for(int a = 0; a + (r - l) < n; a++) {
				int b = a + (r - l);
				dp[l][r][a] = min({
					dp[l + 1][r][a] - (arr[l] == b),
					dp[l + 1][r][a + 1] - (arr[l] == a),
					dp[l][r - 1][a] - (arr[r] == b),
					dp[l][r - 1][a + 1] - (arr[r] == a)
				}) + 1;
			}
		}
	}
	cout << dp[0][n - 1][0] << '\n';
}
