#include <bits/stdc++.h>
using namespace std;

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;

namespace solve1 {
	void solve(int n) {
		vector<int> arr(n);
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		vector<vector<int>> edge(n);
		for(int i = 1, a, b; i < n; i++) {
			cin >> a >> b;
			edge[--a].push_back(--b);
			edge[b].push_back(a);
		}
		function<void(int, int)> dfs = [&](int u, int p) {
			cout << arr[u] << ' ';
			sort(edge[u].begin(), edge[u].end());
			for(int v : edge[u])
				if(v != p)
					dfs(v, u);
		};
		dfs(0, 0);
		cout << '\n';
	}
};

namespace solve2 {
	const int N = 301;
	int arr[N];
	vector<int> edge[N];

	bool cmp(vector<int> &a, vector<int> &b) {
		vector<int> res1, res2;
		for(int x : a)
			res1.push_back(x);
		for(int x : b) {
			res1.push_back(x);
			res2.push_back(x);
		}
		for(int x : a)
			res2.push_back(x);
		return res1 < res2;
	}

	vector<int> dfs(int u, int p) {
		vector<vector<int>> res;
		for(int v : edge[u])
			if(v != p)
				res.push_back(dfs(v, u));//, res.back().push_back(INF);
		sort(res.begin(), res.end(), cmp);
		vector<int> ans;
		ans.push_back(arr[u]);
		for(auto &x : res)
			for(int v : x)
				if(v != INF)
					ans.push_back(v);
		//cout << "at " << u << '\n';
		//for(int v : ans)
			//cout << v << ' ';
		//cout << '\n';
		return ans;
	}

	void solve(int n) {
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		for(int i = 1, a, b; i < n; i++) {
			cin >> a >> b;
			edge[--a].push_back(--b);
			edge[b].push_back(a);
		}
		vector<int> ans(1, INF);
		bool ok = arr[0] == 1;
		for(int i = 1; i < n; i++)
			ok &= arr[i] != 1;
		if(ok)
			ans = dfs(0, 0);
		else
			for(int i = 0; i < n; i++)
				ans = min(ans, dfs(i, i));
		for(int i = 0; i < n; i++)
			cout << ans[i] << " \n"[i == n - 1];
	}
};

signed main() { EMT
	int n;
	cin >> n;
	if(n <= 300)
		solve2::solve(n);
	else
		solve1::solve(n);
}
