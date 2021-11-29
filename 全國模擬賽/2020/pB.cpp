// ?/100
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define EMT ios::sync_with_stdio(0); cin.tie(0);

signed main() { EMT
	int n, m;
	cin >> n >> m;
	ll cnt[2] = {0};
	for(int i = 0; i < n; i++)
		for(int j = 0, x; j < m; j++)
			cin >> x, cnt[(i + j) % 2]+=x;
	if(cnt[0] + cnt[1] == 0 && (cnt[0] % 2 == 0) && (cnt[1] % 2 == 0))
		cout << "Yes\n";
	else
		cout << "No\n";
}
