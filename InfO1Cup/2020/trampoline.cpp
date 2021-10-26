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
const ll LINF = ll(1e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int r, c, n;
	cin >> r >> c >> n;
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	vector<vector<int>> nxt(20, vector<int>(n));
	for(int i = 0; i < n; i++) {
		auto l = lower_bound(arr.begin(), arr.end(), make_pair(arr[i].first + 1, arr[i].second));
		if(l == arr.end() || l->first != arr[i].first + 1)
			nxt[0][i] = n;
		else
			nxt[0][i] = l - arr.begin();
	}
	for(int i = 1; i < 20; i++)
		for(int j = 0; j < n; j++)
			nxt[i][j] = (nxt[i - 1][j] < n ? nxt[i - 1][nxt[i - 1][j]] : n);
	int q;
	cin >> q;
	auto query = [&]() {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2 || y1 > y2)
			return false;
		if(x1 == x2)
			return true;
		auto it = lower_bound(arr.begin(), arr.end(), make_pair(x1, y1)) - arr.begin();
		if(it == n || arr[it].first != x1)
			return false;
		for(int i = 19; ~i; i--) {
			if(nxt[i][it] < n && arr[nxt[i][it]].first < x2)
				it = nxt[i][it];
		}
		return arr[it].first == x2 - 1 && arr[it].second <= y2;
	};
	while(q--) {
		cout << (query() ? "Yes" : "No") << '\n';
	}
}
