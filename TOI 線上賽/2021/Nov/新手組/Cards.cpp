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
const double EPS = 1e-8;
const ll LINF = ll(2e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a;
	while(k--) {
		vector<int> t(n);
		for(int i = 0; i < n; i++)
			t[i] = arr[i / 2 + (i & 1) * n / 2];
		arr = t;
	}
	for(int a : arr)
		cout << a << ' ';
	cout << '\n';
}
