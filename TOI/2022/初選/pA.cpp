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
	int n, r;
	cin >> n >> r;
	map<pair<int, int>, int> cnt;
	auto dis= [&](int a, int b) { return a * a + b * b; };
	while(n--) {
		int x, y;
		cin >> x >> y;
		for(int i = x - 10; i <= x + 10; i++)
			for(int j = y - 10; j <= y + 10; j++)
				if(dis(x - i, y - j) <= r * r)
					cnt[{i, j}]++;
	}
	int ans = 0;
	for(const auto &[a, b] : cnt)
		ans += b & 1;
	cout << ans << '\n';
}
