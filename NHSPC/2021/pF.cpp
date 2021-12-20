// 0/100
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

#define int ll
signed main() {
	int c, t;
	cin >> c >> t;
	vector<int> p(c), s(c), n(c);
	for(int i = 0; i < c; i++)
		cin >> p[i];
	for(int i = 0; i < c; i++)
		cin >> s[i];
	for(int i = 0; i < c; i++)
		cin >> n[i];
	vector<vector<int>> r(c, vector<int>(c));
	for(int i = 0; i < c; i++)
		for(int j = 0; j <= i; j++)
			cin >> r[j][i];

	ll nd = 0;
	vector<int> xdd;
	vector<ll> dp(t + 1);
	for(int i = 0; i < c; i++) {
		int sum = 0;
		vector<pair<int, int>> owo;
		for(int j = 0; j < c; j++) {
			sum += p[j];
			owo.push_back({sum + s[j], r[i][j]});
		}
		owo.push_back({sum, 0});
		sort(owo.begin(), owo.end());
		nd += owo[0].first * n[i];
		int x = owo[0].first;
		for(int j = t; j; j--) {
			for(const auto &[a, b] : owo) {
				if(j >= (a - owo[0].first) * n[i]) {
					dp[j] = max(dp[j], dp[j - (a - owo[0].first) * n[i]] + b);
				}
			}
		}
	}

	if(nd > t) {
		cout << "-1\n";
		return 0;
	}
	cout << dp[t - nd] << '\n';
}
