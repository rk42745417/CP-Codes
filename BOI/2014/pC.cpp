// 34/100
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
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a;
	bool sol = 1;
	for(int i = 1; i < n; i++)
		if(arr[i] != arr[i - 1])
			sol = 0;
	if(sol) {
		int mn = 0;
		for(int i = 1; ; i++) {
			auto t = to_string(i);
			bool ok = 0;
			for(char c : t)
				ok |= c - '0' == arr[0];
			if(!ok)
				mn = max(mn, i + n);
			if(i >= n && mn <= i)
				return cout << i - n + 1 << '\n', 0;
		}
	}
	for(int i = 1; ; i++) {
		bool ok = 1;
		for(int j = 0; j < n; j++) {
			auto t = to_string(j + i);
			bool res = 0;
			for(char c : t)
				res |= c - '0' == arr[j];
			ok &= res;
		}
		if(ok) {
			cout << i << '\n';
			break;
		}
	}
}
