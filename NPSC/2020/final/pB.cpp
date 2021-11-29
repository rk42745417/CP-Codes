#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);

const int INF = 0x3f3f3f3f;
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;

#define int ll
signed main() { EMT
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	if(n == 1) {
		cout << arr[0] << '\n';
		return 0;
	}
	ll s = 0;
	for(int i = 0; i < n; i++)
		s += arr[i];
	ll mn = INF;
	for(int i = 1; i < n; i++)
		mn = min(mn, arr[i]);
	cout << s + mn - arr[0] << '\n'; 
}
