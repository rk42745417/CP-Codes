// 60/100
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

const int N = 5000;
int dp[N][N];
signed main() {
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> nxt(n, vector<int>(10, INF));
	for(int i = n - 2; ~i; i--) {
		for(int j = 0; j < 10; j++)
			nxt[i][j] = nxt[i + 1][j];
		if(s[i + 1] != 'e')
			nxt[i][s[i + 1] - 'a'] = i + 1;
	}
	for(int i = 0; i < n; i++) {
		int mn = -1, cnt = 0;
		for(int j = 0; j < n; j++) {
			if(j > i && s[j] == 'e') {
				if(mn == -1)
					mn = j;
				cnt++;
			}
			if(dp[i][j] == INF)
				continue;
			if(i + 1 < n && s[i + 1] != 'e')
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if(i < j && mn != -1)
				dp[j][mn] = min(dp[j][mn], dp[i][j] + (j - mn) + cnt);
			int r = INF;
			for(int k = 0; k < 10; k++) {
				r = min(r, nxt[j][k]);
				if(nxt[j][k] != INF)
					dp[i][nxt[j][k]] = min(dp[i][nxt[j][k]], dp[i][j] + 2);
			}
			if(r != INF && j <= i && s[j] == 'e')
				dp[i][r] = min(dp[i][r], dp[i][j]);
		}
	}
	int mn = INF;
	for(int i = 0; i < n; i++)
		mn = min(mn, dp[n - 1][i]);
	cout << mn << '\n';
}
