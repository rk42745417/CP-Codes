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
const double EPS = 1e-9;
const ll LINF = ll(4e18) + ll(2e15);
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

const int SQN = 450, N = 2e5 + 25;
int arr[N];

int prv[N], nxt[N]; // for linked list
ll dp[SQN][SQN];
int fst[SQN][SQN], lst[SQN][SQN];
vector<int> v;

vector<pair<int, int>> qls, qrs;
int ql[N], qr[N];
int last_act[N];
ll ans[N];

void calc(int l, int r) {
	v.clear();
	memset(dp, -1, sizeof dp);
	memset(fst, 0, sizeof fst);
	memset(lst, 0, sizeof lst);

	for(int i = l; i < r; i++)
		v.push_back(arr[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	vector<vector<int>> pos(v.size());
	for(int i = l; i < r; i++)
		pos[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()].push_back(i);

	for(int j = 0; j < v.size(); j++) {
		ll res = 0;
		int head = -1, tail = -1;
		for(int i = l, owo = -1; i < r; i++) {
			if(v[j] < arr[i])
				continue;
			nxt[i] = -1;
			prv[i] = owo;
			if(~owo) {
				res += abs(arr[owo] - arr[i]);
				nxt[owo] = i;
			}
			owo = i;

			if(head == -1)
				head = i;
			tail = i;
		}
		dp[0][j] = res;
		lst[0][j] = tail;
		fst[0][j] = head;

		for(int i = 0; i < j; i++) {
			for(int p : pos[i]) {
				if(~nxt[p])
					res -= abs(arr[p] - arr[nxt[p]]), prv[nxt[p]] = prv[p];
				if(~prv[p])
					res -= abs(arr[p] - arr[prv[p]]), nxt[prv[p]] = nxt[p];
				if(~nxt[p] && ~prv[p])
					res += abs(arr[prv[p]] - arr[nxt[p]]);

				if(head == p)
					head = nxt[p];
				if(tail == p)
					tail = prv[p];
			}

			dp[i + 1][j] = res;
			lst[i + 1][j] = tail;
			fst[i + 1][j] = head;
		}
	}
}
void get_ans(const int q) {
	int it = 0;
	for(const auto &[x, i] : qls) {
		while(it < v.size() && v[it] < x)
			it++;
		ql[i] = it;
	}
	it = 0;
	for(const auto &[x, i] : qrs) {
		while(it < v.size() && v[it] <= x)
			it++;
		qr[i] = it - 1;
	}
	for(int i = 0; i < q; i++) {
		int a = ql[i], b = qr[i];
		if(a > b || dp[a][b] == -1)
			continue;
		ans[i] += dp[a][b];
		if(~last_act[i])
			ans[i] += abs(arr[last_act[i]] - arr[fst[a][b]]);
		last_act[i] = lst[a][b];
	}
}

signed main() {
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		qls.push_back({l, i});
		qrs.push_back({r, i});
		last_act[i] = -1;
	}
	sort(qls.begin(), qls.end());
	sort(qrs.begin(), qrs.end());

	for(int l = 0, r = min(n, SQN); l < n; l = r, r = min(r + SQN, n)) {
		calc(l, r);
		get_ans(q);
	}

	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}
