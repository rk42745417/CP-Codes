// ?/100
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("avx2")
//#pragma GCC optimize("unroll-loops")

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const double EPS = 1e-9;

signed main() { EMT
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = 0;
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
			if(arr[j] > arr[i] + 2)
				ans++;
	cout << ans << '\n';
}
