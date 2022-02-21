// 10/100
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

signed main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> arr(h, vector<int>(w));
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			cin >> arr[i][j];
	int ans = 0;
	for(int a = 0; a < h; a++) {
		for(int b = 0; b < w; b++) {
			for(int c = a; c < h; c++) {
				for(int d = b; d < w; d++) {

					vector<tuple<int, int, int>> owo;
					for(int x = a; x <= c; x++)
						for(int y = b; y <= d; y++)
							owo.push_back({arr[x][y], x, y});

					sort(owo.begin(), owo.end());
					bool ok = 1;
					int pa = -1, pb = 0;
					for(const auto &[_, x, y] : owo) {
						if(pa != -1 && abs(pa - x) + abs(pb - y) > 1)
							ok = 0;
						pa = x;
						pb = y;
					}
					//if(ok)
						//cout << "owo " << a << ' ' << b << ' ' << c << ' ' << d << '\n';
					ans += ok;
				}
			}
		}
	}
	cout << ans << '\n';
}
