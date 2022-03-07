// 100/100
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
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 2e5 + 25;
struct fenwicktree {
	ll arr[N];
	void edt(int p, ll v) {
		for(; p < N; p += p & -p)
			arr[p] += v;
	}
	ll que(int p) {
		ll res = 0;
		for(; p; p -= p & -p)
			res += arr[p];
		return res;
	}
	int fnd(ll k) {
		int p = 0;
		ll res = 0;
		for(int i = 1 << 19; i; i >>= 1)
			if(p + i < N && res + arr[p + i] < k)
				res += arr[p |= i];
		return p + 1;
	}
} x, y;

signed main() {
	int n, q;
	cin >> n >> q;
	vector<tuple<int, int, int>> que(q);
	for(auto &[x, d, l] : que)
		cin >> x >> d >> l;

	reverse(que.begin(), que.end());

	for(int i = 1; i <= n; i++)
		x.edt(i, 1), y.edt(i, 1);
	x.edt(n + 1, LINF);
	y.edt(n + 1, LINF);

	for(const auto &[s, d, l] : que) {
		if(d == 1) {
			int it = x.fnd(s + 1);
			y.edt(1, -l * 2);
			y.edt(it, l * 2);
		}
		else {
			int it = y.fnd(s + 1);
			x.edt(it, l * 2);
		}
	}
	for(int i = 1; i <= n; i++)
		cout << (x.que(i) - y.que(i)) / 2 << '\n';
}
