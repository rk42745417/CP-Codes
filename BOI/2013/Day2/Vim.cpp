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
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 70007, M = 11;
int dp[N][M][M], ans[N][M];
signed main() {
	int n;
	string s;
	cin >> n >> s;
	s += 'k';
	n++;
	int cnt = 0;
	vector<bool> has;
	{
		string t;
		bool nxt = false;
		for(int i = 0; i < n; i++) {
			if(s[i] == 'e') {
				nxt = true;
				cnt++;
			}
			else {
				t.push_back(s[i] - 'a');
				has.push_back(nxt);
				nxt = false;
			}
		}
		s = t;
		n = s.size();
	}
	memset(dp, 0x3f, sizeof dp);
	memset(ans, 0x3f, sizeof ans);
	ans[0][s[0]] = 0;
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < M; j++) {
			{
				int &w = ans[i][j];
				w = min(w, ans[i - 1][s[i - 1]] + 2);
				w = min(w, dp[i - 1][s[i - 1]][s[i - 1]] + 2);
				if(j != s[i - 1]) {
					if(!has[i - 1])
						w = min(w, ans[i - 1][j]);
					w = min(w, dp[i - 1][s[i - 1]][j]);
				}
			}
			for(int k = 0; k < M; k++) {
				int &w = dp[i][j][k];
				w = min(w, ans[i - 1][s[i - 1]] + 5);
				w = min(w, dp[i - 1][s[i - 1]][s[i - 1]] + 5);
				if(j != s[i - 1]) {
					w = min(w, ans[i - 1][j] + 3);
					w = min(w, dp[i - 1][j][s[i - 1]] + 3);
				}
				if(k != s[i - 1])
					w = min(w, dp[i - 1][s[i - 1]][k] + 3);
				if(j != s[i - 1] && k != s[i - 1])
					w = min(w, dp[i - 1][j][k] + 1);
			}
		}
	}
	cout << cnt * 2 + ans[n - 1][M - 1] - 2 << '\n';
}
