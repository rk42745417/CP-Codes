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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n + 2, vector<int>(m + 1));

	int max_val = -INF, min_val = INF;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			max_val = max(max_val, arr[i][j]);
			min_val = min(min_val, arr[i][j]);
		}
	auto rot = [&]() {
		reverse(arr.begin(), arr.end());
	};
	auto go = [&](int k) {
		pair<int, int> cur_interval = {0, 0};
		for(int i = 1; i <= n; i++) {
			vector<int> suf_min(m + 1);
			for(int j = m; j; j--) {
				suf_min[j] = arr[i][j];
				if(j + 1 <= m)
					suf_min[j] = min(suf_min[j], suf_min[j + 1]);
			}

			pair<int, int> new_interval = {INF, -INF};
			for(int j = 0, mx = 0; j <= m; j++) {
				if(j)
					mx = max(mx, arr[i][j]);
				int r = (j < m ? suf_min[j + 1] : INF);
				if(mx <= min_val + k && max_val - k <= r && cur_interval.first <= j) {
					new_interval.first = min(new_interval.first, j);
					new_interval.second = max(new_interval.second, j);
				}
			}
			cur_interval = new_interval;
		}
		if(cur_interval.first <= cur_interval.second)
			return true;

		cur_interval = {0, 0};
		for(int i = 1; i <= n; i++) {
			vector<int> suf_max(m + 1);
			for(int j = m; j; j--) {
				suf_max[j] = arr[i][j];
				if(j + 1 <= m)
					suf_max[j] = max(suf_max[j], suf_max[j + 1]);
			}

			pair<int, int> new_interval = {INF, -INF};
			for(int j = 0, mn = INF; j <= m; j++) {
				if(j)
					mn = min(mn, arr[i][j]);
				int r = (j < m ? suf_max[j + 1] : 0);
				if(r <= min_val + k && max_val - k <= mn && cur_interval.first <= j) {
					new_interval.first = min(new_interval.first, j);
					new_interval.second = max(new_interval.second, j);
				}
			}
			cur_interval = new_interval;
		}
		if(cur_interval.first <= cur_interval.second)
			return true;
		return false;
	};
	auto check = [&](int k) {
		bool ok = false;
		for(int i = 0; i < 2; i++)
			ok |= go(k), rot();
		return ok;
	};
	int l = 0, r = INF;
	while(l < r) {
		int m = l + r >> 1;
		if(check(m))
			r = m;
		else
			l = m + 1;
	}
	cout << l << '\n';
}
