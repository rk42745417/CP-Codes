// 88/100
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
const ll LINF = 4e18;

const int N = 2e5 + 25;
struct fenwicktree {
	ll arr[N];
	void edt(int p, int v) {
		for(; p < N; p += p & -p)
			arr[p] += v;
	}
	ll que(int l, int r) {
		ll res = 0;
		for(; r; r -= r & -r)
			res += arr[r];
		for(l--; l; l -= l & -l)
			res -= arr[l];
		return res;
	}
} bit;

int x, y;
int right_most[N << 2], right_most_duplicated[N << 2], arr[N];
vector<int> xdd[N << 2], lst[N << 2], has[N << 2];

void build(int id) {
	if(xdd[id].size() == 1)
		return;

	has[id].reserve(xdd[id].size());
	for(int a : xdd[id])
		has[id].push_back(arr[a]);

	sort(has[id].begin(), has[id].end());
	has[id].erase(unique(has[id].begin(), has[id].end()), has[id].end());
	lst[id].resize(has[id].size());

	xdd[id << 1].reserve((xdd[id].size() + 1) / 2);
	xdd[id << 1 | 1].reserve(xdd[id].size() / 2);
	for(int i = 0; i < xdd[id].size(); i++) {
		if(i & 1)
			xdd[id << 1 | 1].push_back(xdd[id][i]);
		else
			xdd[id << 1].push_back(xdd[id][i]);
	}
	build(id << 1);
	build(id << 1 | 1);
}
void insert(int id, int p, int v, int cur) {
	if(xdd[id].size() == 1) {
		bit.edt(p, x);
		right_most[id] = p;
		return;
	}
	int a = right_most_duplicated[id];
	if(right_most[id << 1 | 1])
		bit.edt(min(right_most[id << 1], right_most[id << 1 | 1]), x);

	if(cur & 1) 
		insert(id << 1, p, v, (cur + 1) / 2);
	else 
		insert(id << 1 | 1, p, v, cur / 2);
	auto it = lower_bound(has[id].begin(), has[id].end(), v) - has[id].begin();
	if(lst[id][it]) 
		right_most_duplicated[id] = max(right_most_duplicated[id], lst[id][it]);
	lst[id][it] = p;

	right_most[id] = p;

	if(right_most[id << 1 | 1])
		bit.edt(min(right_most[id << 1], right_most[id << 1 | 1]), -x);
	if(right_most_duplicated[id] && a != right_most_duplicated[id]) {
		bit.edt(right_most_duplicated[id], x + y);
		if(a)
			bit.edt(a, -(x + y));
	}
}
signed main() { EmiliaMyWife
	int n;
	cin >> n >> x >> y;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];

	xdd[1].reserve(n);
	for(int i = 0; i < n; i++)
		xdd[1].push_back(i + 1);
	build(1);
	
	int q;
	cin >> q;
	vector<tuple<int, int, int>> que(q);
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		que[i] = {r, l, i};
	}
	sort(que.begin(), que.end());
	int it = 0;
	vector<ll> ans(q);
	for(const auto &[r, l, id] : que) {
		while(it < r) {
			++it;
			insert(1, it, arr[it], it);
		}
		ans[id] = bit.que(l, r);
	}
	for(const auto &a : ans)
		cout << a << '\n';
}
