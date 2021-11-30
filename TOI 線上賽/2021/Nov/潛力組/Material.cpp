// 100/100
// 00:09:00
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const ll LINF = ll(2e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 4e5 + 25;
struct fenwicktree {
	int arr[N];
	void edt(int p, int v) {
		for(; p < N; p += p & -p)
			arr[p] += v;
	}
	int que(int p) {
		int res = 0;
		for(; p; p -= p & -p)
			res += arr[p];
		return res;
	}
} bit;

signed main() {
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	int q;
	cin >> q;
	vector<tuple<int, int, int>> que(q);
	vector<int> ans(q);
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		que[i] = {r, l, i};
	}
	sort(que.begin(), que.end());
	int it = 1;
	vector<int> has(n + 1);
	for(const auto &[r, l, id] : que) {
		while(it <= r) {
			bit.edt(it, 1);
			if(has[arr[it]])
				bit.edt(has[arr[it]], -1);
			has[arr[it]] = it;
			it++;
		}
		ans[id] = bit.que(r) - bit.que(l - 1);
	}
	for(int a : ans)
		cout << a << '\n';
}
