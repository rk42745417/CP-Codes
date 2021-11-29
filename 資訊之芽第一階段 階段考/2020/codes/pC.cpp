/*
pC
100/100
15:04:32
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<vector<int>> edge;
vector<int> dis, dep;

void dfs(int now, int pa) {
	for(int &a: edge[now]) {
		if(a == pa)
			continue;
		dep[a] = dep[now] + 1;
		dfs(a, now);
		dis[now] = min(dis[now], dis[a]+1);
	}
}
void dfs2(int now, int pa, int cur) {
	dis[now] = min(dis[now], cur+1);
	for(int &a: edge[now]) {
		if(a == pa)
			continue;
		dfs2(a, now, dis[now]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, root;
	cin >> n >> m;
	edge.resize(n);
	dis.resize(n, INF);
	dep.resize(n, INF);

	for(int i = 0, a, b; i < n-1; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i = 0, a; i < m; i++) {
		cin >> a;
		dis[a] = 0;
	}

	cin >> root;
	dep[root] = 0;
	dfs(root, root);
	dfs2(root, root, INF);

	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(dep[i] < dis[i])
			ans = max(ans, dis[i]);
	}
	cout << ans << '\n';
}
