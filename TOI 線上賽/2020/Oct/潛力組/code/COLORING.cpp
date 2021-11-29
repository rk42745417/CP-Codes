/*
Coloring
00:20:35
100/100
*/
#include <bits/stdc++.h>
using namespace std;

signed main() { ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k;
	cin >> m >> n >> k;
	vector<pair<int, int>> arr(n);
	vector<int> has;
	for(int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second, arr[i].second++, has.push_back(arr[i].first), has.push_back(arr[i].second);
	sort(arr.begin(), arr.end());
	sort(has.begin(), has.end()); has.erase(unique(has.begin(), has.end()), has.end());
	int prv = 0, ans = 0, xdd = 0;
	multiset<int> owo;
	for(int x : has) {
		if(owo.size() >= k)
			ans += x - prv;
		auto it = owo.begin();
		while(it != owo.end() && *it <= x)
			it = owo.erase(it);
		while(xdd < arr.size() && arr[xdd].first == x)
			owo.insert(arr[xdd++].second);
		prv = x;
	}
	cout << ans << '\n';
}
