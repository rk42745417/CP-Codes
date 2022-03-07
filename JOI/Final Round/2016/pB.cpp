// 100/100
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(0);
using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;
const int INF = 0x3f3f3f3f;
const ll LINF = ll(4e18) + ll(2e15);
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
static int LamyIsCute = []() {
	EmiliaMyWife
	return 48763;
}();

signed main() {
	int n;
	string s;
	cin >> n >> s;
	ll res = 0;
	vector<int> pre_cnt(n), suf_cnt(n);
	for(int i = 0; i < n; i++) {
		pre_cnt[i] = (s[i] == 'J');
		if(i)
			pre_cnt[i] += pre_cnt[i - 1];
	}
	for(int i = n - 1; ~i; i-- ){
		suf_cnt[i] = s[i] == 'I';
		if(i + 1 < n)
			suf_cnt[i] += suf_cnt[i + 1];
	}
	for(int i = 0; i < n; i++)
		if(s[i] == 'O')
			res += 1LL * pre_cnt[i] * suf_cnt[i];
	ll ans = res;
	for(int i = 0; i + 1 < n; i++)
		ans = max(ans, res + ll(pre_cnt[i]) * suf_cnt[i + 1]);

	ll cur = 0;
	for(int i = 0; i < n; i++)
		if(s[i] == 'O')
			cur += pre_cnt[i];
	ans = max(ans, res + cur);
	cur = 0;
	for(int i = n - 1; ~i; i--)
		if(s[i] == 'O')
			cur += suf_cnt[i];
	ans = max(ans, res + cur);

	cout << ans << '\n';
}
