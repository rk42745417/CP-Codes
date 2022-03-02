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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);

	for(auto &[v, s] : arr)
		cin >> s >> v;
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	
	vector<int> brr(m);
	for(int &a : brr)
		cin >> a;
	sort(brr.begin(), brr.end());
	reverse(brr.begin(), brr.end());

	int k = 0;
	for(const auto &[_, s] : arr) {
		if(k < m && brr[k] >= s)
			k++;
	}
	cout << k << '\n';
}
