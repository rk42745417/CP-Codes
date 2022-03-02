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
	vector<string> arr(n);
	vector<vector<int>> cnt(n, vector<int>(m));
	ll ans = 0;
	for(auto &s : arr)
		cin >> s;
	for(int i = n - 1; ~i; i--) {
		for(int j = 0; j < m; j++) {
			if(i + 1 < n)
				cnt[i][j] = cnt[i + 1][j];
			if(arr[i][j] == 'I')
				cnt[i][j]++;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = m - 1, res = 0; ~j; j--) {
			if(arr[i][j] == 'O')
				res++;
			if(arr[i][j] == 'J')
				ans += res * cnt[i][j];
		}
	}
	cout << ans << '\n';
}
