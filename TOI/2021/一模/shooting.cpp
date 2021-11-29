// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EMT ios_base::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 1e9+7;
const ll LINF = 2e18;

const int N = 3e6 + 25;
const int N2 = 5e5 + 25;

bool vis[N2];

struct segtree {
	vector<int> arr[N];
	int n;
	void init(int _n) { n = _n; }
	void insert(int l, int r, int v) {
		//cout << "inserting " << l << ' ' << r << '\n';
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				arr[l++].push_back(v);
			if(r & 1)
				arr[--r].push_back(v);
		}
	}
	inline int get(int p) {
		while(!arr[p].empty() && vis[arr[p].back()])
			arr[p].pop_back();
		if(arr[p].empty())
			return -1;
		return arr[p].back();
	}
	int que(int p) {
		int res = -1;
		//cout << "query begin " << p << '\n';
		for(p += n; p; p >>= 1)
			res = max(res, get(p));
		//cout << "query end " << res << '\n';
		return res;
	}
} tree;

struct seg {
	int l, r, w;
};

signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	vector<int> que(m);
	vector<seg> arr(n);
	
	for(int i = 0, a, b, c; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		arr[i] = {a, b, c};
	}
	for(int i = 0; i < m; i++) {
		cin >> que[i];
		v.push_back(que[i]);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	tree.init(v.size());
	
	for(int i = 0; i < n; i++) {
		auto &[l, r, w] = arr[i];
		l = lower_bound(v.begin(), v.end(), l) - v.begin();
		r = lower_bound(v.begin(), v.end(), r) - v.begin();
		tree.insert(l, r + 1, i);
	}
	
	ll ans = 0;
	for(int x : que) {
		x = lower_bound(v.begin(), v.end(), x) - v.begin();
		int id = tree.que(x);
		if(id == -1)
			continue;
		ans += arr[id].w;
		vis[id] = 1;
	}
	cout << ans << '\n';
}
