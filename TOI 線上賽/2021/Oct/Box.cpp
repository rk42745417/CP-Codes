// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = [] {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> dp(n, vector<int>(n + 1));
	if(s[0] == '[' || s[0] == '?')
		dp[0][1]++;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= n; j++) {
			if(s[i] == '?' || s[i] == '[') {
				if(j)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			}
			if(s[i] == '?' || s[i] == ']') {
				if(j < n)
					dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}
	cout << dp[n - 1][0] << '\n';
}
