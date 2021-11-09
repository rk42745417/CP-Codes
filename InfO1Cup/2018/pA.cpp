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

const int N = 1e3 + 25;
struct fenwicktree {
	int arr[N][N];
	void init() {
		for(int i = 1; i < N; i++)
			for(int j = 1; j < N; j++)
				arr[i][j] = -INF;
	}
	void edt(int x, int y, int v) {
		for(; x < N; x += x & -x)
			for(int j = y; j < N; j += j & -j)
				arr[x][j] = max(arr[x][j], v);
	}
	int que(int x, int y) {
		int res = -INF;
		for(; x; x -= x & -x)
			for(int j = y; j; j -= j & -j)
				res = max(arr[x][j], res);
		return res;
	}
} bit[4];

signed main() {
	for(int i = 0; i < 4; i++)
		bit[i].init();
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> arr(n * m);
	for(int i = 0; i < n; i++)
		for(int j = 0, x; j < m; j++)
			cin >> x, arr[i * m + j] = {x, i + 1, j + 1};
	sort(arr.begin(), arr.end());
	int ans = -INF;
	for(const auto &[v, x, y] : arr) {
		bit[0].edt(x, y, + x + y - v);
		bit[1].edt(x, m - y + 1, + x - y - v);
		bit[2].edt(n - x + 1, y, - x + y - v);
		bit[3].edt(n - x + 1, m - y + 1, - x - y - v);
		ans = max(ans, v - x - y + bit[0].que(x, y) - 1);
		ans = max(ans, v - x + y + bit[1].que(x, m - y + 1) - 1);
		ans = max(ans, v + x - y + bit[2].que(n - x + 1, y) - 1);
		ans = max(ans, v + x + y + bit[3].que(n - x + 1, m - y + 1) - 1);
		//cout << v << ' ' << bit[0].que(n, m) << '\n';
	}
	cout << ans << '\n';
}
