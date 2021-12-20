// 64/100
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

signed main() {
	ll n;
	cin >> n;
	assert(n <= 100000);
	vector<ll> dp(n + 1);
	dp[0] = 1;
	ll s1 = 0, s2 = 0;
	for(int i = 2; i <= n; i++) {
		s2 = (s2 + dp[i - 2]) % MOD;
		s1 = (s1 + s2 + dp[i - 2]) % MOD;
		dp[i] = (s1 * 2 - s2 * 3 % MOD + MOD) % MOD;
	}
	dp[i] = (dp[i - j] * (j - 2) * 2 + dp[i - j]); // j >= 2
	cout << dp.back() << '\n';
}
