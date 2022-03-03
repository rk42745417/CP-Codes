// 100/100
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
	int n;
	cin >> n;
	vector<pair<ll, int>> arr(n);
	for(auto &[a, b] : arr)
		cin >> a >> b;
	sort(arr.begin(), arr.end());
	vector<ll> sum(n);
	for(int i = 0; i < n; i++) {
		sum[i] = arr[i].second;
		if(i)
			sum[i] += sum[i - 1];
	}
	ll ans = -LINF, res = LINF;
	for(int i = 0; i < n; i++) {
		ll c = (i ? sum[i - 1] : ll(0)) - arr[i].first;
		res = min(res, c);
		ans = max(ans, sum[i] - arr[i].first - res);
	}
	cout << ans << '\n';
}
