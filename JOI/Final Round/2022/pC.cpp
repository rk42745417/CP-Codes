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
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 507;
double dp[N][N];

signed main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> arr(n);
	int can = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		if(arr[i].second == -1)
			arr[i].second = INF;
		else
			can++;
	}
	sort(arr.begin(), arr.end(), [&](auto a, auto b) { return a.second < b.second; });
	double ans = 1e18;

	for(int i = 0; i <= min(can, k); i++) {
		for(int j = 0; j < N; j++)
			for(int l = 0; l < N; l++)
				dp[j][l] = 1e18;
		dp[0][0] = 0;
		for(int j = 0; j < n; j++) {
			for(int l = 0; l <= min(j, k - i); l++) {
				if(dp[j][l] > 1e9)
					continue;
				int r = j - l;
				if(r < i)
					dp[j + 1][l] = min(dp[j + 1][l], dp[j][l] + double(arr[j].second) / (r + 1));
				else
					dp[j + 1][l] = min(dp[j + 1][l], dp[j][l]);
				dp[j + 1][l + 1] = min(dp[j + 1][l + 1], dp[j][l] + double(arr[j].first) / (i + 1));
			}
		}
		ans = min(ans, dp[n][k - i]);
	}

	cout << fixed << setprecision(15) << ans << '\n';
}
