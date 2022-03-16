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

const int N = 1e4 + 25;
int dp[N][26][26];
signed main() {
	vector<vector<int>> dis(26, vector<int>(26, INF));
	for(int i = 0; i < 26; i++)
		dis[i][i] = 0;
	auto add = [&](char a, char b) {
		a -= 'A';
		b -= 'A';
		dis[a][b] = dis[b][a] = 1;
	};
	{
		string s[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < s[i].size(); j++) {
				if(i) {
					add(s[i][j], s[i - 1][j]);
					add(s[i][j], s[i - 1][j + 1]);
				}
				if(j)
					add(s[i][j - 1], s[i][j]);
			}
		}
	}
	for(int k = 0; k < 26; k++)
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	int n;
	string s;
	cin >> n >> s;
	memset(dp, 0x3f, sizeof dp);
	dp[0]['F' - 'A']['J' - 'A'] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 26; j++) {
			for(int k = 0; k < 26; k++) {
				if(dp[i][j][k] == INF)
					continue;
				dp[i + 1][s[i] - 'A'][k] = min(dp[i + 1][s[i] - 'A'][k], dp[i][j][k] + dis[j][s[i] - 'A']);
				dp[i + 1][j][s[i] - 'A'] = min(dp[i + 1][j][s[i] - 'A'], dp[i][j][k] + dis[k][s[i] - 'A']);
			}
		}
	}
	int ans = INF;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			ans = min(ans, dp[n][i][j]);
	cout << ans << '\n';
}
