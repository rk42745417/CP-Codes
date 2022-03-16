// 7/100
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

const int N = 16;
pair<int, int> dp[(1 << N) + 1][N][N];
signed main() {
	int n, m;
	cin >> n >> m;

	auto id = [&](int a, int b) {
		return a * m + b;
	};
	auto rev = [&](int x) {
		return make_pair(x / m, x % m);
	};
	
	const int s = n * m;
	for(int i = 0; i < (1 << s); i++)
		for(int j = 0; j < s; j++)
			for(int k = 0; k < s; k++)
				dp[i][j][k] = {-1, -1};

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			dp[1 << id(i, j)][id(i, j)][id(i, j)] = {0, 0};

	for(int i = 0; i < (1 << s); i++) {
		for(int j = 0; j < s; j++) {
			for(int k = 0; k < s; k++) {
				if(dp[i][j][k].first == -1)
					continue;
				auto [x, y] = rev(j);
				auto [c, d] = rev(k);
				for(int a = 0; a < n; a++) {
					for(int b = 0; b < m; b++) {
						if(a != x && b != y && abs(a - x) != abs(b - y) && (i >> id(a, b) & 1) == 0) {
							if((i | (1 << id(a, b))) == (1 << s) - 1) {
								if(a != c && b != d && abs(a - c) != abs(b - d))
									dp[(1 << s) - 1][id(a, b)][k] = {i, j};
							}
							else
								dp[i | (1 << id(a, b))][id(a, b)][k] = {i, j};
						}
					}
				}
			}
		}
	}

	int x = -1, y;
	for(int i = 0; i < s; i++)
		for(int j = 0; j < s; j++)
			if(dp[(1 << s) - 1][i][j].first != -1)
				x = i, y = j;
	if(x == -1)
		return cout << "-1\n", 0;
	
	vector<pair<int, int>> ans;
	ans.push_back(rev(y));
	int w = (1 << s) - 1;
	while(w > 0) {
		ans.push_back(rev(x));
		tie(w, x) = dp[w][x][y];
	}
	reverse(ans.begin(), ans.end());
	assert(ans.size() == s + 1);
	for(const auto &[a, b] : ans)
		cout << a + 1 << ' ' << b + 1 << '\n';
}
