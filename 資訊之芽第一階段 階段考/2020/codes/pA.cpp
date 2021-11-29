/*
pA
50/100
16:39:21
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int res = 0;
			for(int j = i, mx = arr[i]; j < n; j++) {
				if((j-i)&1)
					res += arr[j]*arr[j-1];
				mx = max(mx, arr[j]);
				ans = max(ans, res+mx*mx);
			}
		}
		cout << ans << '\n';
	}
}
