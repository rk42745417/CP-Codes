#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);

using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;

int n;
constexpr int N = 5e5 + 7;
int ans[N];
vector<int> edge[N];

void dfs(int u) {
	assert(ans[u] == 0);
	set<int> has;
	for(int v : edge[u]) {
		if(ans[v])
			has.insert(ans[v]);
	}
	for(int i = 1; ; i++) {
		if(!has.count(i)) {
			ans[u] = i;
			break;
		}
	}
	for(int v : edge[u]) {
		if(ans[v])
			assert(ans[u] != ans[v]);
		else
			dfs(v);
	}
}

signed main() { EMT
	int m;
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1);
	int mx = 0;
	for(int i = 1; i <= n; i++)
		mx = max(mx, ans[i]);
	cout << mx << '\n';
	for(int i = 1; i <= n; i++) {
		cout << ans[i];
		if(i == n)
			cout << '\n';
		else
			cout << ' ';
	}
}
