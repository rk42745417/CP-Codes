// ?/100
#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 2e18;
const double EPS = 1e-9;

signed main() { EMT
	int n;
	cin >> n;
	vector<ll> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int w = (*max_element(arr.begin(), arr.end()) + 1) / 2;
	ll ans = 0;
	for(int i = 0; i < n; i++)
		ans += max<ll>(0, arr[i] - w + 1);
	cout << ans << '\n';
}
