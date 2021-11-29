// 100/100
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("avx2")
//#pragma GCC optimize("unroll-loops")

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const double EPS = 1e-9;

signed main() { //EMT
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = n - 1; ~i; i--)
		arr[i] -= arr[i - 1];
	ll cur = 0, cur2 = 0;
	for(int i = 1; i < n; i++)
		cur += max(0, -arr[i] + 1);
	ll ans = cur;
	for(int i = n - 1; i; i--) {
		cur -= max(0, -arr[i] + 1);
		cur2 += max(0, arr[i] + 1);
		ans = min(ans, max(cur, cur2));
		//cout << i << ' ' << arr[i] << ' ' << cur << ' ' << cur2 << '\n';
	}
	cout << ans << '\n';
}
