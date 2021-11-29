// ?/100
#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 2e18;
const double EPS = 1e-9;

const int N = 305;
int dp[N][N], arr[N];
signed main() { EMT
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	for(int r = 1; r <= n; r++) {
		dp[r][r] = 1;
		for(int l = r - 1; l; l--) {
			dp[l][r] = INF;
			for(int k = l; k < r; k++) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);

			}
			if(arr[l] == arr[r])
				dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
		}
	}
	//cout << dp[2][8] << '\n';
	cout << dp[1][n] << '\n';
}
