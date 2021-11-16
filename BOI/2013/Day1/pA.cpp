// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
static auto LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int N = 1e5 + 25, LGN = 19;
vector<int> edge[N]; // edge sorted by choosing priority
set<int> can[N]; // can choose
int rt;
int mn[N]; // minimum number in subtree
int dep[N], sz[N], head[N], heavy[N], id[N]; // HLD
int anc[LGN][N]; // Binary lifting
bool has[N]; // Has ball

struct segtree {
	int arr[N << 1], tag[N], n;
	void init(int _n) {
		n = _n;
		memset(tag, -1, sizeof tag);
	}
	void upd(int p, int v) {
		arr[p] = v;
		if(p < n)
			tag[p] = v;
	}
	void push(int p) {
		for(int h = __lg(p); ~h; h--) {
			int i = p >> h;
			if(~tag[i >> 1]) {
				upd(i, tag[i >> 1]);
				upd(i ^ 1, tag[i >> 1]);
				tag[i >> 1] = -1;
			}
		}
	}
	void edt(int l, int r, int v) {
		int tl = l + n, tr = r + n - 1;
		push(tl);
		push(tr);
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

void build(int u) {
	mn[u] = u;
	sz[u] = 1;
	heavy[u] = -1;
	for(int v : edge[u]) {
		dep[v] = dep[u] + 1;
		anc[0][v] = u;
		build(v);

		mn[u] = min(mn[u], mn[v]);
		sz[u] += sz[v];

		if(heavy[u] == -1 || sz[v] > sz[heavy[u]])
			heavy[u] = v;
	}

	sort(edge[u].begin(), edge[u].end(), [&](int a, int b) { return mn[a] < mn[b]; });
	for(int i = 0; i < edge[u].size(); i++)
		can[u].insert(i);
}
int t = 0;
void build_hld(int u, int h) {
	id[u] = t++;
	head[u] = h;
	if(~heavy[u])
		build_hld(heavy[u], h);
	for(int v : edge[u]) {
		if(v != heavy[u]) {
			build_hld(v, v);
		}
	}
}
int init(int u) {
	int x = u;
	for(int v : edge[u]) {
		if(x == u)
			x = init(v);
		else
			init(v);
	}
	tree.edt(id[u], id[u] + 1, x);
	return x;
}
void edt(int a, int b, int v) {
	for(; head[a] != head[b]; a = anc[0][head[a]]) {
		if(dep[head[a]] < dep[head[b]])
			swap(a, b);
		tree.edt(id[head[a]], id[a] + 1, v);
	}
	if(dep[a] < dep[b])
		swap(a, b);
	tree.edt(id[b], id[a] + 1, v);
}
inline int get_next_link(int p) {
	if(can[p].empty())
		return p;
	return tree.que(id[edge[p][*can[p].begin()]]);
}
int add_ball() {
	int g = tree.que(id[rt]);
	has[g] = true;
	if(g == rt)
		return g;
	int p = anc[0][g];
	can[p].erase(lower_bound(edge[p].begin(), edge[p].end(), g, [&](int a, int b) { return mn[a] < mn[b]; }) - edge[p].begin());

	int nw = get_next_link(p);
	edt(rt, p, nw);

	return g;
}
void remove_ball(int g) {
	has[g] = false;
	if(g == rt)
		return;

	int p = anc[0][g];
	can[p].insert(lower_bound(edge[p].begin(), edge[p].end(), g, [&](int a, int b) { return mn[a] < mn[b]; }) - edge[p].begin());
	int r = tree.que(id[p]);
	int x = p;
	for(int i = LGN - 1; ~i; i--) {
		if(anc[i][x] && tree.que(id[anc[i][x]]) == r)
			x = anc[i][x];
	}

	int nw = get_next_link(p);
	edt(x, p, nw);
}

signed main() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if(x == 0)
			rt = i;
		else
			edge[x].push_back(i);
	}

	dep[rt] = 1;
	build(rt);
	build_hld(rt, rt);
	tree.init(n);
	init(rt);
	for(int i = 1; i < LGN; i++)
		for(int j = 1; j <= n; j++)
			anc[i][j] = anc[i - 1][anc[i - 1][j]];

	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int k;
			cin >> k;
			for(int i = 1; i <= k; i++) {
				int x = add_ball();
				if(i == k)
					cout << x << '\n';
			}
		}
		else {
			int p;
			cin >> p;

			int x = p;
			for(int i = LGN - 1; ~i; i--) {
				if(anc[i][x] && has[anc[i][x]])
					x = anc[i][x];
			}
			cout << dep[p] - dep[x] << '\n';
			remove_ball(x);
		}
	}
}
