/*
100/100
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n), cnt(n), dis(n, -0x3f3f3f3f), ans(n, 1);
	vector<vector<int>> edge(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		if(arr[a] == arr[b])
			continue;
		if(arr[a] < arr[b])
			swap(a, b);
		edge[a].push_back(b);
		cnt[b]++;
	}
	vector<bool> vis(n);
	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;
		for(int v : edge[u]) {
			cnt[v]--;
			if(dis[v] < dis[u] + 1)
				dis[v] = dis[u] + 1, ans[v] = 0;
			if(dis[v] == dis[u] + 1)
				ans[v] += ans[u];
			if(!cnt[v])
				dfs(v);
		}
	};
	dis[0] = 0;
	for(int i = 0; i < n; i++)
		if(!cnt[i] && !vis[i])
			dfs(i);
	if(dis.back() < 0)
		cout << "0\n";
	else
		cout << max(0, ans.back()) << '\n';
}
