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
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n + 1);
	vector<int> ans(n + 1), brr(n);
	for(int i = 0; i < n + 1; i++)
		cin >> arr[i].first, arr[i].second = i;
	for(int i = 0; i < n; i++)
		cin >> brr[i];
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	multiset<int> has;
	for(int i = 0; i < n; i++)
		has.insert(arr[i + 1].first - brr[i]);

	for(int i = 0; i <= n; i++) {
		ans[arr[i].second] = *has.rbegin();

		if(i < n) {
			has.erase(has.lower_bound(arr[i + 1].first - brr[i]));
			has.insert(arr[i].first - brr[i]);
		}
	}
	for(int a : ans)
		cout << a << ' ';
	cout << '\n';
}
