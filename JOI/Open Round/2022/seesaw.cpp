// 34/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 4e18;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	cin >> n;
	assert(n <= 200);
	vector<int> arr(n);
	for(int &a : arr)
		cin >> a;
	vector<ld> cen;
	for(int i = 0; i < n; i++) {
		ll s = 0;
		for(int j = i; j < n; j++) {
			s += arr[j];
			cen.push_back(ld(s) / (j - i + 1));
		}
	}
	sort(cen.begin(), cen.end());

	ll s = accumulate(arr.begin(), arr.end(), 0LL);
	auto test = [&](int l, int r) {
		int a = 0, b = n - 1;
		ll res = s;
		ld cur = ld(res) / (b - a + 1);
		if((cur > cen[r] && abs(cur - cen[r]) > EPS) || (cur < cen[l] && abs(cur - cen[l]) > EPS))
			return false;
		while(a < b) {
			res -= arr[a];
			cur = ld(res) / (b - a);
			if((cur < cen[r] || abs(cur - cen[r]) < EPS) && (cur > cen[l] || abs(cur - cen[l]) < EPS)) {
				a++;
				continue;
			}
			res -= arr[b] - arr[a];
			cur = ld(res) / (b - a);
			if((cur < cen[r] || abs(cur - cen[r]) < EPS) && (cur > cen[l] || abs(cur - cen[l]) < EPS)) {
				b--;
				continue;
			}
			return false;
		}
		return true;
	};
	
	ld ans = 1e18;
	for(int r = 1, l = 0; r < cen.size(); r++) {
		while(test(l + 1, r))
			l++;
		if(test(l, r))
			ans = min(ans, cen[r] - cen[l]);
	}
	cout << fixed << setprecision(15) << ans << '\n';
}
