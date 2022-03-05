// 110/110
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(4e18) + ll(2e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 1e6 + 25;
struct segtree {
	int arr[N << 1], n;
	multiset<int> has[N];
	void init(int _n) { n = _n; }
	void edt(int p, int v, int t) {
		if(t == 1)
			has[p].insert(v);
		else
			has[p].erase(v);
		arr[p + n] = has[p].empty() ? 0 : *has[p].rbegin();
		for(p += n; p > 1; p >>= 1)
			arr[p >> 1] = max(arr[p], arr[p ^ 1]);
	}
	int que(int l, int r) {
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res = max(res, arr[l++]);
			if(r & 1)
				res = max(res, arr[--r]);
		}
		return res;
	}
} tree;

signed main() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> fac(n + 1);
	vector<bool> cur(n + 1);
	vector<set<int>> has(n + 1, {0});
	for(int i = 2; i <= n; i++)
		if(fac[i].empty())
			for(int j = i; j <= n; j += i)
				fac[j].push_back(i);

	auto add = [&](int x) {
		cur[x] = true;
		for(int p : fac[x]) {
			auto it = has[p].lower_bound(x);
			if(it != has[p].end()) {
				tree.edt(*it, *prev(it), 0);
				tree.edt(*it, x, 1);
			}
			tree.edt(x, *prev(it), 1);
			has[p].insert(x);
		}
	};
	auto rem = [&](int x) {
		cur[x] = false;
		for(int p : fac[x]) {
			has[p].erase(x);
			auto it = has[p].lower_bound(x);
			if(it != has[p].end()) {
				tree.edt(*it, *prev(it), 1);
				tree.edt(*it, x, 0);
			}
			tree.edt(x, *prev(it), 0);
		}
	};

	tree.init(n + 1);
	while(q--) {
		char c;
		cin >> c;
		if(c == 'S') {
			int x;
			cin >> x;
			if(cur[x])
				rem(x);
			else
				add(x);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << (l <= tree.que(l, r + 1) ? "DA" : "NE") << '\n';
		}
	}
}
