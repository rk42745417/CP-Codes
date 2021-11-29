// 100/100
#include<bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ld = long double;

signed main() { EmiliaMyWife
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edge(n);
	vector<bool> vis(n);
	for(int i = 0, a, b; i < m; i++)
		cin >> a >> b, edge[a].push_back(b), edge[b].push_back(a);
	int a = 0, b = 0;
	const function<bool(int, int)> dfs = [&] (int u, int p) {
		vis[u] = 1;
		bool ok = 0;
		for(int v : edge[u]) {
			if(v == p)
				continue;
			if(vis[v])
				ok = 1;
			else
				ok |= dfs(v, u);
		}
		return ok;
	};
	for(int i = 0; i < n; i++) {
		if(vis[i])
			continue;
		a++;
		b += dfs(i, i);
	}
	cout << a << ' ' << b << '\n';
}

