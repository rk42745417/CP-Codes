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
	int n, m, k, a, b, c;
	cin >> n >> m >> k >> a >> b >> c;
	k -= m;

	ll t;
	cin >> t;

	vector<ll> arr(m), cur(m), nxt(m);
	for(int i = 0; i < m; i++)
		cin >> arr[i], arr[i]--;

	auto cal = [&](int i) { // calculate nxt[i]
		ll g = t - (arr[i] * b + (cur[i] + 1 - arr[i]) * c);
		if(g < 0 || cur[i] + 1 == arr[i + 1]) {
			nxt[i] = cur[i];
			return;
		}
		ll r = min(arr[i + 1] - 1 - (cur[i] + 1), g / a);
		nxt[i] = cur[i] + 1 + r;
	};

	int ans = (arr[m - 1] * b <= t) - 1;
	for(int i = 0; i + 1 < m; i++) {
		ll r = arr[i] * b;
		if(r > t)
			continue;
		ll x = min(arr[i + 1] - arr[i] - 1, (t - r) / a);
		ans += x + 1;
		cur[i] = arr[i] + x;
		cal(i);
	}

	while(k--) {
		int mx = 0, id = 0;
		for(int i = 0; i + 1 < m; i++)
			if(nxt[i] - cur[i] > mx)
				mx = nxt[i] - cur[i], id = i;
		if(mx == 0)
			break;
		ans += mx;
		cur[id] = nxt[id];
		cal(id);
	}
	cout << ans << '\n';
}
