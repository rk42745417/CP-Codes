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
const ll LINF = ll(4e15) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 403;
int dp[N][N][N][3], cnt[N][3];

signed main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	{
		string s;
		cin >> s;
		for(int i = 0; i < n; i++) {
			if(s[i] == 'R')
				arr[i] = 0;
			if(s[i] == 'G')
				arr[i] = 1;
			if(s[i] == 'Y')
				arr[i] = 2;
		}
	}
	array<vector<int>, 3> pos;
	for(int i = 0; i < n; i++) {
		pos[arr[i]].push_back(i);
		cnt[i][arr[i]]++;
		if(i) {
			for(int j = 0; j < 3; j++)
				cnt[i][j] += cnt[i - 1][j];
		}
	}
	int a = pos[0].size(), b = pos[1].size(), c = pos[2].size();
	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i < 3; i++)
		dp[0][0][0][i] = 0;

	for(int i = 0; i <= a; i++) {
		for(int j = 0; j <= b; j++) {
			for(int k = 0; k <= c; k++) {
				for(int r = 0; r < 3; r++)
					dp[i][j][k][r] = min(dp[i][j][k][r], INF);
				if(i < a) {
					int cost = max(0, cnt[pos[0][i]][1] - j) + max(0, cnt[pos[0][i]][2] - k);
					dp[i + 1][j][k][0] = min(dp[i][j][k][1] + cost, dp[i][j][k][2] + cost);
				}
				if(j < b) {
					int cost = max(0, cnt[pos[1][j]][0] - i) + max(0, cnt[pos[1][j]][2] - k);	
					dp[i][j + 1][k][1] = min(dp[i][j][k][0] + cost, dp[i][j][k][2] + cost);
				}
				if(k < c) {
					int cost = max(0, cnt[pos[2][k]][0] - i) + max(0, cnt[pos[2][k]][1] - j);
					dp[i][j][k + 1][2] = min(dp[i][j][k][0] + cost, dp[i][j][k][1] + cost);
				}
			}
		}
	}

	int r = min({dp[a][b][c][0], dp[a][b][c][1], dp[a][b][c][2]});
	if(r == INF)
		cout << "-1\n";
	else
		cout << r << '\n';
}
