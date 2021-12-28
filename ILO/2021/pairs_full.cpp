// 100/100
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

int query(int u, vector<int> &arr, int l, int r) {
	vector<int> tmp = {u};
	for(int i = l; i <= r; i++)
		tmp.push_back(arr[i]);
	int g = distinct(tmp);
	assert(g == r - l + 1 || g == r - l + 2);
	return g;
}
vector<pair<int, int>> train(int n) {
	vector<int> init(n * 2);
	vector<pair<int, int>> ans;
	for(int i = 0; i < n * 2; i++)
		init[i] = i + 1;
	shuffle(init.begin(), init.end(), mt19937());
	vector<int> has;
	for(int a : init) {
		if(query(a, has, 0, has.size() - 1) == has.size()) {
			int l = 0, r = has.size() - 1;
			while(l < r) {
				int m = l + r >> 1;
				if(query(a, has, l, m) == m - l + 1)
					r = m;
				else
					l = m + 1;
			}
			ans.push_back({a, has[l]});
			has.erase(has.begin() + l);
		}
		else
			has.push_back(a);
	}
	return ans;
}
