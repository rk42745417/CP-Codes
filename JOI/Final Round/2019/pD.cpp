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
const ll LINF = ll(4e15) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
		return 48763;
}();

signed main() {
	int n;
	cin >> n;
	vector<int> arr(n + 1), brr(n + 1);
	ll ans = 0;
	for(int i = 0; i < n * 2; i++) {
		int x, y;
		cin >> x >> y;
		int a = max(1, min(n, x)), b = max(1, min(2, y));
		ans += abs(a - x) + abs(b - y);
		if(b == 1)
			arr[a]++;
		else
			brr[a]++;
	}
	for(int i = 1, a = 0, b = 0; i <= n; i++) {
		a += arr[i] - 1;
		b += brr[i] - 1;
		int k = min(abs(a), abs(b));
		if(a > 0 && b < 0)
			a -= k, b += k, ans += k;
		if(a < 0 && b > 0)
			a += k, b -= k, ans += k;
		ans += abs(a) + abs(b);
	}
	cout << ans << '\n';
}
