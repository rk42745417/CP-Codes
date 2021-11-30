// 100/100
// 00:17:08
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const ll LINF = ll(2e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + m), b(n + m);
	ll cur = 0;
	vector<int> owo(n + m);
	for(int i = 0; i < n + m; i++)
		cin >> a[i] >> b[i], cur += a[i], owo[i] = b[i] - a[i];
	sort(owo.begin(), owo.end());
	cout << cur + accumulate(owo.begin(), owo.begin() + m, 0LL) << '\n';
}
