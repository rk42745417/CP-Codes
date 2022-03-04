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
	int n, q, s, t;
	cin >> n >> q >> s >> t;
	vector<ll> arr(n + 1);
	for(int i = 0; i <= n; i++)
		cin >> arr[i];
	ll res = 0;
	for(int i = n; i; i--)
		arr[i] -= arr[i - 1];

	auto cost = [&](ll x) {
		return 1LL * s * min<ll>(0, -x) + 1LL * t * max<ll>(0, -x);
	};

	for(int i = 1; i <= n; i++)
		res += cost(arr[i]);
	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;
		r++;
		res -= cost(arr[l]);
		arr[l] += x;
		res += cost(arr[l]);
		if(r <= n) {
			res -= cost(arr[r]);
			arr[r] -= x;
			res += cost(arr[r]);
		}
		cout << res << '\n';
	}
}
