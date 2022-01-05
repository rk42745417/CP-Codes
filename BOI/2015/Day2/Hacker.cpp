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
const double EPS = 1e-6;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	vector<int> arr(n * 2);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	ll sum = 0;
	const int sz = (n + 1) / 2;
	deque<pair<ll, int>> line;
	ll ans = 0;
	for(int i = 0; i < n * 2; i++) {
		sum += arr[i];
		if(i - sz >= 0)
			sum -= arr[i - sz];
		while(!line.empty() && line.front().second <= (i - sz + 1) - sz)
			line.pop_front();
		while(!line.empty() && line.back().first >= sum)
			line.pop_back();
		line.push_back({sum, i - sz + 1});
		if(i - sz + 1 >= 0)
			ans = max(ans, line.front().first);
	}
	cout << ans << '\n';
}
