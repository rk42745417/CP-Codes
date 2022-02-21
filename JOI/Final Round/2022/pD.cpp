// 100/100
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
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int LGN = 19, M = 2e5 + 25, N = 1e5 + 25;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}
struct segtree {
	pair<int, int> arr[N << 1], tag[N];
	int n;
	void init(int _n) {
		n = _n;
		for(int i = 0; i < n * 2; i++)
			arr[i] = {INF, -INF};
		for(int i = 0; i < n; i++)
			tag[i] = {INF, -INF};
	}
	void upd(int p, pair<int, int> v) {
		arr[p] = arr[p] + v;
		if(p < n)
			tag[p] = tag[p] + v;
	}
	void push(int p) {
		for(int h = __lg(p); ~h; h--) {
			int i = p >> h;
			upd(i, tag[i >> 1]);
			upd(i ^ 1, tag[i >> 1]);
		}
	}
	void pull(int p) {
		for(; p > 1; p >>= 1)
			arr[p >> 1] = arr[p] + arr[p ^ 1] + tag[p >> 1];
	}
	void edt(int l, int r, pair<int, int> v) {
		int tl = l + n, tr = r + n - 1;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				upd(l++, v);
			if(r & 1)
				upd(--r, v);
		}
		pull(tl); pull(tr);
	}
	pair<int, int> que(int l, int r) {
		pair<int, int> res = {INF, -INF};
		push(l + n); push(r + n - 1);
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = res + arr[l++];
			if(r & 1)
				res = res + arr[--r];
		}
		return res;
	}
} tree[LGN];

signed main() {
	int n, k, m;
	cin >> n >> k >> m;
	vector<pair<int, int>> arr(m);
	for(auto &[a, b] : arr)
		cin >> a >> b;

	for(int i = 0; i < LGN; i++)
		tree[i].init(n + 1);
	for(int i = 1; i <= n; i++)
		tree[0].edt(i, i + 1, {i, i});
	for(const auto &[a, b] : arr) {
		if(a < b)
			tree[0].edt(a, min(b + 1, a + k), {INF, b});
		else
			tree[0].edt(max(b, a - k + 1), a + 1, {b, -INF});
	}
	for(int i = 1; i < LGN; i++) {
		for(int j = 1; j <= n; j++) {
			auto [l, r] = tree[i - 1].que(j, j + 1);
			auto [a, b] = tree[i - 1].que(l, r + 1);
			tree[i].edt(j, j + 1, {a, b});
		}
	}

	auto in = [&](int t, auto inter) {
		return inter.first <= t && t <= inter.second;
	};

	int q;
	cin >> q;
	while(q--) {
		int s, t;
		cin >> s >> t;
		if(!in(t, tree[LGN - 1].que(s, s + 1)))
			cout << "-1\n";
		else {
			int res = 0;
			pair<int, int> owo = {s, s};
			for(int i = LGN - 1; ~i; i--) {
				auto [l, r] = tree[i].que(owo.first, owo.second + 1);
				if(!in(t, make_pair(l, r)))
					owo = {l, r}, res |= 1 << i;
			}
			cout << res + 1 << '\n';
		}

	}
}
