/*
100/100
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n), brr(m);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int j = 0; j < m; j++)
		cin >> brr[j];
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	long long ans = 0;
	while(arr.size() && brr.size()) {
		int x = brr.back();
		brr.pop_back();
		while(arr.size() && arr.back() > x)
			arr.pop_back();
		if(arr.size())
			ans += arr.back(), arr.pop_back();
	}
	cout << ans << '\n';
}
