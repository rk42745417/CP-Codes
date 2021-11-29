// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
static auto LamyIsCute = [] {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1), mx(k + 1, -1);
	multiset<int> owo;
	mx[0] = 0;
	owo.insert(0);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		if(~mx[w]) {
			owo.erase(owo.lower_bound(mx[w]));
		}
		mx[w] = max(mx[w], *owo.rbegin() + arr[i]);
		ans = max(ans, mx[w]);
		owo.insert(mx[w]);
	}
	cout << ans << '\n';
}
