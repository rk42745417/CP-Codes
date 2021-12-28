// 21/100 (subtask 1,2)
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(2e18) + ll(1e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = 0;
	for(int i = 0; i < n; i++) {
		set<int> has, rip;
		for(int j = i; j < n; j++) {
			int x = arr[j];
			if(!rip.count(x)) {
				if(has.count(x))
					has.erase(x), rip.insert(x);
				else
					has.insert(x);
			}
			if(l <= has.size() && has.size() <= r)
				ans++;
		}
	}
	cout << ans << '\n';
}
