/*
 Cake
 100/100
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	int ans = 0;
	vector<int> arr(n+1);
	for(int i = 1; i <= n; i++)
		cin >> arr[i], arr[i] += arr[i-1];
	deque<int> mn;
	mn.push_back(0);
	//cout << mn.front() << '\n';
	for(int i = 1; i <= n; i++) {
		while(mn.size() && (i-mn.front()) > k)
			mn.pop_front();
		ans = max(ans, arr[i]-arr[mn.front()]);
		while(mn.size() && arr[mn.back()] >= arr[i])
			mn.pop_back();
		mn.push_back(i);
	}
	cout << ans << '\n';
}
