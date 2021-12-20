// 19/100
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
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(n), t(n), w(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> t[i] >> w[i];
	}
	for(int i = 1; i < n; i++) {
		t[i] += t[i - 1];
		w[i] += w[i - 1];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x = upper_bound(t.begin(), t.end(), m + (i ? t[i - 1] : 0)) - t.begin();
		if(x > i)
			ans = max(ans, w[x - 1] - (i ? w[i - 1] : 0));
	}
	cout << ans << '\n';
}
