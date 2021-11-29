/*
 Plant
 100/100
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
	int m, n;
	cin >> m >> n;
	vector<int> dp(m+1);
	vector<pair<int,int>> seg(n);
	for(int i = 0; i < n; i++)
		cin >> seg[i].first >> seg[i].second;
	sort(seg.begin(), seg.end(), [](pair<int,int> a, pair<int,int> b) {
		return a.second < b.second;
	});
	int it = 0;
	for(int i = 1; i <= m; i++) {
		while(it < n && seg[it].second == i) {
			dp[i] = max(dp[i], dp[seg[it].first]+i-seg[it].first);
			it++;
		}
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[m];

	return 0;
}
