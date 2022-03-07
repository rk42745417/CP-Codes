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

const int N = 2e5 + 25;
struct segtree {
	ll arr[N << 1], tag[N];
	int n;
	void init(int _n) { n = _n; }
	void upd(int p, ll v, int h) {
		arr[p] += v * (1LL << h);
		if(p < n)
			tag[p] += v;
	}
	void push(int p) {
		for(int h = __lg(p); ~h; h--) {
			int i = p >> h;
			upd(i, tag[i >> 1], h);
			upd(i ^ 1, tag[i >> 1], h);
			tag[i >> 1] = 0;
		}
	}
	void pull(int p) {
		for(int h = 1; p > 1; p >>= 1, h++)
			arr[p >> 1] = arr[p] + arr[p ^ 1] + tag[p >> 1] * (1LL << h);
	}
	void edt(int l, int r, int v) {
		if(l >= r)
			return;
		int tl = l + n, tr = r + n - 1, h = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1, h++) {
			if(l & 1)
				upd(l++, v, h);
			if(r & 1)
				upd(--r, v, h);
		}
		pull(tl);
		pull(tr);
	}
	ll que(int l, int r) {
		if(l >= r)
			return 0;
		push(l + n);
		push(r + n - 1);
		ll res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1)
				res += arr[l++];
			if(r & 1)
				res += arr[--r];
		}
		return res;
	}
} tree, tree2;

signed main() {
	int n, q;
	cin >> n >> q;
	tree.init(n);
	tree2.init(n);
	vector<int> arr(n), prv(n), nxt(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	{
		stack<int, vector<int>> st;
		for(int i = 0; i < n; i++) {
			while(!st.empty() && arr[st.top()] < arr[i]) {
				nxt[st.top()] = i;
				st.pop();
			}
			if(!st.empty())
				prv[i] = st.top();
			else
				prv[i] = -1;
			st.push(i);
		}
		while(!st.empty()) {
			nxt[st.top()] = n;
			st.pop();
		}
	}

	vector<vector<tuple<int, int, int>>> mods(n + 1), mods2(n + 1);
	auto add_triangle = [&](int l, int r, ll v) { // [l, r]
		mods[0].push_back({r + 1, n, -v});
		int tot = r - l + 1;
		if(tot <= n)
			mods[tot].push_back({r + 1, n, v});

		mods2[0].push_back({l, n, v});
		if(tot <= n)
			mods2[tot].push_back({l, n, -v});
	};

	for(int i = 0; i < n; i++) {
		if(~prv[i]) {
			add_triangle(prv[i] + 1, nxt[i] - 1, arr[i]);
			if(prv[i] + 1 < i)
				add_triangle(prv[i] + 1, i - 1, -arr[i]);
			if(i + 1 < nxt[i])
				add_triangle(i + 1, nxt[i] - 1, -arr[i]);
		}
		else {
			mods[0].push_back({i, nxt[i], arr[i]});
			if(i + 1 < nxt[i])
				add_triangle(i + 1, nxt[i] - 1, -arr[i]);
		}
	}

	vector<ll> ans(q);
	vector<vector<tuple<int, int, int>>> ques(n + 1);
	for(int i = 0; i < q; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		ques[t].push_back({l - 1, r, i});
	}

	for(int i = 0; i <= n; i++) {
		for(const auto &[l, r, v] : mods[i])
			tree.edt(l, r, v);
		for(const auto &[l, r, v] : mods2[i])
			tree2.edt(l, r, v);
		for(const auto &[l, r, id] : ques[i]) {
			ans[id] = tree.que(l, r);
			ans[id] += tree2.que(max(0, l - i), max(0, r - i));
		}
	}
	
	for(ll a : ans)
		cout << a << '\n';
}
