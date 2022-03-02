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

signed main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<vector<int>> cnt(n + 1, vector<int>(3));
	const string joi = "JOI";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cnt[i + 1][j] = cnt[i][j] + (s[i] == joi[j]);
		}
	}

	int ans = INF;
	for(int i = 1; i <= n; i++) {
		int cur = i;
		bool ok = 1;
		for(int j = 0; j < 3; j++) {
			if(cnt[n][j] - cnt[cur - 1][j] < k) {
				ok = 0;
				break;
			}
			int l = i, r = n;
			while(l < r) {
				int m = l + r >> 1;
				if(cnt[m][j] - cnt[cur - 1][j] < k)
					l = m + 1;
				else
					r = m;
			}
			cur = l;
		}
		if(ok)
			ans = min(ans, cur - i + 1 - k * 3);
	}
	if(ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';
}
