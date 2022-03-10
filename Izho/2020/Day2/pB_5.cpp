// 20/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const ll LINF = ll(4e18) + ll(2e15);
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 1e5 + 25;
struct segtreemx {
	int arr[N << 1], n;
	void init(int _n) {
		n = _n;
		for(int i = 0; i < 2 * n; i++)
			arr[i] = -INF;
	}
	void edt(int p, int v) {
		p += n;
		for(arr[p] = max(arr[p], v); p > 1; p >>= 1)
			arr[p >> 1] = max(arr[p], arr[p ^ 1]);;
	}
	int que(int l, int r) {
		int res = -INF;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = max(res, arr[l++]);
			if(r & 1)
				res = max(res, arr[--r]);
		}
		return res;
	}
} lb;
struct segtreemn {
	int arr[N << 1], n;
	void init(int _n) {
		n = _n;
		for(int i = 0; i < 2 * n; i++)
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
} rb;

signed main() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
	}

	lb.init(q);
	rb.init(q);
	int id = 0;
	while(q--) {
		int ty;
		cin >> ty;
		if(ty == 1) {
			int u, t;
			cin >> u >> t;
			lb.edt(id, u + t);
			rb.edt(id, u - t);
			id++;
		}
		else {
			int l, r, t;
			cin >> l >> r >> t;
			l--;
			
			ll a = ll(lb.que(l, r)) - t, b = ll(rb.que(l, r)) + t;
			a = max<ll>(1, a);
			b = min<ll>(b, n);
			cout << max<ll>(0, b - a + 1) << '\n';
		}
	}
}
