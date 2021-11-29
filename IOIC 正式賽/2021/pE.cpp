#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie();
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

signed main() { EmiliaMyWife
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int m = n / 2;
	map<int, int> cnt;
	for(int i = 0; i < (1 << m); i++) {
		int res = 0;
		for(int j = 0; j < m; j++)
			if(i >> j & 1)
				res ^= arr[j];
		cnt[res]++;
	}
	int ans = 0;
	for(int i = 0; i < (1 << (n - m)); i++) {
		int res = 0;
		for(int j = 0; j < n - m; j++)
			if(i >> j & 1)
				res ^= arr[j + m];
		if(cnt.count(res))
			ans += cnt[res];
	}
	cout << ans << '\n';
}
