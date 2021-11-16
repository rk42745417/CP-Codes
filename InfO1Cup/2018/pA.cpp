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
const double EPS = 1e-8;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
	int ans = -INF;
	auto calc = [&]() {
		vector<vector<int>> mx(n, vector<int>(m, -INF)), mx2(n, vector<int>(m, -INF));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				mx[i][j] = -arr[i][j] + i + j;
				mx2[i][j] = arr[i][j] + i + j;
				if(i) {
					mx[i][j] = max(mx[i][j], mx[i - 1][j]);
					mx2[i][j] = max(mx2[i][j], mx2[i - 1][j]);
				}
				if(j) {
					mx[i][j] = max(mx[i][j], mx[i][j - 1]);
					mx2[i][j] = max(mx2[i][j], mx2[i][j - 1]);
				}
				ans = max(ans, arr[i][j] - i - j + mx[i][j] - 1);
				ans = max(ans, mx2[i][j] - i - j - arr[i][j] - 1);
			}
		}
	};
	calc();
	reverse(arr.begin(), arr.end());
	calc();
	cout << ans << '\n';
}
