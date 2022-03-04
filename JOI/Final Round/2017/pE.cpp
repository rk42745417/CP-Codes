// 0/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(4e48) + ll(2e15);
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n), ans(m, INF);
	for(int i = 0; i < n; i++)
		cin >> arr[i], arr[i]--;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < (1 << n); k++) {
				vector<int> owo(n);
				for(int w = 0; w < n; w++) {
					if(k >> i & 1)
						owo[w] = i;
					else
						owo[w] = j;
				}
				vector<vector<bool>> dp(n, vector<bool>(n));
				for(int r = 1; r < n; r++) {
					dp[r - ][r] = true;
					for(int l = r - 2; ~l; l--) {
					}
				}
			}
		}

	for(int i = 0; i < m; i++)
		cout << ans[i] << '\n';
}
