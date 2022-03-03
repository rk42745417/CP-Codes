// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const ll LINF = ll(4e18) + ll(2e15);
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(auto &a : arr)
		cin >> a;
	vector<int> owo(n - 1);
	for(int i = 0; i < n - 1; i++)
		owo[i] = arr[i + 1] - arr[i] - 1;
	sort(owo.begin(), owo.end(), greater<int>());
	cout << arr.back() - arr[0] + 1 - accumulate(owo.begin(), owo.begin() + k - 1, 0) << '\n';
}
