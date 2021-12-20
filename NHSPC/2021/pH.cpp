// 40/100
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
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, k, p;
	cin >> n >> k >> p;
	int r = n - k;

	deque<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	if(k == 2) {
		int ans = INF;
		for(int i = 1; i < n; i++)
			ans = min(ans, arr[i] - arr[i - 1]);
		cout << ans << '\n';
		return 0;
	}

	multiset<int> has = {arr[1] - arr[0]};
	for(int i = 2; i < k; i++)
		has.insert(arr[i] - arr[i - 2]);
	pair<int, int> cur = {*has.rbegin(), 0};

	for(int i = 0; i < r; i++) {
		has.erase(has.lower_bound(arr[i + 1] - arr[i]));
		has.erase(has.lower_bound(arr[i + 2] - arr[i]));
		has.insert(arr[i + 2] - arr[i + 1]);
		has.insert(arr[i + 3] - arr[i + 1]);

		has.insert(arr[k + i] - arr[k + i - 1]);
		cur = min(cur, make_pair(*has.rbegin(), i + 1));
	}

	for(int i = 0; i < r - cur.second; i++)
		arr.pop_back();
	for(int i = 0; i < cur.second; i++)
		arr.pop_front();

	n = k;

	deque<int> owo = {arr.back()};
	arr.pop_back();
	while(!arr.empty()) {
		int u = arr.back();
		arr.pop_back();
		if(owo.front() > owo.back())
			owo.push_front(u);
		else
			owo.push_back(u);
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, abs(owo[i] - owo[(i + 1) % n]));
	cout << ans << '\n';
}
