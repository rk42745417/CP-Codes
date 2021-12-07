// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const ll LINF = 4e18;

signed main() { EmiliaMyWife
	int n, s, t;
	cin >> n >> s >> t;
	s--;
	t--;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	vector<vector<int>> edge(n);
	vector<int> cnt(n);
	vector<pair<int, int>> st; // (l, r)
	st.reserve(n);
	for(int i = 0; i < n; i++) {
		while(!st.empty() && arr[st.back().first] > arr[i]) {
			for(int j = st.back().first; j <= st.back().second; j++)
				edge[j].push_back(i), cnt[i]++;
			st.pop_back();
		}
		auto xdd = make_pair(i, i);
		if(!st.empty() && arr[st.back().first] == arr[i]) {
			xdd.first = st.back().first;
			st.pop_back();
		}
		if(!st.empty())
			edge[i].push_back(st.back().second), cnt[st.back().second]++;
		st.push_back(xdd);
	}
	vector<ll> dis(n, LINF);
	queue<int> bfs;
	for(int i = 0; i < n; i++)
		if(!cnt[i])
			bfs.push(i);
	dis[s] = 0;
	ll ans = LINF;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		ans = min(ans, dis[u] + (ll) arr[u] * abs(u - t));
		for(int v : edge[u]) {
			dis[v] = min(dis[v], dis[u] + (ll) arr[u] * abs(u - v));
			cnt[v]--;
			if(!cnt[v])
				bfs.push(v);
		}
	}
	cout << ans << '\n';
}
