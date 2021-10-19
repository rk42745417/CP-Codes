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
const ll LINF = 4e18;
const double EPS = 1e-8;

const int N = 4e4 + 25;
struct segtree {
	struct node {
		ll ans, no_left, no_right, no_both;
		node(): ans(0), no_left(0), no_right(0), no_both(0) { }
		node(int x): ans(x), no_left(0), no_right(0), no_both(0) { }
		friend node operator+(node a, node b) {
			node res = node();
			res.ans = max({a.ans, b.ans, a.no_right + b.ans, a.ans + b.no_left});
			res.no_left = max(a.no_left + b.no_left, a.no_both + b.ans);
			res.no_right = max(a.no_right + b.no_right, a.ans + b.no_both);
			res.no_both = max(a.no_both + b.no_right, a.no_left + b.no_both);
			return res;
		}
	} arr[N << 1];
	int n;
	void init(vector<int> &a) {
		n = a.size();
		for(int i = 0; i < n; i++)
			arr[i + n] = node(a[i]);
		for(int i = n - 1; i; i--)
			arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}
	void edt(int p, int v) {
		for(arr[p += n] = node(v); p > 1; p >>= 1)
			arr[p >> 1] = arr[p & (p ^ 1)] + arr[p | 1];
	}
	ll que(int l, int r) {
		node lres = node(), rres = node();
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				lres = lres + arr[l++];
			if(r & 1)
				rres = arr[--r] + rres;
		}
		return (lres + rres).ans;
	}
} tree;
signed main() { EmiliaMyWife
	const string PROBLEM = "optmilk";
	freopen((PROBLEM + ".in").c_str(), "r", stdin);
	freopen((PROBLEM + ".out").c_str(), "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for(int &x : arr)
		cin >> x;
	tree.init(arr);
	ll ans = 0;
	while(q--) {
		int p, v;
		cin >> p >> v;
		tree.edt(p - 1, v);
		ans += tree.que(0, n);
	}
	cout << ans << '\n';
}
