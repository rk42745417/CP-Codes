// 100/100
#include "grader.h"
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;

//int query(vector<int>);

void solve(int n) {
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		arr[i] = i + 1;
	mt19937 rnd(time(0));
	while(true) {
		int w = query(arr);
		if(w == n)
			return;
		if(w == 0)
			break;
		shuffle(arr.begin(), arr.end(), rnd);
	}
	vector<pair<int, int>> valid;
	auto my_query = [&](vector<pair<int, int>> &owo) {
		for(const auto &[a, b] : owo)
			swap(arr[a], arr[b]);
		int w = query(arr);
		for(const auto &[a, b] : owo)
			swap(arr[a], arr[b]);
		return w;
	};
	bool flag = false;
	function<void(int, int, vector<pair<int, int>>&, int)> divide = [&](int l, int r, vector<pair<int, int>> &pairs, int sum) {
		if(sum == 0 || flag)
			return;
		if(l == r - 1) {
			valid.push_back(pairs[l]);
			return;
		}
		vector<pair<int, int>> xdd;
		int m = l + r >> 1;
		for(int i = l; i < m; i++)
			xdd.push_back(pairs[i]);
		int ls = my_query(xdd), rs = sum - ls;
		if(ls == n)
			flag = true;
		divide(l, m, pairs, ls);
		divide(m, r, pairs, rs);
	};
	for(int i = 1; i <= n; i++) {
		vector<pair<int, int>> has;
		for(int j = 0; j < n; j++) {
			int k = (i - j + n) % n;
			if(j < k)
				has.push_back({j, k});
		}
		divide(0, has.size(), has, my_query(has));
		if(flag)
			return;
	}
	assert(!valid.empty() && valid.size() <= n);
	//cerr << "collected all pairs: ";
	//for(const auto &[a, b] : valid)
		//cerr << a << ' ' << b << '\n';
	//cerr << "----------------\n";
	vector<vector<int>> edge(n);
	for(const auto &[a, b] : valid) {
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<bool> vis(n);
	function<void(int, vector<int>&)> dfs = [&](int u, vector<int>&tra) {
		vis[u] = true;
		tra.push_back(u);
		for(int v : edge[u])
			if(!vis[v])
				dfs(v, tra);
	};
	vector<bool> owo;
	vector<vector<int>> travs;
	vector<int> ans = arr;
	for(int i = 0; i < n; i++) {
		if(vis[i])
			continue;
		vector<int> tra;
		dfs(i, tra);
		//cerr << i << "-th traversal: ";
		//for(int a : tra)
			//cerr << a << ' ';
		//cerr << '\n';
		for(int i = 0; i < tra.size(); i++) {
			ans[tra[i]] = arr[tra[(i + 1) % tra.size()]];
		}
		int w = query(ans);
		if(w == n)
			return;
		if(w > 0)
			owo.push_back(true);
		else
			owo.push_back(false);
		travs.push_back(tra);
		ans = arr;
	}
	for(int i = 0; i < owo.size(); i++) {
		if(owo[i]) {
			auto &tra = travs[i];
			for(int j = 0; j < tra.size(); j++) {
				ans[tra[j]] = arr[tra[(j + 1) % tra.size()]];
			}
		}
		else {
			auto &tra = travs[i];
			for(int j = 0; j < tra.size(); j++)
				ans[tra[(j + 1) % tra.size()]] = arr[tra[j]];
		}
	}
	assert(query(ans) == n);
}

/*
vector<int> arr;
int query(vector<int> g) {
	int w = 0;
	for(int i = 0; i < g.size(); i++)
		w += arr[i] == g[i];
	cout << "query: ";
	for(int a : g)
		cout << a << ' ';
	cout << '\n';
	cout << "Answer: " << w << '\n';
	return w;
}
signed main() {
	int n;
	cin >> n;
	arr.resize(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	solve(n);
}
*/
