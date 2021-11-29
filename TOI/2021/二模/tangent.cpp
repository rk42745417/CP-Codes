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

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*--------------------------------------------------------------------------------------*/

const int N = 5e5 + 25;
struct point {
	int x, y, id;
	bool operator<(const point &b) { return x == b.x ? y < b.y : x < b.x; }
} p[N];

vector<int> v;
inline ll cross(const point &a, const point &b, const point &c) {
	return (v[b.x] - v[a.x]) * 1LL * (c.y - a.y) - (v[c.x] - v[a.x]) * 1LL * (b.y - a.y);
}

struct segment {
	int a, w, h, id;
	bool operator<(const segment &b) { return 1LL * h * b.w < 1LL * b.h * w; }
};

void build_convex(vector<int> &arr) {
	vector<int> tmp;
	tmp.reserve(arr.size());
	for(int i = 0; i < arr.size(); i++) {
		while(tmp.size() > 1 && cross(p[tmp.rbegin()[1]], p[tmp.back()], p[arr[i]]) >= 0)
			tmp.pop_back();
		tmp.push_back(arr[i]);
	}
	arr = tmp;
}

struct segtree {
	vector<int> arr[N * 2];
	int n;
	void init(int _n, int ps) {
		n = _n;
		for(int i = 0; i < ps; i++) {
			if(!arr[p[i].x + n].empty())
				arr[p[i].x + n].pop_back();
			arr[p[i].x + n].push_back(i);
		}
		for(int i = n - 1; i; i--) {
			arr[i].resize(arr[i << 1].size() + arr[i << 1 | 1].size());
			merge(arr[i << 1].begin(), arr[i << 1].end(), arr[i << 1 | 1].begin(), arr[i << 1 | 1].end(), arr[i].begin(), [&](int a, int b) { return a < b; });
			build_convex(arr[i]);
		}
	}
	inline ll tim(point &a, segment &s) { return s.w ? 1LL * s.w * a.y - 1LL * s.h * v[a.x] : a.y; }
	inline bool cmp(int a, int b, segment &s) {
		return tim(p[a], s) == tim(p[b], s) ? v[p[a].x] < v[p[b].x] : tim(p[a], s) > tim(p[b], s);
	}
	inline int get(segment &s, int prv, int pos) {
		vector<int> &cur = arr[pos];
		while(cur.size() > 1 && tim(p[cur.back()], s) < tim(p[cur.rbegin()[1]], s))
			cur.pop_back();
		if(!cur.empty()) {
			if(prv == -1 || cmp(cur.back(), prv, s))
				return cur.back();
			return prv;
		}
		return prv;
	}
	int que(int l, int r, segment s) {
		int res = -1;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = get(s, res, l++);
			if(r & 1)
				res = get(s, res, --r);
		}
		return res;
	}
} tree;

signed main() { EmiliaMyWife
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y, v.push_back(p[i].x), p[i].id = i + 1;
	sort(p, p + n);
	int m;
	cin >> m;

	vector<segment> s(m);
	vector<int> ans(m);
	for(int i = 0; i < m; i++)
		cin >> s[i].a >> s[i].w >> s[i].h, s[i].id = i;

	sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
	sort(s.begin(), s.end());
	for(int i = 0; i < n; i++)
		p[i].x = lower_bound(v.begin(), v.end(), p[i].x) - v.begin();
	
	assert(v.size() < N);
	tree.init(v.size(), n);

	for(const auto &w : s) {
		int l = lower_bound(v.begin(), v.end(), w.a) - v.begin();
		int r = lower_bound(v.begin(), v.end(), w.a + w.w + 1) - v.begin();
		
		ans[w.id] = tree.que(l, r, w);
	}
	for(int i = 0; i < m; i++)
		cout << (~ans[i] ? p[ans[i]].id : -1) << '\n';
}
