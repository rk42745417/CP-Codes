#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using uint = uint32_t;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double EPS = 1e-6;

#define int ll

signed main() { EmiliaMyWife
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> owo(r - l + 1);
	for(ll i = 1, j; i <= n; i = j + 1) {
		ll x = n / i;
		j = n / x;
		ll st = n % i, ed = n % j;
		ll ql = n - st + 1, qr = n - ed + 1;
		if(ql < l) {
			ll w = (l - ql + x - 1) / x * x;
			owo[0] += w / x;
			ql += w;
		}
		for(ll w = ql; w <= min(qr, r); w += x)
			owo[w - l]++;
	}
	for(ll i = 0, cur = 0; i <= r - l; i++) {
		cur += owo[i];
		cout << cur;
		if(i != r - l)
			cout << ' ';
		else
			cout << '\n';
	}
}
