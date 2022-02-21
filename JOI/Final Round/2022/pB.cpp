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
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n), brr(n);
	for(int &a : arr)
		cin >> a;
	for(int &a : brr)
		cin >> a;
	ll l = 0, r = LINF;
	auto check = [&](const ll k) {
		ll cur = 1LL * m * n;
		for(int i = 0; i < n; i++) {
			if(arr[i] <= brr[i]) {
				cur -= (k + brr[i] - 1) / brr[i];
			}
			else {
				ll r = k;
				ll w = min<ll>(m, (r + arr[i] - 1) / arr[i]);
				cur -= w;
				r -= w * arr[i];
				if(r > 0)
					cur -= (r + brr[i] - 1) / brr[i];
			}
			if(cur < 0)
				return false;
		}
		return true;
	};
	while(l < r) {
		ll m = l + r >> 1;
		if(check(m))
			l = m + 1;
		else
			r = m;
	}
	cout << ll(l - 1) << '\n';
}
