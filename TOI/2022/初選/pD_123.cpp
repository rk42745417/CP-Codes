// 32/100
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

const int N = 307;
int cnt[N][N][11], a, b;
string ans;

bool dfs(int x, int y, int r) {
	if(cnt[x][y][r] == 2)
		return false;
	cnt[x][y][r]++;
	if(x + y == a + b) {
		if(r == 0 && cnt[x][y][r] == 2)
			return true;
		return false;
	}

	int w = (r * 10 + 2) % 11;
	if(y < b && dfs(x, y + 1, w)) {
		ans += '2';
		return true;
	}
	w = (r * 10) % 11;
	if(x < a && dfs(x + 1, y, w)) {
		ans += '0';
		return true;
	}
	return false;
}
bool dfs2(int x, int y, int r) {
	if(cnt[x][y][r] == 2)
		return false;
	cnt[x][y][r]++;
	if(x + y == a + b) {
		if(r == 0 && cnt[x][y][r] == 2)
			return true;
		return false;
	}
	
	int w = (r * 10) % 11;
	if(x < a && dfs2(x + 1, y, w)) {
		ans += '0';
		return true;
	}
	w = (r * 10 + 2) % 11;
	if(y < b && dfs2(x, y + 1, w)) {
		ans += '2';
		return true;
	}
	return false;
}
signed main() {
	cin >> a >> b;
	if(!dfs(0, 0, 0))
		return cout << "-1\n", 0;
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	
	ans = "";
	memset(cnt, 0, sizeof cnt);
	dfs2(0, 0, 0);
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}
