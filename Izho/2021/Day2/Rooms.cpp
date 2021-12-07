// 40/100
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

signed main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a;
	vector<int> brr(n + 1);
	for(int &a : brr)
		cin >> a;
	bool test = 0;
	if(n > 5000 || test) {
		if(*max_element(arr.begin(), arr.end()) == 0) {
			vector<int> mx(n);
			mx[n - 1] = brr[n];
			for(int i = n - 2; ~i; i--)
				mx[i] = max(mx[i + 1], brr[i + 1]);
			for(int i = 0, m = brr[0]; i < n; i++) {
				cout << min(m, mx[i]) << " \n"[i == n - 1];
				m = max(m, brr[i + 1]);
			}
		}
		else if(*max_element(brr.begin(), brr.end()) <= 100) {
			
		}
		else {
			for(int i = 0; i < n; i++)
				cout << max<ll>(0, brr[i] - arr[i]) << " \n"[i == n - 1];
		}
		return 0;
	}
	vector<bool> vis(n);
	for(int i = 0; i < n; i++) {
		fill(vis.begin(), vis.end(), false);

		ll cur = arr[i], ans = 0;
		int l = i, r = i;
		while(0 <= l && r < n) {
			if(brr[l] < brr[r + 1]) {
				ll x = max<ll>(brr[l] - cur, 0);
				ans += x;
				cur += x;
				l--;
				if(0 <= l)
					cur += arr[l];
			}
			else {
				ll x = max<ll>(brr[r + 1] - cur, 0);
				ans += x;
				cur += x;
				r++;
				if(r < n)
					cur += arr[r];
			}
		}
		cout << ans << " \n"[i == n - 1];
	}
}
