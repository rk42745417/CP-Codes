/*
pE
100/100
16:00:21
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9+100;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k, ans = -INF;
	//cout << INF;
	cin >> n >> k;
	vector<pair<int,int>> seg(n);
	for(int i = 0; i < n; i++)
		cin >> seg[i].first >> seg[i].second;
	sort(seg.begin(), seg.end());
	unordered_map<int,int> now;
	set<int> has;
	int cnt = 0, x;
	for(int i = 0; i < n; i++) {
		//cout << x << '\n';
		if(i > k-1 && i > 1) {
			if(seg[i-1].second == x) {
				cnt++;
			}
			if(seg[i-1].second > x) {
				cnt++;
				if(cnt == now[x]) {
					x = *has.upper_bound(x);
					cnt = 0;
				}
			}
		}
		if(i == k-1 && i)
			x = *has.begin();
		if(i >= k-1)
			ans = max(ans, min((i?x:INF), seg[i].second)-seg[i].first);
		now[seg[i].second]++;
		has.insert(seg[i].second);
	}
	cout << ans << '\n';
}
