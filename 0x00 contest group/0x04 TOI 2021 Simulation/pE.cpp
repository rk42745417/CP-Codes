#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;

signed main() { EMT
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n / k);
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		arr[i / k] += x;
	}
	int w = n / k;
	for(int i = 1; i < w; i++)
		arr[i] += arr[i - 1];
	auto sum = [&](int l, int r) { return arr[r] - (l > 0 ? arr[l - 1] : 0); };
	vector<vector<ll>> dp(w, vector<ll>(w));
	for(int r = 0; r < w; r++) {
		dp[r][r] = sum(r, r);
		for(int l = r - 1; ~l; l--) {
			//cout << l << ' ' << r << ' ' << sum(l, r) << '\n';
			dp[l][r] = max(sum(l, r) - dp[l + 1][r], sum(l, r) - dp[l][r - 1]);
		}
	}
	cout << dp[0][w - 1] << ' ' << sum(0, w - 1) - dp[0][w - 1] << '\n';
}
