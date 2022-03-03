// 22/100
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
	int n, q;
	cin >> n >> q;
	vector<int> mpow(n + 1, 1);
	for(int i = 1; i <= n; i++)
		mpow[i] = mpow[i - 1] * 3;
	vector<int> dp(mpow[n]), prv(mpow[n]);
	{
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++) {
			int r = 0;
			for(int j = 0; j < n; j++)
				if(i >> j & 1)
					r += mpow[j];
			dp[r] = s[i] - '0';
		}
	}
	for(int i = 0; i < n; i++) {
		swap(prv, dp);
		for(int j = 0; j < mpow[n]; j++) {
			int x = j / mpow[i] % 3;
			if(x < 2)
				dp[j] = prv[j];
			else
				dp[j] = prv[j - mpow[i] * 2] + prv[j - mpow[i]];
		}
	}

	while(q--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int r = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == '?')
				r += mpow[i] * 2;
			else
				r += mpow[i] * (s[i] & 1);
		}
		cout << dp[r] << '\n';
	}
}
