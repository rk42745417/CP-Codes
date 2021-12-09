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
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 1e6 + 25;
struct segtree {
	int arr[N << 1], tag[N], n;
	void init(int _n) { n = _n; }
	void upd(int p, int v) {
		arr[p] = max(arr[p], v);
		if(p < n)
			tag[p] = max(tag[p], v);
	}
	void push(int p) {
		for(int h = __lg(p); ~h; h--) {
			int i = p >> h;
			if(tag[i >> 1]) {
				upd(i, tag[i >> 1]);
				upd(i ^ 1, tag[i >> 1]);
				tag[i >> 1] = 0;
			}
		}
	}
	void edt(int l, int r, int v) {
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				upd(l++, v);
			if(r & 1)
				upd(--r, v);
		}
	}
	int que(int p) {
		push(p += n);
		return arr[p];
	}
} tree;
signed main() {
	int n;
	cin >> n;
	vector<int> arr(n), brr(n + 1);
	vector<ll> sum(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum[i] = arr[i];
		if(i)
			sum[i] += sum[i - 1];
	}
	for(int i = 0; i <= n; i++)
		cin >> brr[i];
	auto cost = [&](int l, int r) {
		return max<ll>(0, min(brr[l], brr[r + 1]) - sum[r] + (l ? sum[l - 1] : 0));
	};

	tree.init(n);
	stack<int> owo;
	owo.push(0);
	for(int i = 0; i < n; i++) {
		int x = brr[i + 1];
		while(!owo.empty() && brr[owo.top()] < x) {
			tree.edt(owo.top(), i + 1, cost(owo.top(), i));
			owo.pop();
		}
		if(!owo.empty())
			tree.edt(owo.top(), i + 1, cost(owo.top(), i));
		owo.push(i + 1);
	}
	for(int i = 0; i < n; i++)
		cout << tree.que(i) << " \n"[i == n - 1];
}
