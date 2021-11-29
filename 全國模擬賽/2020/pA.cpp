// 100/100
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define EMT ios::sync_with_stdio(0); cin.tie(0);

signed main() { EMT
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >>a[i] >> b[i];
	map<pair<int, int>, int> cnt;
	ll ans = 0;
	for(int i = 0; i <n ; i++) {
		ans += cnt[{a[i] % 2, b[i] % 2}];
		cnt[{a[i] % 2, b[i] % 2}]++;
	}
	cout << ans << '\n';
}
