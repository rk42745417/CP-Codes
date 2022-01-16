// 100/100
/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"
#define print(x) emilia_mata_tenshi(#x, begin(x), end(x))
template<typename T> void emilia_mata_tenshi(const char *s, T l, T r) {
	cerr << "\e[1;33m" << s << " = [";
	while(l != r) {
		cerr << *l;
		cerr << (++l == r ? ']' : ',');
	}
	cerr << "\e[0m\n";
}

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-7;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static int Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

struct dat {
	priority_queue<ll> slope;
	ll l = 0, r = 0;
	ll zero_ans = 0;
	int zero_slope = 0;
	inline int size() { return slope.size(); }
	void shift(int c) {
		while(slope.size() > zero_slope)
			slope.pop();
		if(zero_slope == 0) {
			zero_slope++;
		}
		else
			slope.pop();
		l += c, r += c;
		slope.push(l);
		slope.push(r);
		zero_ans += c;
	}
	void update() {
		while(slope.size() > zero_slope + 1)
			slope.pop();
		ll a = slope.top(); slope.pop();
		l = slope.top();
		r = a;
		slope.push(a);
	}
	void merge(dat b) {
		while(!b.slope.empty()) {
			slope.push(b.slope.top());
			b.slope.pop();
		}
		zero_ans += b.zero_ans;
		zero_slope += b.zero_slope;
	}
};

signed main() {
	int n, m;
	cin >> n >> m;
	n += m;
	vector<vector<pair<int, int>>> edge(n + 1);
	for(int i = 2; i <= n; i++) {
		int p, c;
		cin >> p >> c;
		edge[p].push_back({i, c});
	}
	vector<dat> arr(n + 1);
	function<void(int)> dfs = [&](int u) {
		if(edge[u].empty())
			return;
		for(const auto &[v, c] : edge[u]) {
			dfs(v);
			arr[v].shift(c);
			if(arr[u].slope.empty()) {
				swap(arr[u], arr[v]);
				continue;
			}
			if(arr[v].size() > arr[u].size())
				swap(arr[u], arr[v]);
			arr[u].merge(arr[v]);
		}

		arr[u].update();
	};
	dfs(1);
	ll cur = arr[1].zero_ans, sl = -arr[1].zero_slope;
	vector<ll> ch;
	while(!arr[1].slope.empty()) {
		ch.push_back(arr[1].slope.top());
		arr[1].slope.pop();
	}
	reverse(ch.begin(), ch.end());
	ll prv = 0;
	for(ll a : ch) {
		cur += (a - prv) * sl;
		sl++;
		if(sl == 0)
			break;
		prv = a;
	}
	cout << cur << '\n';
}
