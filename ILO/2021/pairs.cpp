// 96/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

int distinct(vector<int> s);

vector<int> init;
int query(int l, int r) {
	vector<int> tmp;
	for(int i = l; i <= r; i++)
		tmp.push_back(init[i - 1]);
	return distinct(tmp);
}
int query2(int u, vector<int> &arr, int l, int r) {
	vector<int> tmp = {u};
	for(int i = l; i <= r; i++)
		tmp.push_back(arr[i]);
	int g = distinct(tmp);
	assert(g == r - l + 1 || g == r - l + 2);
	return g;
}
vector<pair<int, int>> ans;
vector<int> solve(int l, int r, int cnt) { // [l, r]
	if(cnt == 0) {
		vector<int> tmp;
		for(int i = l; i <= r; i++)
			tmp.push_back(init[i - 1]);
		return tmp;
	}
	if(l == r - 1) {
		ans.push_back({init[l - 1], init[r - 1]});
		return vector<int>();
	}
	int m = l + r >> 1;
	int lone = r - l + 1 - 2 * cnt;
	int a = query(l, m);
	int b = query(m + 1, r);
	
	int left_right = a + b - cnt - lone;
	auto x = solve(l, m, (m - l + 1) - a);
	auto y = solve(m + 1, r, (r - m) - b);

	if(y.empty())
		return x;
	if(x.empty())
		return y;

	if(x.size() > y.size())
		swap(x, y);
	vector<int> new_x;
	//shuffle(x.begin(), x.end(), mt19937());

	for(int u : x) {
		if(left_right == 0 || query2(u, y, 0, y.size() - 1) == y.size() + 1) {
			new_x.push_back(u);
			continue;
		}
		int l = 0, r = y.size() - 1;
		while(l < r) {
			int m = l + r >> 1;
			if(query2(u, y, l, m) == m - l + 2)
				l = m + 1;
			else
				r = m;
		}
		ans.push_back({u, y[l]});
		y.erase(y.begin() + l);
		left_right--;
	}
	for(int w : y)
		new_x.push_back(w);
	return new_x;
}
vector<pair<int, int>> train(int n) {
	init.resize(n * 2);
	for(int i = 0; i < n * 2; i++)
		init[i] = i + 1;
	shuffle(init.begin(), init.end(), mt19937());
	solve(1, 2 * n, n);
	return ans;
}
