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
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static int Lamy_is_cute = []() {
	EmiliaMyWife
	return 48763;
}();
/*--------------------------------------------------------------------------------------*/

const int LGN = 20, N = 2e5 + 25;
struct segtree {
	int arr[N << 1], n;
	void init(int _n) {
		n = _n;
		for(int i = 0; i < n * 2; i++)
			arr[i] = INF;
	}
	void edt(int p, int v) {
		p += n;
		for(arr[p] = min(arr[p], v); p > 1; p >>= 1)
			arr[p >> 1] = min(arr[p], arr[p ^ 1]);
	}
	int que(int l, int r) {
		int res = INF;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = min(res, arr[l++]);
			if(r & 1)
				res = min(res, arr[--r]);
		}
		return res;
	}
} tree[LGN];
signed main() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> arr(n);
	vector<int> v;
	for(auto &[a, b] : arr) {
		cin >> a >> b;
		v.push_back(a);
		v.push_back(b);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 0; i < LGN; i++)
		tree[i].init(v.size());
	for(auto &[l, r] : arr) {
		l = lower_bound(v.begin(), v.end(), l) - v.begin();
		r = lower_bound(v.begin(), v.end(), r) - v.begin();
		tree[0].edt(r, l);
	}

	for(int i = 0; i + 1 < LGN; i++) {
		for(int j = 0; j < v.size(); j++) {
			int w = tree[i].que(j, j + 1);
			tree[i + 1].edt(j, tree[i].que(w, j + 1));
		}
	}

	while(q--) {
		int s, t;
		cin >> s >> t;
		if(s == t) {
			cout << 0 << '\n';
			continue;
		}
		s--; t--;
		swap(s, t);

		auto [l, r] = arr[s];
		int x = arr[t].second;
		if(l <= x && x <= r) {
			cout << 1 << '\n';
			continue;
		}
		if(r < x || tree[LGN - 1].que(l, r + 1) > x) {
			cout << "impossible\n";
			continue;
		}
		int res = 0;
		for(int i = LGN - 1; ~i; i--) {
			int g = tree[i].que(l, r + 1);
			if(g > x) {
				res |= 1 << i;
				l = g;
			}
		}
		cout << res + 2 << '\n';
	}
}
