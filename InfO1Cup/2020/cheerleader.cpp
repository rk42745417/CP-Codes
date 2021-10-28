// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using uint = uint32_t;
using ull = uint64_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const ll LINF = ll(1e18) + ll(1e15);
static auto LamyIsCute = []() {
	EmiliaMyWife
		return 48763;
}();

signed main() {
	int n;
	cin >> n;
	if(n == 0) {
		cout << "0\n";
		return 0;
	}
	auto rot = [&](int &a) {
		a = (a >> 1) | ((a & 1) << (n - 1));
	};
	vector<int> arr(1 << n);
	for(int i = 0; i < (1 << n); i++) {
		int x;
		cin >> x;
		arr[x] = i;
	}

	int a, b;
	ll mn = LINF;
	for(int i = 0; i < n; i++) {
		ll res = 0;
		int w = 0;

		vector<vector<ll>> cost(n, vector<ll>(2));
		vector<vector<int>> cnt(n, vector<int>(1 << n));
		for(int j = 0; j < (1 << n); j++) {
			for(int k = 0; k < n; k++) {
				int r = arr[j] >> k;
				cost[k][r & 1] += cnt[k][r ^ 1];
			}
			for(int k = 0; k < n; k++)
				cnt[k][arr[j] >> k]++;
		}
		for(int i = 0; i < n; i++) {
			if(cost[i][1] < cost[i][0])
				w ^= 1 << i;
			res += min(cost[i][1], cost[i][0]);
		}

		if(res < mn) {
			mn = res;
			a = i;
			b = w;
		}
		for(int &x : arr)
			rot(x);
	}
	string s(a, '2');
	for(int i = 0, w = n - 1; i < n; i++) {
		if(b >> w & 1)
			s += '1';
		s += '2';
		w = (w + 1) % n;
	}
	cout << mn << '\n' << s << '\n';
}
