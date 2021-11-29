/*
pD
20/100
16:56:17
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, l, ans = 1e18;
	cin >> n >> l;
	vector<int> arr(n);
	vector<int> brr(n);
	vector<int> xx(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++)
		cin >> brr[i];
	for(int i = 0; i < n; i++)
		xx[i] = i;
	do {
		int res = 0;
		for(int i = 0; i < n; i++) {
			res += min(abs(arr[i]-brr[xx[i]]), l-abs(arr[i]-brr[xx[i]]));
		}
		ans = min(ans, res);
	}
	while(next_permutation(xx.begin(), xx.end()));
	cout << ans << '\n';

}
