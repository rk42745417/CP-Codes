// 40/100 (subtask 3, 4)
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

const int N = 1.5e5 + 25;
struct segtree {
	struct node {
		int mn, cnt;
		int smn, scnt;
		node operator+(node b) {
			node res;
			res.mn = min(mn, b.mn);
			res.smn = min(smn, b.smn);
			if(mn > res.mn)
				res.smn = min(res.smn, mn);
			if(b.mn > res.mn)
				res.smn = min(res.smn, b.mn);

			res.cnt = res.scnt = 0;
			if(res.mn == mn)
				res.cnt += cnt;
			if(res.mn == b.mn)
				res.cnt += b.cnt;

			if(res.smn == mn)
				res.scnt += cnt;
			if(res.smn == b.mn)
				res.scnt += b.cnt;
			if(res.smn == b.smn)
				res.scnt += b.scnt;
			if(res.smn == smn)
				res.scnt += scnt;
			return res;
		}
	} arr[N << 1];
	int n, tag[N];
	void init(int _n) {
		n = _n;
		for(int i = 0; i < n; i++)
			arr[i + n] = {INF, 1, INF + 1, 0};
		for(int i = n - 1; i; i--)
			arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}
	void upd(int p, int v) {
		arr[p].mn += v;
		arr[p].smn += v;
		if(p < n)
			tag[p] += v;
	}
	void pull(int p) {
		for(; p > 1; p >>= 1) {
			arr[p >> 1] = arr[p] + arr[p ^ 1];
			arr[p >> 1].mn += tag[p >> 1];
			arr[p >> 1].smn += tag[p >> 1];
		}
	}
	void push(int p) {
		for(int h = __lg(p); ~h; h--) {
			int i = p >> h;
			upd(i, tag[i >> 1]);
			upd(i ^ 1, tag[i >> 1]);
			tag[i >> 1] = 0;
		}
	}
	void edt(int l, int r, int v) {
		int tl = l + n, tr = r + n - 1;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				upd(l++, v);
			if(r & 1)
				upd(--r, v);
		}
		pull(tl);
		pull(tr);
	}
	node que(int l, int r) {
		push(l + n); push(r + n - 1);
		node res;
		res.mn = INF;
		res.smn = INF + 1;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = arr[l++] + res;
			if(r & 1)
				res = arr[--r] + res;
		}
		return res;
	}
} tree;

signed main() {
	int n, l, r;
	cin >> n >> l >> r;
	tree.init(n);
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	map<int, int> pos, prv;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		tree.edt(i, i + 1, -INF);
		if(pos.count(arr[i]))
			tree.edt(pos[arr[i]] + 1, i + 1, 1);
		else
			tree.edt(0, i + 1, 1);
		if(prv.count(arr[i]))
			tree.edt(prv[arr[i]] + 1, pos[arr[i]] + 1, -1);

		if(pos.count(arr[i]))
			prv[arr[i]] = pos[arr[i]];
		else
			prv[arr[i]] = -1;
		pos[arr[i]] = i;
		auto w = tree.que(0, i + 1);
		if(w.mn == l)
			ans += w.cnt;
		if(w.smn == l)
			ans += w.scnt;
	}
	cout << ans << '\n';
}
