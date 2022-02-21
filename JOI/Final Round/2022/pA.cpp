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
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	ll it = 0, cur = 0, prv = -1;
	int q;
	cin >> q;
	while(q--) {
		ll x;
		cin >> x;
		while(cur < x) {
			ll w = 1;
			while(arr[it] % 2 == 0)
				w *= 2, arr[it] /= 2;
			cur += w;
			prv = arr[it];
			it++;
		}
		cout << prv << '\n';
	}
}
