/*
Club
100/100
00:13:50
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> cnt(n+1, -1), edges(n+1);
	vector<vector<int>> edge(n+1);
	for(int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edges[b]++;
	}
	queue<int> bfs;
	for(int i = 1; i <= n; i++)
		if(!edges[i])
			bfs.push(i);

	int now = 0;
	while(!bfs.empty()) {
		int num = bfs.front();
		bfs.pop();
		if(~cnt[num])
			continue;
		cnt[num] = now++;
		for(int &a: edge[num]) {
			edges[a]--;
			if(!edges[a])
				bfs.push(a);
		}
	}
	bool ans = true;
	for(int i = 1; i <= n; i++) {
		if(!(~cnt[i]))
			ans = false;
	}
	if(ans) {
		cout << "YES\n";
		vector<int> ans(n);
		for(int i = 1; i <= n; i++)
			ans[cnt[i]] = i;
		for(int i = 0; i < n; i++)
			cout << ans[i] << '\n';
	}
	else {
		cout << "NO";
	}
}
