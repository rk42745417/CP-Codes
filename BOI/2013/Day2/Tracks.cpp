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

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
signed main() {
	int h, w;
	cin >> h >> w;
	vector<string> arr(h);
	vector<vector<bool>> has(h, vector<bool>(w));
	for(int i = 0; i < h; i++)
		cin >> arr[i];

	queue<pair<int, int>> nd[2];
	assert(arr[0][0] != '.');

	int cur = arr[0][0] == 'F', ans = 0;
	nd[arr[0][0] == 'F'].push({0, 0});
	has[0][0] = true;
	while(!nd[0].empty() || !nd[1].empty()) {
		ans++;
		while(!nd[cur].empty()) {
			auto [a, b] = nd[cur].front();
			nd[cur].pop();
			for(int i = 0; i < 4; i++) {
				int x = a + dx[i], y = b + dy[i];
				if(x >= 0 && x < h && y >= 0 && y < w) {
					if(!has[x][y] && arr[x][y] != '.') {
						has[x][y] = true;
						nd[arr[x][y] == 'F'].push({x, y});
					}
				}
			}
		}
		cur = !cur;
	}
	cout << ans << '\n';
}
