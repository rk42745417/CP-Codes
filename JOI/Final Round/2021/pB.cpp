// 100/100
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("avx2")
//#pragma GCC optimize("unroll-loops")

#define EMT ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const double EPS = 1e-9;

signed main() { EMT
	int n, q;
	cin >> n >> q;
	vector<ll> arr(n), ans(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	vector<pair<ll, ll>> owo(q + 2);
	vector<ll> que(q + 2);
	ll w = 0;
	for(int i = 1; i <= q; i++) {
		cin >> que[i];
		w += que[i];
		owo[i].first = min(owo[i - 1].first, w);
		owo[i].second = max(owo[i - 1].second, w);
	}
	ans[0] += -owo[q].first;
	ans[n - 1] += owo[q].second;
	owo[q + 1].first = -1e18;
	owo[q + 1].second = 1e18;

	vector<pair<int, int>> ord;
	for(int i = 1; i < n; i++)
		ord.push_back({i - 1, i});
	sort(ord.begin(), ord.end(), [&](const auto &a, const auto &b) {
		return arr[a.second] - arr[a.first] < arr[b.second] - arr[b.first];
	});

	int it = 0;
	for(const auto &[l, r] : ord) {
		while(it <= q && owo[it].second - owo[it].first <= arr[r] - arr[l])
			it++;
		ans[r] += -owo[it - 1].first;
		ans[l] += owo[it - 1].second;
		if(que[it] > 0) {
			ans[l] += min(arr[r] + owo[it - 1].first - (arr[l] + owo[it - 1].second), que[it]);
		}
		else {
			ans[r] += min(arr[r] + owo[it - 1].first - (arr[l] + owo[it - 1].second), -que[it]);
		}
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}
/*
10 10
-56 -43 -39 -31 -22 -5 0 12 18 22
-3
0
5
-4
-2
10
-13
-1
9
6

*/
