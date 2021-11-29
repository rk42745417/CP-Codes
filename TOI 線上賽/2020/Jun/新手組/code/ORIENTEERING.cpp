/*
 Orienteering
 100/100
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k;
	char w;
	cin >> n >> m >> k;
	map<char,pair<int,int>> ans;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> w;
			if(w <= 'z' && w >= 'a')
				ans[w] = {i, j};
		}
	if(ans.size() < k) 
		return cout << "Mission fail.\n", 0;
	int cnt = 0;
	for(auto &a : ans)
		if(cnt++<k)
			cout << a.second.first << ' ' << a.second.second << '\n';
}
